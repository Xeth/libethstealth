
#include <boost/test/unit_test.hpp>

#include "bitcrypto/serialization/Base16PublicKeySerializer.hpp"
#include "Address.hpp"
#include "Base58AddressEncoder.hpp"

using namespace Stealth;
using namespace BitCrypto;

BOOST_AUTO_TEST_SUITE(AddressEncodingTest)


BOOST_AUTO_TEST_CASE(base58Encode)
{

    Base16PublicKeySerializer serializer;
    PublicKey scan = serializer.unserialize("03d9e876028f4fc062c19f7097762e4affc2ce4edfffa7d42e3c17cd157ec6d1bc");
    PublicKey spend = serializer.unserialize("0215a49b55a2ed2a02569cb6c018644211d408caab3aca86d2cc7d6a9e5789b1d2");

    Address address(scan, spend, 0x2a);

    Base58AddressEncoder addressEncoder;

    BOOST_REQUIRE_EQUAL(addressEncoder.encode(address), "vJmzLu29obZcUGXXgotapfQLUpz7dfnZpbr4xg1R75qctf8xaXAteRdi3ZUk3T2ZMSad5KyPbve7uyH6eswYAxLHRVSbWgNUeoGuXp");

}


BOOST_AUTO_TEST_CASE(base58Decode)
{
    Base58AddressEncoder addressEncoder;
    Base16PublicKeySerializer serializer;

    Address address = addressEncoder.decode("vJmzLu29obZcUGXXgotapfQLUpz7dfnZpbr4xg1R75qctf8xaXAteRdi3ZUk3T2ZMSad5KyPbve7uyH6eswYAxLHRVSbWgNUeoGuXp");
    
    const PublicKey & scanKey = address.getScanKey();
    const std::vector<PublicKey> & spendKeys = address.getSpendKeys();

    BOOST_REQUIRE_EQUAL(spendKeys.size(), 1);
    BOOST_REQUIRE_EQUAL(serializer.serialize(scanKey), "03d9e876028f4fc062c19f7097762e4affc2ce4edfffa7d42e3c17cd157ec6d1bc");
    BOOST_REQUIRE_EQUAL(serializer.serialize(spendKeys[0]), "0215a49b55a2ed2a02569cb6c018644211d408caab3aca86d2cc7d6a9e5789b1d2");
    BOOST_REQUIRE_EQUAL(address.getPrefix().size(), 0);
    BOOST_REQUIRE_EQUAL(address.getOptions(), 0);
    BOOST_REQUIRE_EQUAL(address.getVersion(), 0x2a);
}



BOOST_AUTO_TEST_SUITE_END()