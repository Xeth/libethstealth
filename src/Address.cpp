#include "Address.hpp"


namespace Stealth{



//Address::Address(const Key &key, const Data &prefix, size_t signatures, uint8_t options, uint8_t version) :
//    _scanKey(key.getScanPubKey()),
//    _spendKeys(key.getSpendPubKeys()),
//    _version(version),
//    _signatures(signatures ? signatures : _spendKeys.size()),
//    _options(options),
//    _prefix(prefix)
//{}


Address::Address(uint8_t version, const PubKey &scanKey, const std::vector<PubKey> &spendKeys, const Data &prefix, size_t signatures, uint8_t options) : 
    _scanKey(scanKey),
    _spendKeys(spendKeys),
    _version(version),
    _signatures(signatures ? signatures : _spendKeys.size()),
    _options(options),
    _prefix(prefix)
{}

Address::Address(uint8_t version, const PubKey &scanKey, const PubKey &spendKey, const Data &prefix, uint8_t options) :
    _scanKey(scanKey),
    _version(version),
    _signatures(1),
    _options(options),
    _prefix(prefix)
{
    _spendKeys.push_back(spendKey);
}



uint8_t Address::getVersion() const
{
    return _version;
}

uint8_t Address::getOptions() const
{
    return _options;
}

const Data & Address::getPrefix() const
{
    return _prefix;
}

size_t Address::getRequiredSignatures() const
{
    return _signatures;
}


const PubKey & Address::getScanKey() const
{
    return _scanKey;
}

const std::vector<PubKey> & Address::getSpendKeys() const
{
    return _spendKeys;
}



}
