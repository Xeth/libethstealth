
#include <boost/test/unit_test.hpp>

#include "ethkey/cipher/DummyCipher.hpp"

#include "Address.hpp"
#include "Literal.hpp"
#include "KeyGenerator.hpp"
#include "KeySerializer.hpp"



using namespace Ethereum;

BOOST_AUTO_TEST_SUITE(KeySerializationTest)


BOOST_AUTO_TEST_CASE(serializeSuccess)
{

    Stealth::KeyGenerator generator;
    Stealth::KeySerializer<DummyCipher> serializer;
    Stealth::Key<DummyCipher> key = generator.generate(DummyCipher(), "");
    std::string serialized = serializer.serialize(key);
    Stealth::Key<DummyCipher> key2 = serializer.unserialize(serialized);

    const std::vector<PublicKey> & spendPubs = key2.getSpendPublicKeys();
    const std::vector<PublicKey> & spendPubsCheck = key.getSpendPublicKeys();
    const std::vector<SecuredPrivateKey<DummyCipher> > & spendSecrets = key2.getSpendPrivateKeys();
    const std::vector<SecuredPrivateKey<DummyCipher> > & spendSecretsCheck = key.getSpendPrivateKeys();

    BOOST_REQUIRE(key.getScanPublicKey() == key2.getScanPublicKey());
    BOOST_REQUIRE(key.getScanPrivateKey() == key2.getScanPrivateKey());
    BOOST_REQUIRE_EQUAL(spendSecrets.size(), spendSecretsCheck.size());
    BOOST_REQUIRE_EQUAL(spendPubs.size(), spendPubsCheck.size());

    for(size_t i=0; i<spendPubs.size(); i++)
    {
        BOOST_REQUIRE(spendPubs[i] == spendPubsCheck[i]);
        BOOST_REQUIRE(spendSecrets[i].getData().data == spendSecretsCheck[i].getData().data);
    }

}





BOOST_AUTO_TEST_SUITE_END()
