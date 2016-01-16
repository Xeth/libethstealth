
namespace Stealth{


template<class Encoder>
std::string GenericAddressEncoder<Encoder>::encode(const Address &address) const
{
    size_t dataSize = 42;
    const std::vector<PubKey> & spendKeys = address.getSpendKeys();
    const PubKey & scanKey = address.getScanKey();
    const Data &prefix = address.getPrefix();

    for(std::vector<PubKey>::const_iterator it = spendKeys.begin(), end = spendKeys.end();  it != end; ++it)
    {
        dataSize += 33;
    }
    
    dataSize += prefix.size();
 
    Data data;

    data.resize(dataSize);

    Data::iterator it = data.begin();

    *it = address.getVersion();
    ++it;

    *it = address.getOptions();
    ++it;
    

    CompressedPoint point;
    BinaryPubKeySerializer serializer;

    serializer.serialize(scanKey, point);

    std::copy(point.begin(), point.end(), it);

    it += 33;

    *it = static_cast<uint8_t>(spendKeys.size());
    ++it;

    for(int i=0; i<spendKeys.size(); i++)
    {
        const PubKey & spendKey = spendKeys[i];
        serializer.serialize(spendKey, point);

        std::copy(point.begin(), point.end(), it);
        it += 33;
    }

    *it = static_cast<uint8_t>(address.getRequiredSignatures());
    ++it;

    *it = static_cast<uint8_t>(prefix.size());
    ++it;
    if(prefix.size())
    {
        std::copy(prefix.begin(), prefix.end(), it);
        it += prefix.size();
    }
    DoubleSha256CheckSum checksum;
    uint32_t checksumResult = checksum(data.begin(), it);
    uint8_t *checksumPtr = (unsigned char *)&checksumResult;
    std::copy(checksumPtr, checksumPtr+4, it);

    Encoder encoder;
    return encoder.encode(data.begin(), data.end());
}


template<class Encoder>
Address GenericAddressEncoder<Encoder>::decode(const std::string &address) const
{
    Encoder encoder;
    Data data = encoder.decode(address.begin(), address.end());

    size_t dataSize = data.size();

    if(dataSize < 71)
    {
        throw std::runtime_error("invalid stealth address");
    }

    BinaryPubKeySerializer serializer;
    std::vector<PubKey> spendKeys;
    Data prefix;

    uint8_t signatures, version, options, prefixSize, spendKeysCount;
    Data::iterator it = data.begin();

    version = *it;
    ++it;

    options = *it;
    ++it;


    PubKey scanKey = serializer.unserialize(it, it+33);
    it += 33;

    spendKeysCount = *it;
    size_t spendKeysDataSize = spendKeysCount * 33;

    if(dataSize < 38 + spendKeysDataSize)
    {
        throw std::runtime_error("invalid stealth address");
    }
    
    ++it;

    spendKeys.resize(spendKeysCount);

    for(int i=0; i<spendKeysCount; i++)
    {
        spendKeys[i] = serializer.unserialize(it, it+33);
        it += 33;
    }

    signatures = *it;
    ++it;

    prefixSize = *it;
    ++it;


    if(dataSize < 38 + spendKeysDataSize + prefixSize)
    {
        throw std::runtime_error("invalid stealth address");
    }

    if(prefixSize)
    {
        prefix.resize(prefixSize);
        std::copy(it, it+prefixSize, prefix.begin());
        it += prefixSize;
    }

    if(data.end()-it != 4)
    {
        throw std::runtime_error("invalid checksum");
    }

    uint32_t check = *((uint32_t *)&*it);
    DoubleSha256CheckSum checksum;
    if(checksum(data.begin(), it)!=check)
    {
        throw std::runtime_error("invalid checksum");
    }

    return Address(scanKey, spendKeys, signatures, prefix, options, version);
}


}
