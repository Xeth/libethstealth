#pragma once 

#include "ethkey/KeyGenerator.hpp"
#include "Key.hpp"


namespace Ethereum{namespace Stealth{


using Ethereum::Data;
using Ethereum::PublicKey;
using Ethereum::PrivateKey;
using Ethereum::SecuredPrivateKey;
using Ethereum::KeyPair;
using Ethereum::SecuredKeyPair;


class KeyGenerator
{
    public:

        template<class Cipher, class CipherKey>
        Key<Cipher> generate(const Cipher &, const CipherKey &, size_t spendKeys=1);

        template<class Cipher, class CipherKey>
        Key<Cipher> generate(const unsigned char *entropy, size_t entropySize, const Cipher &, const CipherKey &,  size_t spendKeys=1);

        template<class Cipher, class CipherKey>
        Key<Cipher> generate(const Data &entropy, const Cipher &, const CipherKey &,  size_t spendKeys=1);


    private:

        void checkSpendKeysCount(size_t);

    private:
        Ethereum::KeyGenerator _generator;
};


}}


#include "KeyGenerator.ipp"
