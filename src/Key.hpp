#pragma once 

#include "bitcrypto/Secret.hpp"
#include "bitcrypto/SecuredSecret.hpp"
#include "bitcrypto/PubKey.hpp"


namespace Stealth{


using namespace BitCrypto;


template<class Cipher>
class Key
{
    public:
        typedef SecuredSecret<Cipher> SpendSecret;
        typedef Secret ScanSecret;

        typedef std::vector<PubKey> PubKeyCollection;
        typedef std::vector<SpendSecret> SpendSecretCollection;

    public:

        Key
        (
            const ScanSecret &scanKey, 
            const PubKey &scanPub, 
            const SpendSecretCollection &spendKeys, 
            const PubKeyCollection &spendPub
        );

        Key
        (
            const ScanSecret &scanKey,
            const PubKey &scanPub,
            const SpendSecret &spendKey,
            const PubKey &spendPub
        );

        const PubKey & getScanPubKey() const;
        const PubKeyCollection & getSpendPubKeys() const;
        const Secret & getScanKey() const;

        const SpendSecretCollection & getSpendKeys() const;


    private:
        ScanSecret  _scanKey;
        PubKey  _scanPub;
        SpendSecretCollection _spendKeys;
        PubKeyCollection  _spendPub;
};


}

#include "Key.ipp"
