
#include <boost/test/unit_test.hpp>

#include "ethkey/cipher/DummyCipher.hpp"
#include "ethkey/SignatureValidator.hpp"
#include "ethkey/hash/Sha256.hpp"
#include "ethkey/Signer.hpp"
#include "ethkey/Literal.hpp"

#include "KeyGenerator.hpp"

using namespace Ethereum::Stealth;
using Ethereum::DummyCipher;
using Ethereum::DummyKey;
using Ethereum::SignatureValidator;
using Ethereum::Sha256;
using Ethereum::Data;
using Ethereum::Signer;
using Ethereum::Signature;
using Ethereum::Literal;

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
    Key<DummyCipher> key = generator.generate((const unsigned char *)"0123456789012345678901234567890123456789012345678901234567890123456789", 70, DummyCipher(), DummyKey());
    validateKeys(key);

    Key<DummyCipher> key2 = generator.generate((const unsigned char *)"0123456789012345678901234567890123456789012345678901234567890123456789", 70, DummyCipher(), DummyKey());

    BOOST_REQUIRE(key.getScanPrivateKey() == key2.getScanPrivateKey());
//    BOOST_REQUIRE(key.getScanPublicKey() == key2.getScanPublicKey());
//    BOOST_REQUIRE_EQUAL(key.getSpendPublicKeys().size(), key2.getSpendPublicKeys().size());
//    BOOST_REQUIRE_EQUAL(key.getSpendPrivateKeys().size(), key2.getSpendPrivateKeys().size());
//    BOOST_REQUIRE(key.getSpendPublicKeys()[0] == key2.getSpendPublicKeys()[0]);
//    BOOST_REQUIRE(key.getSpendPrivateKeys()[0].getData().data == key2.getSpendPrivateKeys()[0].getData().data);

}


BOOST_AUTO_TEST_CASE(invalidEntropy)
{
    KeyGenerator generator;
    BOOST_CHECK_THROW(generator.generate((const unsigned char *)"asd", 3, DummyCipher(), DummyKey()), std::runtime_error);
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
