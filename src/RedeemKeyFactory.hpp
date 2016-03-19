#pragma once 


#include "ethcrypto/key/KeyPair.hpp"
#include "ethcrypto/key/SecuredKeyPair.hpp"
#include "ethcrypto/key/PublicKeyFactory.hpp"


#include "SharedSecret.hpp"


namespace Ethereum{namespace Stealth{


using Ethereum::KeyPair;
using Ethereum::SecuredKeyPair;
using Ethereum::PublicKeyFactory;
using Ethereum::PublicKey;
using Ethereum::PrivateKey;



class RedeemKeyFactory
{
    public:

        KeyPair create(const PrivateKey &spendPrivate, const SharedSecret &secret);

        template<class Cipher, class CipherKey>
        SecuredKeyPair<Cipher> create(const PrivateKey &spendPrivate, const SharedSecret &, const Cipher &, const CipherKey &);

    private:
        PrivateKey createRedeemSecret(const PrivateKey &spendPrivate, const SharedSecret &);

    private:
        PublicKeyFactory _pubkeyFactory;

};


}}

#include "RedeemKeyFactory.ipp"
