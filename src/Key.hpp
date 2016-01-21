#pragma once 

#include "bitcrypto/PrivateKey.hpp"
#include "bitcrypto/SecuredPrivateKey.hpp"
#include "bitcrypto/PublicKey.hpp"


namespace Stealth{


using BitCrypto::PublicKey;
using BitCrypto::PrivateKey;
using BitCrypto::SecuredPrivateKey;


template<class Cipher>
class Key
{
    public:
        typedef SecuredPrivateKey<Cipher> SpendSecret;
        typedef PrivateKey ScanSecret;

        typedef std::vector<PublicKey> PublicKeyCollection;
        typedef std::vector<SpendSecret> SpendSecretCollection;

    public:

        Key
        (
            const ScanSecret &scanKey, 
            const PublicKey &scanPub, 
            const SpendSecretCollection &spendKeys, 
            const PublicKeyCollection &spendPub
        );

        Key
        (
            const ScanSecret &scanKey,
            const PublicKey &scanPub,
            const SpendSecret &spendKey,
            const PublicKey &spendPub
        );

        const PublicKey & getScanPublicKey() const;
        const PublicKeyCollection & getSpendPublicKeys() const;
        const ScanSecret & getScanPrivateKey() const;

        const SpendSecretCollection & getSpendPrivateKeys() const;


    private:
        ScanSecret  _scanKey;
        PublicKey  _scanPub;
        SpendSecretCollection _spendKeys;
        PublicKeyCollection  _spendPub;
};


}

#include "Key.ipp"
