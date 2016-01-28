#pragma once 

#include "ethkey/Address.hpp"
#include "ethkey/PublicKey.hpp"
#include "ethkey/PublicKeyFactory.hpp"

#include "SharedSecret.hpp"
#include "SharedSecretFactory.hpp"
#include "Key.hpp"


namespace Ethereum{namespace Stealth{


using Ethereum::PublicKey;
using Ethereum::PublicKeyFactory;


template<class Key>
class PaymentResolver
{
    public:
        PaymentResolver(const Key &);

        bool uncover(const Ethereum::Address &, const PublicKey &, SharedSecret &);
        bool uncover(const Ethereum::Address &, const PublicKey &, SharedSecret &, size_t spendIndex);

    private:
        const Key &_key;
        SharedSecretFactory _secretFactory;
        PublicKeyFactory _pubkeyFactory;

};


}}


#include "PaymentResolver.ipp"
