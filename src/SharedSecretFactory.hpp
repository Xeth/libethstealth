#pragma once 

#include "ethcrypto/key/PublicKey.hpp"
#include "ethcrypto/key/PrivateKey.hpp"
#include "ethcrypto/hash/Sha256.hpp"
#include "ethcrypto/serialization/PublicKeySerializer.hpp"


#include "Key.hpp"
#include "SharedSecret.hpp"


namespace Ethereum{namespace Stealth{


using Ethereum::PublicKey;
using Ethereum::PrivateKey;
using Ethereum::Sha256;
using Ethereum::BinaryPublicKeySerializer;
using Ethereum::CompressedPoint;


class SharedSecretFactory
{
    public:

        SharedSecret createFromScanPublic(const PublicKey &scan, const PrivateKey &ephemeral) const;
        SharedSecret createFromScanSecret(const PrivateKey &scan, const PublicKey &ephemeral) const;
        SharedSecret create(const PublicKey &scanOrEphemeral, const PrivateKey &ephemeralOrScan) const;
};


}}
