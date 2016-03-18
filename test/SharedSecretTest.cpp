
#include <boost/test/unit_test.hpp>

#include "SharedSecretFactory.hpp"
#include "ethkey/key/KeyGenerator.hpp"

using Ethereum::KeyGenerator;

BOOST_AUTO_TEST_SUITE(SharedSecretTest)



BOOST_AUTO_TEST_CASE(generate)
{

    Ethereum::KeyGenerator generator;
    Ethereum::KeyPair scan = generator.generate();
    Ethereum::KeyPair ephemeral = generator.generate();

    Ethereum::Stealth::SharedSecretFactory secretFactory;
    Ethereum::Stealth::SharedSecret secret = secretFactory.createFromScanPublic(scan.getPublicKey(), ephemeral.getPrivateKey());
    Ethereum::Stealth::SharedSecret secret2 = secretFactory.createFromScanSecret(scan.getPrivateKey(), ephemeral.getPublicKey());

    for(size_t i=0; i<secret.size(); i++)
    {
        BOOST_REQUIRE_EQUAL(secret[i], secret2[i]);
    }
}




BOOST_AUTO_TEST_SUITE_END()
