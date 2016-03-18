
#include "ethkey/serialization/Literal.hpp"
#include "ethkey/encoding/HexEncoder.hpp"

#include "Address.hpp"
#include "AddressEncoder.hpp"
#include "SharedSecret.hpp"

namespace Ethereum{

template<>
Stealth::Address Literal<Stealth::Address>(const std::string &);

template<>
Stealth::SharedSecret Literal<Stealth::SharedSecret>(const std::string &);

std::string Literal(const Stealth::Address &);
std::string Literal(const Stealth::SharedSecret &);


namespace Stealth{

using Ethereum::Literal;

}


}
