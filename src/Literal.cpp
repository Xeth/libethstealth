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


template<>
Stealth::SharedSecret Literal<Stealth::SharedSecret>(const std::string &encoded)
{
    HexEncoder encoder;
    Stealth::SharedSecret secret;
    encoder.decode(encoded.begin(), encoded.end(), (boost::array<unsigned char, 32> &)secret);
    return secret;
}


std::string Literal(const Stealth::SharedSecret &secret)
{
    return EncodeHex(secret);
}

}
