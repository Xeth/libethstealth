
#include <boost/test/unit_test.hpp>

#include "bitcrypto/cipher/DummyCipher.hpp"
#include "bitcrypto/SignatureValidator.hpp"
#include "bitcrypto/Sha256.hpp"
#include "bitcrypto/Signer.hpp"
#include "bitcrypto/Literal.hpp"

#include "KeyGenerator.hpp"

using namespace Stealth;
using BitCrypto::DummyCipher;
using BitCrypto::DummyKey;
using BitCrypto::SignatureValidator;
using BitCrypto::Sha256;
using BitCrypto::Data;
using BitCrypto::Signer;
using BitCrypto::Signature;
using BitCrypto::Literal;

BOOST_AUTO_TEST_SUITE(KeyGeneratorTest)

template<class Cipher>
void validateKeys(const Key<Cipher> &key)
{
    SignatureValidator validator;
    Signer signer;
    Sha256 hasher;
    Data hash = hasher.hash("data");

    Signature signature = signer.sign(key.getScanPrivateKey(), hash);

    BOOST_REQUIRE(validator.verify(key.getScanPublicKey(), signature, hash));

    Signature signature2 = signer.sign(key.getSpendPrivateKeys()[0].unlock(DummyKey()), hash);
    BOOST_REQUIRE(validator.verify(key.getSpendPublicKeys()[0], signature2, hash));
}


BOOST_AUTO_TEST_CASE(generateFromEntropy)
{
    KeyGenerator generator;
    Key<DummyCipher> key = generator.generate(DummyCipher(), DummyKey(), (const unsigned char *)"0123456789012345678901234567890123456789012345678901234567890123456789", 70);
    validateKeys(key);

    Key<DummyCipher> key2 = generator.generate(DummyCipher(), DummyKey(), (const unsigned char *)"0123456789012345678901234567890123456789012345678901234567890123456789", 70);

    BOOST_REQUIRE_EQUAL(Literal(key.getScanPrivateKey()), Literal(key2.getScanPrivateKey()));
    BOOST_REQUIRE_EQUAL(Literal(key.getScanPublicKey()), Literal(key2.getScanPublicKey()));
    BOOST_REQUIRE_EQUAL(key.getSpendPublicKeys().size(), key2.getSpendPublicKeys().size());
    BOOST_REQUIRE_EQUAL(key.getSpendPrivateKeys().size(), key2.getSpendPrivateKeys().size());
    BOOST_REQUIRE_EQUAL(Literal(key.getSpendPublicKeys()[0]), Literal(key2.getSpendPublicKeys()[0]));
    BOOST_REQUIRE_EQUAL(Literal(key.getSpendPrivateKeys()[0]), Literal(key2.getSpendPrivateKeys()[0]));

}


BOOST_AUTO_TEST_CASE(invalidEntropy)
{
    KeyGenerator generator;
    BOOST_CHECK_THROW(generator.generate(DummyCipher(), DummyKey(), (const unsigned char *)"asd", 3), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(generateRandom)
{
    KeyGenerator generator;
    Key<DummyCipher> key = generator.generate(DummyCipher(), DummyKey());
    BOOST_REQUIRE_EQUAL(key.getSpendPublicKeys().size(), 1);
    BOOST_REQUIRE_EQUAL(key.getSpendPrivateKeys().size(), 1);
    validateKeys(key);
}


BOOST_AUTO_TEST_SUITE_END()
