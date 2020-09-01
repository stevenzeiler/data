// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DATA_MATH_ALGEBRA
#define DATA_MATH_ALGEBRA

#include <data/math/field.hpp>

namespace data::math {
    template <typename V, typename F>
    concept vector = group<V, plus<V>> && field<F> && multiplicative<V, V, F>;
    
    template <typename V, typename F>
    concept algebra = ring<V, plus<V>, times<V>> && field<F> && multiplicative<V, V, F>;
    
}

#endif
