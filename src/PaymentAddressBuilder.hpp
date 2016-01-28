#pragma once 

#include "ethkey/KeyGenerator.hpp"

#include "Address.hpp"
#include "PaymentAddress.hpp"
#include "SharedSecretFactory.hpp"


namespace Ethereum{namespace Stealth{



class PaymentAddressBuilder
{
    public:
        PaymentAddressBuilder(const Address &);

        PaymentAddress build();

    private:
        const Address &_address;
        Ethereum::KeyGenerator _keyGenerator;
        SharedSecretFactory _secretFactory;
        Ethereum::PublicKeyFactory &_pubkeyFactory;

};



}}
