#pragma once 

#include "ethkey/PrivateKey.hpp"
#include "ethkey/SecuredPrivateKey.hpp"
#include "ethkey/PublicKey.hpp"


namespace Ethereum{namespace Stealth{


using Ethereum::PublicKey;
using Ethereum::PrivateKey;
using Ethereum::SecuredPrivateKey;


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


}}

#include "Key.ipp"
