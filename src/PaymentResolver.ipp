
namespace Ethereum{namespace Stealth{


template<class Key>
PaymentResolver<Key>::PaymentResolver(const Key &key) : 
    _key(key)
{}


template<class Key>
bool PaymentResolver<Key>::uncover(const Ethereum::Address &address, const PublicKey &ephem, SharedSecret &secret)
{
    return uncover(address, ephem, secret, 0);
}



template<class Key>
bool PaymentResolver<Key>::uncover(const Ethereum::Address &address, const PublicKey &ephem, SharedSecret &secret, size_t spendIndex)
{
    const std::vector<PublicKey> &spends = _key.getSpendPublicKeys();
    if(spendIndex >= spends.size())
    {
        return false;
    }

    secret = _secretFactory.createFromScanSecret(_key.getScanPrivateKey(), ephem);
    PublicKey secretPub = _pubkeyFactory.createFromSecret(secret);

    if(address == Ethereum::Address(spends[spendIndex] + secretPub))
    {
        return true;
    }
    return false;
}



}}
