#pragma once 

#include "ethcrypto/checksum/DoubleSha256CheckSum.hpp"
#include "ethcrypto/serialization/PublicKeySerializer.hpp"
#include "ethcrypto/encoding/Base58Encoder.hpp"

#include "../Address.hpp"



namespace Ethereum{ namespace Stealth{


using Ethereum::Data;
using Ethereum::DoubleSha256CheckSum;
using Ethereum::BinaryPublicKeySerializer;
using Ethereum::Base58Encoder;


template<class Encoder>
class GenericAddressEncoder 
{
    public:

        std::string encode(const Address &) const;
        Address decode(const std::string &) const;

};



}}

#include "GenericAddressEncoder.ipp"
