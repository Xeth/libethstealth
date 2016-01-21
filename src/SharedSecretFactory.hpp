#pragma once 

#include "bitcrypto/PublicKey.hpp"
#include "bitcrypto/PrivateKey.hpp"
#include "bitcrypto/Sha256.hpp"
#include "bitcrypto/serialization/BinaryPublicKeySerializer.hpp"


#include "Key.hpp"
#include "SharedSecret.hpp"


namespace Stealth{


using BitCrypto::PublicKey;
using BitCrypto::PrivateKey;
using BitCrypto::Sha256;
using BitCrypto::BinaryPublicKeySerializer;
using BitCrypto::CompressedPoint;


class SharedSecretFactory
{
    public:

        SharedSecret createFromScanPublic(const PublicKey &scan, const PrivateKey &ephemeral) const;
        SharedSecret createFromScanSecret(const PrivateKey &scan, const PublicKey &ephemeral) const;
        SharedSecret create(const PublicKey &scanOrEphemeral, const PrivateKey &ephemeralOrScan) const;
};


}
