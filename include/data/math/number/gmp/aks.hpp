// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DATA_MATH_NUMBER_GMP_AKS
#define DATA_MATH_NUMBER_GMP_AKS

#include <data/math/number/prime.hpp>
#include <data/math/number/integer.hpp>
#include <data/math/number/gmp/Z.hpp>

namespace data::math::number::gmp {
    
    bool aks_is_prime(const Z);
    
}

namespace data::math::number {
    
    template <> struct AKS<N<gmp::Z>> {
        prime<N<gmp::Z>> is_prime(const N<gmp::Z> n) {
            return gmp::aks_is_prime(n.Value) ? prime<N<gmp::Z>>{n, prime<N<gmp::Z>>::certain} : prime<N<gmp::Z>>{};
        }
    };
    
    template <> struct AKS<gmp::Z> {
        prime<gmp::Z> is_prime(const gmp::Z z) {
            return gmp::aks_is_prime(z) ? prime<gmp::Z>{z, prime<gmp::Z>::certain} : prime<gmp::Z>{};
        }
    };
    
    template struct AKS<N<gmp::Z>>;
    template struct AKS<gmp::Z>;
    
}

#endif

