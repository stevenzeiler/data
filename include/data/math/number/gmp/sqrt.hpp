// Copyright (c) 2020 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DATA_MATH_NUMBER_GMP_SQRT
#define DATA_MATH_NUMBER_GMP_SQRT

#include <data/math/number/gmp/Z.hpp>
#include <data/math/number/sqrt.hpp>
#include <data/math/complex.hpp>
#include <data/math/number/integer.hpp>

namespace data::math::number::gmp {
        
    Z sqrt(const Z& n);
    Z root(const Z& n, uint32 p);
    
    Z inline Z::sqrt() const {
        return gmp::sqrt(*this);
    }
        
    Z inline sqrt(const Z& n) {
        return root(n, 2);
    }

}

namespace data::math {
    
    template <> struct sqrt<N<number::gmp::Z>, N<number::gmp::Z>> {
        N<number::gmp::Z> operator()(const N<number::gmp::Z> &n) const {
            return n.sqrt();
        }
    };
    
    template <> struct sqrt<N<number::gmp::Z>, number::gmp::Z> {
        N<number::gmp::Z> operator()(const number::gmp::Z &n) const {
            if (n < 0) return N<number::gmp::Z>{number::gmp::Z{}};
            return sqrt<N<number::gmp::Z>, N<number::gmp::Z>>{}(N<number::gmp::Z>{n});
        }
    };
    
    template <> struct sqrt<number::gmp::Z, number::gmp::Z> {
        number::gmp::Z operator()(const number::gmp::Z &z) const {
            N<number::gmp::Z> n = sqrt<N<number::gmp::Z>, number::gmp::Z>{}(z);
            if (n.valid()) return N<number::gmp::Z>{number::gmp::Z{}};
            return n.Value;
        }
    };

}

#endif
