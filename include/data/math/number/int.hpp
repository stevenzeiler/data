// Copyright (c) 2020 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DATA_MATH_NUMBER_INT
#define DATA_MATH_NUMBER_INT

#include <type_traits>
#include <data/math/ordered.hpp>

namespace data::math::number {
    
    template <typename n>
    concept uint = 
        std::totally_ordered<n> && requires (const n& x) {
            { ~x } -> std::same_as<n>;
        } && requires (n& x) {
            { ++x } -> std::same_as<n&>;
            { --x } -> std::same_as<n&>;
        } && requires (const n& x, const n& y) {
            { x + y } -> std::same_as<n>;
            { x - y } -> std::same_as<n>;
            { x * y } -> std::same_as<n>;
            { x / y } -> std::same_as<n>;
            { x % y } -> std::same_as<n>;
        } && requires (n& x, const n& y) {
            { x += y } -> std::same_as<n&>;
            { x -= y } -> std::same_as<n&>;
            { x *= y } -> std::same_as<n&>;
            { x ^= y } -> std::same_as<n&>;
            { x |= y } -> std::same_as<n&>;
            { x /= y } -> std::same_as<n&>;
            { x %= y } -> std::same_as<n&>;
        } && requires (const n& x, const uint32& b) {
            { x << b } -> std::same_as<n>;
            { x >> b } -> std::same_as<n>;
        } && requires (n& x, const uint32& b) {
            { x <<= b } -> std::same_as<n>;
            { x >>= b } -> std::same_as<n>;
        };
    
    template <typename z>
    concept sint = 
        uint<z> && requires (const z& x) {
            { -x } -> std::same_as<z>;
        };
}

// define post-increment in terms of pre-increment
template <data::math::number::uint n>
inline n operator++(n& x, int) {
    auto y = x;
    ++x;
    return y;
}

template <data::math::number::uint n>
inline n operator--(n& x, int) {
    auto y = x;
    ++x;
    return y;
}

template <data::math::number::uint n>
inline n operator^(const n& a, const n& b) {
    n x = a;
    x ^= b;
    return x;
}

template <data::math::number::uint n>
inline n operator|(const n& a, const n& b) {
    n x = a;
    x |= b;
    return x;
}

#endif
