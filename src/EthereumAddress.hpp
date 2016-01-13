#pragma once 

#include "Address.hpp"


namespace Stealth{


#define ETHEREUM_ADDRESS_VERSION 0x80


class EthereumAddress : public Address
{

    public:
        EthereumAddress
        (
            const PubKey &scanKey, 
            const std::vector<PubKey> &spendKeys, 
            const Data &prefix=Data(), 
            size_t signatures = 0, 
            uint8_t options = 0
        );

        EthereumAddress
        (
            const PubKey &scanKey,
            const PubKey &spendKey,
            const Data &prefix=Data(),
            uint8_t options = 0
        );

        EthereumAddress(const Address &);

};


}
