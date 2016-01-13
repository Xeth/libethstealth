#pragma once

#include "GenericPubKeyEncoder.hpp"
#include "Base58Encoder.hpp"


namespace Stealth{


typedef GenericPubKeyEncoder<Base58Encoder> Base58PubKeyEncoder;


}
