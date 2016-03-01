#pragma once 

#include <string>
#include <ctime>

#include <json/value.h>
#include <json/reader.h>
#include <json/writer.h>

#include "ethkey/SecuredPrivateKey.hpp"
#include "ethkey/PublicKey.hpp"
#include "ethkey/serialization/PrivateKeySerializer.hpp"
#include "ethkey/encoding/HexEncoder.hpp"

#include "Key.hpp"
#include "Literal.hpp"

namespace Ethereum{namespace Stealth{


using Ethereum::PublicKey;
using Ethereum::SecuredPrivateKey;
using Ethereum::EncodeHex;
using Ethereum::DecodeHex;
using Ethereum::PrivateKeySerializer;
using Ethereum::PublicKeyFactory;


template<class Cipher>
class KeySerializer
{
    public:

        Json::Value serializeToJson(const Key<Cipher> &) const;
        std::string serialize(const Key<Cipher> &) const;

        Key<Cipher> unserialize(const Json::Value &) const;
        Key<Cipher> unserialize(const std::string &) const;

    private:
        Json::Value serializeSpendKeys(const Key<Cipher> &) const;
        void unserializeSpendKeys(const Json::Value &, std::vector<SecuredPrivateKey<Cipher> > &, std::vector<PublicKey> &) const;

    private:
        PrivateKeySerializer<Cipher> _secretSerializer;
        PublicKeySerializer _pubSerializer;
        PublicKeyFactory _pubFactory;

};


}}


#include "KeySerializer.ipp"
