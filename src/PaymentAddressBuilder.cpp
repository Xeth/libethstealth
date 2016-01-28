#include "PaymentAddressBuilder.hpp"


namespace Ethereum{namespace Stealth{


PaymentAddressBuilder::PaymentAddressBuilder(const Address &address) :
    _address(address),
    _pubkeyFactory(_keyGenerator.getPublicKeyFactory())
{}


PaymentAddress PaymentAddressBuilder::build()
{
    Ethereum::KeyPair ephem = _keyGenerator.generate();
    SharedSecret secret = _secretFactory.createFromScanPublic(_address.getScanKey(), ephem.getPrivateKey());

    const std::vector<PublicKey> & spendKeys = _address.getSpendKeys();
    AddressCollection destinations;
    PublicKey secretPub = _pubkeyFactory.createFromSecret(secret);

    for(std::vector<PublicKey>::const_iterator it = spendKeys.begin(), end = spendKeys.end(); it!=end; ++it)
    {
        destinations.push_back(Ethereum::Address(*it + secretPub));
    }

    return PaymentAddress(ephem.getPublicKey(), destinations);
}


}}
