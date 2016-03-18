#pragma once 

#include "ethkey/key/PrivateKey.hpp"
#include "ethkey/key/SecuredPrivateKey.hpp"
#include "ethkey/key/PublicKey.hpp"


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

        Key();
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

        Key & operator = (const Key &);
        bool operator == (const Key &) const;

    private:
        ScanSecret  _scanKey;
        PublicKey  _scanPub;
        SpendSecretCollection _spendKeys;
        PublicKeyCollection  _spendPub;
};


}}

#include "Key.ipp"
