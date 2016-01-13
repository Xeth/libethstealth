#pragma once 

#include "GenericAddressEncoder.hpp"
#include "Base58Encoder.hpp"

namespace Stealth{


typedef GenericAddressEncoder<Base58Encoder> Base58AddressEncoder;


}
