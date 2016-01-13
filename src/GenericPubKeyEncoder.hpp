#pragma once 

#include "Data.hpp"
#include "PubKey.hpp"

namespace Stealth{


template<class Encoder>
class GenericPubKeyEncoder
{
    public:

        PubKey decode(const std::string &) const;
        std::string encode(const PubKey &) const;
};


}

#include "GenericPubKeyEncoder.ipp"
