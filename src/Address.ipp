
namespace Ethereum{ namespace Stealth{


template<class Cipher>
Address::Address(const Key<Cipher> &key, size_t signatures, const Data &prefix, uint8_t options, uint8_t version) :
    _scanKey(key.getScanPubKey()),
    _spendKeys(key.getSpendPubKeys()),
    _version(version),
    _signatures(signatures ? signatures : _spendKeys.size()),
    _options(options),
    _prefix(prefix)
{}


}}
