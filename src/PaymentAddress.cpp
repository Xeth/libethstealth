#include "PaymentAddress.hpp"

namespace Ethereum{namespace Stealth{


PaymentAddress::PaymentAddress(const PublicKey &ephem, const AddressCollection &addresses) :
    _addresses(addresses),
    _ephem(ephem)
{}

const AddressCollection & PaymentAddress::getAddresses() const
{
    return _addresses;
}

const PublicKey & PaymentAddress::getEphemPublicKey() const
{
    return _ephem;
}






}}
