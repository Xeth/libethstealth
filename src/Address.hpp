#pragma once 

#include <stdint.h>

#include "bitcrypto/Data.hpp"
#include "bitcrypto/PubKey.hpp"
//#include "Key.hpp"



namespace Stealth{


using BitCrypto::Data;
using BitCrypto::PubKey;



class Address
{
    public:

//        Address
//        (
//            const Key &, 
//            const Data &prefix=Data(),
//            size_t signatures = 0, 
//            uint8_t options = 0,
//            uint8_t version=DEFAULT_VERSION
//        );

        Address
        (
            uint8_t version,
            const PubKey &scanKey, 
            const std::vector<PubKey> &scanKeys, 
            const Data &prefix=Data(), 
            size_t signatures = 0, 
            uint8_t options = 0
        );

        Address
        (
            uint8_t version,
            const PubKey &scanKey,
            const PubKey &spendKey,
            const Data &prefix=Data(),
            uint8_t options = 0
        );

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
