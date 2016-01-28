

namespace Ethereum{namespace Stealth{


template<class Cipher, class CipherKey>
SecuredKeyPair<Cipher> 
RedeemKeyFactory::create(const PrivateKey &spendPrivate, const SharedSecret &secret, const Cipher &cipher, const CipherKey &key)
{
    PrivateKey redeemSecret = createRedeemSecret(spendPrivate, secret);
    return SecuredKeyPair<Cipher>(redeemSecret, _pubkeyFactory.createFromSecret(redeemSecret), cipher, key);
}



inline PrivateKey RedeemKeyFactory::createRedeemSecret(const PrivateKey &spendPrivate, const SharedSecret &secret)
{
    return spendPrivate + secret;
}



}}
