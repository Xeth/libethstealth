#include "RedeemKeyFactory.hpp"


namespace Ethereum{namespace Stealth{


KeyPair RedeemKeyFactory::create(const PrivateKey &spendPrivate, const SharedSecret &secret)
{
    PrivateKey redeemSecret = createRedeemSecret(spendPrivate, secret);
    return KeyPair(redeemSecret, _pubkeyFactory.createFromSecret(redeemSecret));
}


}}
