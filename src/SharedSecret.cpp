#include "SharedSecret.hpp"


namespace Ethereum{namespace Stealth{


unsigned char * SharedSecret::operator & ()
{
    return data();
}


const unsigned char * SharedSecret::operator & () const
{
    return data();
}


}}
