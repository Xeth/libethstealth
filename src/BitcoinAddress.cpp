#include "BitcoinAddress.hpp"


namespace Stealth{


BitcoinAddress::BitcoinAddress(Type type, const PubKey &scanKey, const std::vector<PubKey> &spendKeys, const Data &prefix, size_t signatures, uint8_t options) : 
    Address(type, scanKey, spendKeys, prefix, signatures, options)
{}


BitcoinAddress::BitcoinAddress(Type type, const PubKey &scanKey, const PubKey &spendKey, const Data &prefix, uint8_t options) :
    Address(type, scanKey, spendKey, prefix, options)
{}


BitcoinAddress::BitcoinAddress(const PubKey &scanKey, const std::vector<PubKey> &spendKeys, const Data &prefix, size_t signatures, uint8_t options) :
    Address(Main_Net, scanKey, spendKeys, prefix, signatures, options)
{}


BitcoinAddress::BitcoinAddress(const PubKey &scanKey, const PubKey &spendKey, const Data &prefix, uint8_t options) : 
    Address(Main_Net, scanKey, spendKey, prefix, options)
{}


BitcoinAddress::BitcoinAddress(const Address &copy) : Address(copy)
{
    uint8_t version = getVersion();

    if(version!=Main_Net&&version!=Test_Net)
    {
        throw std::runtime_error("invalid bitcoin stealth address");
    }
}


}
