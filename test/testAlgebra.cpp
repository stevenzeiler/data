// Copyright (c) 2020 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <data/data.hpp>
#include "gtest/gtest.h"

namespace data {
    
    // TODO prove that complex is linear over R. 
     
    // TODO prove that quaternions are linear over R. 
     
    // TODO prove that octonions are linear over R. 
    
    template <typename X>
    requires math::ring<X>
    void is_ring() {}
    
    // test that the Gaussian integers etc are rings. 

    template <typename X>
    requires math::number::rational<X>
    void is_rational() {}

    template <typename X>
    requires math::number::normed_division_algebra<X>
    void is_normed_division_algebra() {}
    
    TEST(AlgebraTest, TestIsRational) {
        is_rational<Q>();
    }
    
    // test that the complex rationals, quaternions, and octonions are normed division algebras. 
    
    template <typename X>
    requires math::group<X>
    void is_group() {}
    
    // symmetric and alternating groups. 
    
    template <typename X>
    requires math::field<X>
    void is_field() {}
    
    // test that the complex rationals are a field. 
    
    // finite fields. 
    
    // polynomial rings and fields
}
