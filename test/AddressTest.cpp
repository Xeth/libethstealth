
#include <boost/test/unit_test.hpp>

#include "bitcrypto/serialization/Base16PubKeySerializer.hpp"
#include "BitcoinAddress.hpp"
#include "Base58AddressEncoder.hpp"

using namespace Stealth;
using namespace BitCrypto;

BOOST_AUTO_TEST_SUITE(StealthAddressTest)


BOOST_AUTO_TEST_CASE(base58Encode)
{

    Base16PubKeySerializer serializer;
    PubKey scan = serializer.unserialize("03d9e876028f4fc062c19f7097762e4affc2ce4edfffa7d42e3c17cd157ec6d1bc");
    PubKey spend = serializer.unserialize("0215a49b55a2ed2a02569cb6c018644211d408caab3aca86d2cc7d6a9e5789b1d2");

    BitcoinAddress address(scan, spend);

    Base58AddressEncoder addressEncoder;

    BOOST_REQUIRE_EQUAL(addressEncoder.encode(address), "vJmzLu29obZcUGXXgotapfQLUpz7dfnZpbr4xg1R75qctf8xaXAteRdi3ZUk3T2ZMSad5KyPbve7uyH6eswYAxLHRVSbWgNUeoGuXp");

}


BOOST_AUTO_TEST_CASE(base58Decode)
{
    Base58AddressEncoder addressEncoder;
    Base16PubKeySerializer serializer;

    BitcoinAddress address = addressEncoder.decode("vJmzLu29obZcUGXXgotapfQLUpz7dfnZpbr4xg1R75qctf8xaXAteRdi3ZUk3T2ZMSad5KyPbve7uyH6eswYAxLHRVSbWgNUeoGuXp");
    
    const PubKey & scanKey = address.getScanKey();
    const std::vector<PubKey> & spendKeys = address.getSpendKeys();

    BOOST_REQUIRE_EQUAL(spendKeys.size(), 1);
    BOOST_REQUIRE_EQUAL(serializer.serialize(scanKey), "03d9e876028f4fc062c19f7097762e4affc2ce4edfffa7d42e3c17cd157ec6d1bc");
    BOOST_REQUIRE_EQUAL(serializer.serialize(spendKeys[0]), "0215a49b55a2ed2a02569cb6c018644211d408caab3aca86d2cc7d6a9e5789b1d2");
    BOOST_REQUIRE_EQUAL(address.getPrefix().size(), 0);
    BOOST_REQUIRE_EQUAL(address.getOptions(), 0);
    BOOST_REQUIRE_EQUAL(address.getVersion(), BitcoinAddress::Main_Net);
}



BOOST_AUTO_TEST_SUITE_END()
