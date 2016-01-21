#include "SharedSecretFactory.hpp"


namespace Stealth{


SharedSecret SharedSecretFactory::createFromScanPublic(const PublicKey &scan, const PrivateKey &ephemeral) const
{
    return create(scan, ephemeral);
}


SharedSecret SharedSecretFactory::createFromScanSecret(const PrivateKey &scan, const PublicKey &ephemeral) const
{
    return create(ephemeral, scan);
}


SharedSecret SharedSecretFactory::create(const PublicKey &scanOrEphemeral, const PrivateKey &ephemeralOrScan) const
{
    SharedSecret sharedSecret;
    PublicKey sharedPub = scanOrEphemeral + ephemeralOrScan;
    BinaryPublicKeySerializer serializer;
    CompressedPoint point = serializer.serialize<CompressedPoint>(sharedPub);
    Sha256 hasher;
    hasher.hash(point.begin(), point.end(), sharedSecret.begin());
    return sharedSecret;
}

}
