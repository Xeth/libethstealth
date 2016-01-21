namespace Stealth{


template<class Cipher, class CipherKey>
Key<Cipher> KeyGenerator::generate(const Cipher &cipher, const CipherKey &cipherKey, size_t spendKeysCount)
{
    checkSpendKeysCount(spendKeysCount);

    std::vector<PublicKey> spendPub;
    std::vector<SecuredPrivateKey<Cipher> > spendKeys;
    spendPub.reserve(spendKeysCount);
    spendKeys.reserve(spendKeysCount);

    KeyPair scanKey = _generator.generate();

    for(size_t i=0; i<spendKeysCount; ++i)
    {
        SecuredKeyPair<Cipher> pair = _generator.generate(cipher, cipherKey);
        spendPub.push_back(pair.getPublicKey());
        spendKeys.push_back(pair.getPrivateKey());
    }

    return Key<Cipher>(scanKey.getPrivateKey(), scanKey.getPublicKey(), spendKeys, spendPub);
}


template<class Cipher, class CipherKey>
Key<Cipher> KeyGenerator::generate(const Cipher &cipher, const CipherKey &cipherKey, const Data &entropy, size_t spendKeysCount)
{
    return generate(cipher, cipherKey, &*entropy.begin(), entropy.size(), spendKeysCount);
}


template<class Cipher, class CipherKey>
Key<Cipher> KeyGenerator::generate(const Cipher &cipher, const CipherKey &cipherKey, const unsigned char *entropy, size_t entropySize, size_t spendKeysCount)
{

    checkSpendKeysCount(spendKeysCount);

    if(entropySize < (spendKeysCount + 1) * 32)
    {
        throw std::runtime_error("not enough entropy");
    }

    std::vector<PublicKey> spendPub;
    std::vector<SecuredPrivateKey<Cipher> > spendKeys;
    spendPub.reserve(spendKeysCount);
    spendKeys.reserve(spendKeysCount);

    size_t entropyChunk = entropySize / (spendKeysCount + 1);

    KeyPair scanKey = _generator.generate(entropy, entropyChunk);
    entropy += entropyChunk;

    for(size_t i=0; i<spendKeysCount; ++i)
    {
        SecuredKeyPair<Cipher> pair = _generator.generate(entropy, entropyChunk, cipher, cipherKey);
        entropy += entropyChunk;

        spendPub.push_back(pair.getPublicKey());
        spendKeys.push_back(pair.getPrivateKey());
    }

    return Key<Cipher>(scanKey.getPrivateKey(), scanKey.getPublicKey(), spendKeys, spendPub);
}


inline void KeyGenerator::checkSpendKeysCount(size_t count)
{
    if(count == 0)
    {
        throw std::runtime_error("can't have zero spend keys");
    }
}


}
