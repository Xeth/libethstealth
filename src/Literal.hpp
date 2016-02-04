
#include "ethkey/Literal.hpp"
#include "Address.hpp"
#include "AddressEncoder.hpp"

namespace Ethereum{

template<>
Stealth::Address Literal<Stealth::Address>(const std::string &);


std::string Literal(const Stealth::Address &);


namespace Stealth{

using Ethereum::Literal;

}


}
