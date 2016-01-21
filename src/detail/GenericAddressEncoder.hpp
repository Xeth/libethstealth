#pragma once 

#include "bitcrypto/Data.hpp"
#include "bitcrypto/DoubleSha256CheckSum.hpp"
#include "bitcrypto/serialization/BinaryPublicKeySerializer.hpp"
#include "bitcrypto/encoding/Base58Encoder.hpp"

#include "Address.hpp"



namespace Stealth{


using namespace BitCrypto;



template<class Encoder>
class GenericAddressEncoder 
{
    public:

        std::string encode(const Address &) const;
        Address decode(const std::string &) const;

};



}

#include "GenericAddressEncoder.ipp"
