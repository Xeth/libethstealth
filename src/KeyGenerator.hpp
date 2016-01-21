#pragma once 

#include "bitcrypto/KeyGenerator.hpp"
#include "Key.hpp"


namespace Stealth{


using BitCrypto::Data;
using BitCrypto::PublicKey;
using BitCrypto::PrivateKey;
using BitCrypto::SecuredPrivateKey;
using BitCrypto::KeyPair;
using BitCrypto::SecuredKeyPair;


class KeyGenerator
{
    public:

        template<class Cipher, class CipherKey>
        Key<Cipher> generate(const Cipher &, const CipherKey &, size_t spendKeys=1);

        template<class Cipher, class CipherKey>
        Key<Cipher> generate(const Cipher &, const CipherKey &, const unsigned char *entropy, size_t entropySize,  size_t spendKeys=1);

        template<class Cipher, class CipherKey>
        Key<Cipher> generate(const Cipher &, const CipherKey &, const Data &entropy,  size_t spendKeys=1);


    private:

        void checkSpendKeysCount(size_t);

    private:
        BitCrypto::KeyGenerator _generator;
};


}


#include "KeyGenerator.ipp"
