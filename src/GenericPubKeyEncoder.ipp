
namespace Stealth{


template<class Encoder>
PubKey GenericPubKeyEncoder<Encoder>::decode(const std::string &data) const
{
    Encoder encoder;
    Data bin = encoder.decode(data.begin(), data.end());

    if(bin.size()!=33)
    {
        throw std::runtime_error("invalid public key");
    }

    return PubKey(bin);
}


template<class Encoder>
std::string GenericPubKeyEncoder<Encoder>::encode(const PubKey &key) const
{
    Encoder encoder;
    return encoder.encode(key.begin(), key.end());
}


}
