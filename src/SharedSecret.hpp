#pragma once 

#include <boost/array.hpp>


namespace Ethereum{namespace Stealth{


class SharedSecret : public boost::array<unsigned char, 32>
{
    public:
        unsigned char * operator & ();
        const unsigned char * operator & () const;
};


}}
