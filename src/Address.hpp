#pragma once 

#include <stdint.h>

#include "bitcrypto/Data.hpp"
#include "bitcrypto/PublicKey.hpp"
#include "Key.hpp"



namespace Stealth{


using BitCrypto::Data;
using BitCrypto::PublicKey;

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
            uint8_t options = 0,
            uint8_t version=DEFAULT_VERSION
        );

        Address
        (
            const PublicKey &scanKey, 
            const std::vector<PublicKey> &spendKeys,  
            size_t signatures = 0, 
            const Data &prefix=Data(),
            uint8_t options = 0,
            uint8_t version = DEFAULT_VERSION
        );

        Address
        (
            const PublicKey &scanKey,
            const PublicKey &spendKey,
            const Data &prefix=Data(),
            uint8_t options = 0,
            uint8_t version = DEFAULT_VERSION
        );

        Address(const PublicKey &scanKey, const PublicKey &spendKey, uint8_t version = DEFAULT_VERSION);

        uint8_t getVersion() const;
        uint8_t getOptions() const;
        const Data & getPrefix() const;
        size_t getRequiredSignatures() const;

        const PublicKey & getScanKey() const;
        const std::vector<PublicKey> & getSpendKeys() const;

    private:
        PublicKey _scanKey;
        std::vector<PublicKey> _spendKeys;
        uint8_t _version;
        size_t _signatures;
        uint8_t _options;
        Data _prefix;
};


}

#include "Address.ipp"
