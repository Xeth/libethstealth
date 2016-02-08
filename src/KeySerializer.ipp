namespace Ethereum{namespace Stealth{


template<class Cipher>
Json::Value KeySerializer<Cipher>::serializeToJson(const Key<Cipher> &key) const
{
    Address address(key);
    Json::Value json;
    json["address"] = address.toString();
    json["scan"] = Literal(key.getScanPrivateKey());
    json["version"] = 1;
    json["spend"] = serializeSpendKeys(key);
    json["time"] = (unsigned)time(NULL);
    return json;
}


template<class Cipher>
Json::Value KeySerializer<Cipher>::serializeSpendKeys(const Key<Cipher> &key) const
{
    Json::Value json;
    const std::vector<PublicKey> & pubs = key.getSpendPublicKeys();
    const std::vector<SecuredPrivateKey<Cipher> > & secrets = key.getSpendPrivateKeys();

    for(int i=0; i<pubs.size(); i++)
    {
        Json::Value keyData;
        keyData["pub"] = _pubSerializer.serialize(pubs[i]);
        keyData["secret"] = _secretSerializer.serializeToJson(secrets[i]);
        json.append(keyData);
    }

    return json;
}


template<class Cipher>
std::string KeySerializer<Cipher>::serialize(const Key<Cipher> &key) const
{
    Json::FastWriter writer;
    return writer.write(serializeToJson(key));
}


template<class Cipher>
Key<Cipher> KeySerializer<Cipher>::unserialize(const Json::Value &json) const
{
    std::vector<PublicKey> spendPubs;
    std::vector<SecuredPrivateKey<Cipher> > spendSecrets;

    unserializeSpendKeys(json["spend"], spendSecrets, spendPubs);

    PrivateKey scanSecret = Literal<PrivateKey>(json["scan"].asString());
    PublicKey scanPub = _pubFactory.createFromSecret(scanSecret);

    return Key<Cipher>(scanSecret, scanPub, spendSecrets, spendPubs);
}


template<class Cipher>
void KeySerializer<Cipher>::unserializeSpendKeys(const Json::Value &json, std::vector<SecuredPrivateKey<Cipher> > &secrets, std::vector<PublicKey> &pubs) const
{
    Json::FastWriter writer;
    for(Json::ValueConstIterator it = json.begin(), end = json.end(); it!=end; ++it)
    {
        const Json::Value & val = *it;
        secrets.push_back(_secretSerializer.unserialize(val["secret"]));
        pubs.push_back(_pubSerializer.unserialize(val["pub"].asString()));
    }
}


template<class Cipher>
Key<Cipher> KeySerializer<Cipher>::unserialize(const std::string &serialized) const
{
    Json::Reader reader;
    Json::Value json;
    if(!reader.parse(serialized, json))
    {
        throw std::runtime_error("invalid json");
    }

    return unserialize(json);
}


}}
