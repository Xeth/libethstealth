namespace Ethereum{ namespace Stealth{


template<class Cipher>
Key<Cipher>::Key()
{}

template<class Cipher>
Key<Cipher>::Key(const ScanSecret &scanKey,  const PublicKey &scanPub, const SpendSecretCollection &spendKeys, const PublicKeyCollection &spendPub) :
    _scanKey(scanKey),
    _scanPub(scanPub),
    _spendKeys(spendKeys),
    _spendPub(spendPub)
{}


template<class Cipher>
Key<Cipher>::Key(const ScanSecret &scanKey, const PublicKey &scanPub, const SpendSecret &spendKey, const PublicKey &spendPub) :
    _scanKey(scanKey),
    _scanPub(scanPub)
{
    _spendKeys.push_back(spendKey);
    _spendPub.push_back(spendPub);
}


template<class Cipher>
Key<Cipher> & Key<Cipher>::operator = (const Key<Cipher> &copy)
{
    _scanKey = copy._scanKey;
    _scanPub = copy._scanPub;
    _spendKeys = copy._spendKeys;
    _spendPub = copy._spendPub;
    return *this;
}

template<class Cipher>
const PublicKey & Key<Cipher>::getScanPublicKey() const
{
    return _scanPub;
}


template<class Cipher>
const typename Key<Cipher>::PublicKeyCollection & Key<Cipher>::getSpendPublicKeys() const
{
    return _spendPub;
}


template<class Cipher>
const typename Key<Cipher>::ScanSecret & Key<Cipher>::getScanPrivateKey() const
{
    return _scanKey;
}


template<class Cipher>
const typename Key<Cipher>::SpendSecretCollection & Key<Cipher>::getSpendPrivateKeys() const
{
    return _spendKeys;
}


}}
