#pragma once 

#include "GenericPubKeyEncoder.hpp"
#include "Base16Encoder.hpp"

namespace Stealth{

typedef GenericPubKeyEncoder<Base16Encoder> Base16PubKeyEncoder;

}
