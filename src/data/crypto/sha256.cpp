#include <data/crypto/sha256.hpp>
#include <crypto++/sha.h>

namespace data::sha256 {
    digest hash(bytes& data) {
        digest hash;
        CryptoPP::SHA256 shaHash;
        shaHash.CalculateDigest(hash.data(),data.data(),data.size());
        return hash;
    }
    
    template <uint32 n>
    digest hash(const array<byte, n>& data) {
        digest hash;
        CryptoPP::SHA256 shaHash;
        shaHash.CalculateDigest(hash.data(), data.data(), data.size());
        return hash;
    };

}
