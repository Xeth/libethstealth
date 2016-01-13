#pragma once 

#include "Data.hpp"
#include "Address.hpp"
#include "DoubleSha256CheckSum.hpp"


namespace Stealth{


template<class Encoder>
class GenericAddressEncoder 
{
    public:

        std::string encode(const Address &) const;
        Address decode(const std::string &) const;

};


}

#include "GenericAddressEncoder.ipp"
