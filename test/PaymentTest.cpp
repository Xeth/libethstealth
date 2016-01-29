
#include <boost/test/unit_test.hpp>

#include "ethkey/cipher/DummyCipher.hpp"

#include "Address.hpp"
#include "Literal.hpp"
#include "PaymentAddressBuilder.hpp"
#include "PaymentResolver.hpp"
#include "KeyGenerator.hpp"
#include "RedeemKeyFactory.hpp"

using namespace Ethereum::Stealth;
using Ethereum::DummyCipher;
using Ethereum::DummyKey;

BOOST_AUTO_TEST_SUITE(PaymentTest)



BOOST_AUTO_TEST_CASE(createPaymentAddress)
{
    Address address = Literal<Address>("vJmzLu29obZcUGXXgotapfQLUpz7dfnZpbr4xg1R75qctf8xaXAteRdi3ZUk3T2ZMSad5KyPbve7uyH6eswYAxLHRVSbWgNUeoGuXp");
    PaymentAddressBuilder builder(address);
    PaymentAddress paymentAddr = builder.build();
    BOOST_REQUIRE_EQUAL(paymentAddr.getAddresses().size(), 1);
}


BOOST_AUTO_TEST_CASE(uncoverPaymentAddress)
{
    KeyGenerator generator;
    Key<DummyCipher> key = generator.generate(DummyCipher(), DummyKey());

    Address address(key);
    PaymentAddressBuilder builder(address);
    PaymentAddress paymentAddr = builder.build();


    PaymentResolver<Key<DummyCipher> > resolver(key);

    SharedSecret secret;
    BOOST_REQUIRE(resolver.uncover(paymentAddr.getAddresses()[0], paymentAddr.getEphemPublicKey(), secret));
}


BOOST_AUTO_TEST_CASE(unknownPayment)
{
    KeyGenerator generator;
    Key<DummyCipher> key = generator.generate(DummyCipher(), DummyKey());

    Address address = Literal<Address>("vJmzLu29obZcUGXXgotapfQLUpz7dfnZpbr4xg1R75qctf8xaXAteRdi3ZUk3T2ZMSad5KyPbve7uyH6eswYAxLHRVSbWgNUeoGuXp");

    PaymentAddressBuilder builder(address);
    PaymentAddress paymentAddr = builder.build();

    PaymentResolver<Key<DummyCipher> > resolver(key);

    SharedSecret secret;
    BOOST_REQUIRE(!resolver.uncover(paymentAddr.getAddresses()[0], paymentAddr.getEphemPublicKey(), secret));
}


BOOST_AUTO_TEST_CASE(redeemKey)
{
    KeyGenerator generator;
    Key<DummyCipher> key = generator.generate(DummyCipher(), DummyKey());

    Address address(key);
    PaymentAddressBuilder builder(address);
    PaymentAddress paymentAddr = builder.build();


    PaymentResolver<Key<DummyCipher> > resolver(key);

    SharedSecret secret;
    BOOST_REQUIRE(resolver.uncover(paymentAddr.getAddresses()[0], paymentAddr.getEphemPublicKey(), secret));

    RedeemKeyFactory redeemFactory;
    KeyPair pair = redeemFactory.create(key.getSpendPrivateKeys()[0].unlock(DummyKey()), secret);

    BOOST_REQUIRE(Ethereum::Address(pair.getPublicKey()) == paymentAddr.getAddresses()[0]);
    BOOST_REQUIRE(Ethereum::Address(key.getScanPublicKey()) != paymentAddr.getAddresses()[0]);
}




BOOST_AUTO_TEST_SUITE_END()
