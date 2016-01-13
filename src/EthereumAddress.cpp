#include "EthereumAddress.hpp"


namespace Stealth{


EthereumAddress::EthereumAddress(const PubKey &scanKey, const std::vector<PubKey> &spendKeys, const Data &prefix, size_t signatures, uint8_t options) : 
    Address(ETHEREUM_ADDRESS_VERSION, scanKey, spendKeys, prefix, signatures, options)
{}


EthereumAddress::EthereumAddress(const PubKey &scanKey, const PubKey &spendKey, const Data &prefix, uint8_t options) : 
    Address(ETHEREUM_ADDRESS_VERSION, scanKey, spendKey, prefix, options)
{}


EthereumAddress::EthereumAddress(const Address &copy) : Address(copy)
{
    if(getVersion() != ETHEREUM_ADDRESS_VERSION)
    {
        throw std::runtime_error("invalid ethereum stealth address");
    }
}


}
