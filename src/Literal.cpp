#include "Literal.hpp"


namespace Ethereum{

template<>
Stealth::Address Literal<Stealth::Address>(const std::string &encoded)
{
    Stealth::AddressEncoder encoder;
    return encoder.decode(encoded);
}



std::string Literal(const Stealth::Address &address)
{
    Stealth::AddressEncoder encoder;
    return encoder.encode(address);
}




}
