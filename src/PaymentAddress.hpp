#pragma once 

#include "ethcrypto/key/PublicKey.hpp"
#include "ethcrypto/key/Address.hpp"


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
