#pragma once 

#include <stdint.h>

#include "bitcrypto/Data.hpp"
#include "bitcrypto/PubKey.hpp"
#include "Key.hpp"



namespace Stealth{


using BitCrypto::Data;
using BitCrypto::PubKey;

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
            const PubKey &scanKey, 
            const std::vector<PubKey> &spendKeys,  
            size_t signatures = 0, 
            const Data &prefix=Data(),
            uint8_t options = 0,
            uint8_t version = DEFAULT_VERSION
        );

        Address
        (
            const PubKey &scanKey,
            const PubKey &spendKey,
            const Data &prefix=Data(),
            uint8_t options = 0,
            uint8_t version = DEFAULT_VERSION
        );

        Address(const PubKey &scanKey, const PubKey &spendKey, uint8_t version = DEFAULT_VERSION);

        uint8_t getVersion() const;
        uint8_t getOptions() const;
        const Data & getPrefix() const;
        size_t getRequiredSignatures() const;

        const PubKey & getScanKey() const;
        const std::vector<PubKey> & getSpendKeys() const;

    private:
        PubKey _scanKey;
        std::vector<PubKey> _spendKeys;
        uint8_t _version;
        size_t _signatures;
        uint8_t _options;
        Data _prefix;
};


}

#include "Address.ipp"
