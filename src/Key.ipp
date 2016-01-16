namespace Stealth{


template<class Cipher>
Key<Cipher>::Key(const ScanSecret &scanKey,  const PubKey &scanPub, const SpendSecretCollection &spendKeys, const PubKeyCollection &spendPub) :
    _scanKey(scanKey),
    _scanPub(scanPub),
    _spendKeys(spendKeys),
    _spendPub(spendPub)
{}


template<class Cipher>
Key<Cipher>::Key(const ScanSecret &scanKey, const PubKey &scanPub, const SpendSecret &spendKey, const PubKey &spendPub) :
    _scanKey(scanKey),
    _scanPub(scanPub)
{
    _spendKeys.push_back(spendKey);
    _spendPub.push_back(spendPub);
}


template<class Cipher>
const PubKey & Key<Cipher>::getScanPubKey() const
{
    return _scanPub;
}


template<class Cipher>
const typename Key<Cipher>::PubKeyCollection & Key<Cipher>::getSpendPubKeys() const
{
    return _spendPub;
}


template<class Cipher>
const Secret & Key<Cipher>::getScanKey() const
{
    return _scanKey;
}


template<class Cipher>
const typename Key<Cipher>::SpendSecretCollection & Key<Cipher>::getSpendKeys() const
{
    return _spendPub;
}


}
