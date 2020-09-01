
#include <data/math/number/gmp/sqrt.hpp>

namespace data::math::number::gmp {
    
    Z root(const Z& n, uint32 p) {
        if (p == 0 || n < 0) return Z{};
        if (p == 1 || n == Z{0} || n == Z{1}) return n;
        Z p_root{};
        if (0 == mpz_root(p_root.MPZ, n.MPZ, p)) return Z{};
        return p_root;
    }

}


