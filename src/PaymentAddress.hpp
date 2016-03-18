#pragma once 

#include "ethkey/key/PublicKey.hpp"
#include "ethkey/key/Address.hpp"


namespace Ethereum{namespace Stealth{


using Ethereum::PublicKey;

typedef std::vector<Ethereum::Address> AddressCollection;


class PaymentAddress
{
    public:
        PaymentAddress(const PublicKey &ephem, const AddressCollection &address);

        const AddressCollection & getAddresses() const;
        const PublicKey & getEphemPublicKey() const;


    private:
        AddressCollection _addresses;
        PublicKey _ephem;
};



}}
