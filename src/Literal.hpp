
#include "ethkey/Literal.hpp"
#include "Address.hpp"
#include "Base58AddressEncoder.hpp"

namespace Ethereum{

template<>
Stealth::Address Literal<Stealth::Address>(const std::string &);


namespace Stealth{


using Ethereum::Literal;


std::string Literal(const Address &);


}}
