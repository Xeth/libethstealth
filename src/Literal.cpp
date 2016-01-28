#include "Literal.hpp"


namespace Ethereum{

template<>
Stealth::Address Literal<Stealth::Address>(const std::string &encoded)
{
    Stealth::Base58AddressEncoder encoder;
    return encoder.decode(encoded);
}



namespace Stealth{



std::string Literal(const Address &address)
{
    Base58AddressEncoder encoder;
    return encoder.encode(address);
}




}}
