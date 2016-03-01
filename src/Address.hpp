#pragma once 

#include "ethkey/Data.hpp"
#include "ethkey/PublicKey.hpp"
#include "Key.hpp"



namespace Ethereum {namespace Stealth{


using Ethereum::Data;
using Ethereum::PublicKey;

#define DEFAULT_VERSION 0x80


class Address
{
    public:

        template<class Cipher>
        Address
        (
            const Key<Cipher> &, 
            size_t signatures = 0,
            const Data &prefix=Data(),
            unsigned char options = 0,
            unsigned char version=DEFAULT_VERSION
        );

        Address
        (
            const PublicKey &scanKey, 
            const std::vector<PublicKey> &spendKeys,  
            size_t signatures = 0, 
            const Data &prefix=Data(),
            unsigned char options = 0,
            unsigned char version = DEFAULT_VERSION
        );

        Address
        (
            const PublicKey &scanKey,
            const PublicKey &spendKey,
            const Data &prefix=Data(),
            unsigned char options = 0,
            unsigned char version = DEFAULT_VERSION
        );

        Address(const PublicKey &scanKey, const PublicKey &spendKey, unsigned char version = DEFAULT_VERSION);

        unsigned char getVersion() const;
        unsigned char getOptions() const;
        const Data & getPrefix() const;
        size_t getRequiredSignatures() const;

        const PublicKey & getScanKey() const;
        const std::vector<PublicKey> & getSpendKeys() const;

        std::string toString() const;
        static Address FromString(const std::string &);

    private:
        PublicKey _scanKey;
        std::vector<PublicKey> _spendKeys;
        unsigned char _version;
        size_t _signatures;
        unsigned char _options;
        Data _prefix;
};


}}

#include "Address.ipp"
