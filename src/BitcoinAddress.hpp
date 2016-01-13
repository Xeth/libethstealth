#pragma once

#include "Address.hpp"


namespace Stealth{


class BitcoinAddress : public Address
{
    public:
        enum Type
        {
            Main_Net = 0x2a,
            Test_Net = 0x2b
        };

    public:
        BitcoinAddress
        (
            Type type,
            const PubKey &scanKey, 
            const std::vector<PubKey> &spendKeys, 
            const Data &prefix=Data(), 
            size_t signatures = 0, 
            uint8_t options = 0
        );

        BitcoinAddress
        (
            Type type,
            const PubKey &scanKey,
            const PubKey &spendKey,
            const Data &prefix=Data(),
            uint8_t options = 0
        );

        BitcoinAddress
        (
            const PubKey &scanKey, 
            const std::vector<PubKey> &spendKeys, 
            const Data &prefix=Data(), 
            size_t signatures = 0, 
            uint8_t options = 0
        );

        BitcoinAddress
        (
            const PubKey &scanKey,
            const PubKey &spendKey,
            const Data &prefix=Data(),
            uint8_t options = 0
        );

        BitcoinAddress(const Address &);

};


}
