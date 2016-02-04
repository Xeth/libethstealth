#pragma once 

#include "detail/GenericAddressEncoder.hpp"

namespace Ethereum{namespace Stealth{

typedef GenericAddressEncoder<Base58Encoder> AddressEncoder;

}}
