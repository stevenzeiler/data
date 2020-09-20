// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "data/math/number/abs.hpp"
#include "data/math/number/bounded.hpp"
#include "data/data.hpp"
#include "gtest/gtest.h"

namespace data::math {
    
    TEST(SignTest, TestDecrement) {
        EXPECT_EQ(    sint_big<9>{0}--,     sint_big<9>{"0xffffffffffffffffff"});
        EXPECT_EQ(   sint_big<10>{0}--,    sint_big<10>{"0xffffffffffffffffffff"});
        EXPECT_EQ(   sint_big<11>{0}--,    sint_big<11>{"0xffffffffffffffffffffff"});
        EXPECT_EQ(   sint_big<20>{0}--,    sint_big<20>{"0xffffffffffffffffffffffffffffffffffffffff"});
        EXPECT_EQ( sint_little<9>{0}--,  sint_little<9>{"0xffffffffffffffffff"});
        EXPECT_EQ(sint_little<10>{0}--, sint_little<10>{"0xffffffffffffffffffff"});
        EXPECT_EQ(sint_little<11>{0}--, sint_little<11>{"0xffffffffffffffffffffff"});
        EXPECT_EQ(sint_little<20>{0}--, sint_little<20>{"0xffffffffffffffffffffffffffffffffffffffff"});
        
        EXPECT_LT(sint_big<9>{"0x800000000000000000"}, 
                  sint_big<9>{"0x7fffffffffffffffff"});
        EXPECT_LT(sint_big<10>{"0x80000000000000000000"}, 
                  sint_big<10>{"0x7fffffffffffffffffff"});
        EXPECT_LT(sint_big<11>{"0x8000000000000000000000"}, 
                  sint_big<11>{"0x7fffffffffffffffffffff"});
        EXPECT_LT(sint_big<20>{"0x8000000000000000000000000000000000000000"},
                  sint_big<20>{"0x7fffffffffffffffffffffffffffffffffffffff"});
        EXPECT_LT(sint_little<9>{"0x800000000000000000"}, 
                  sint_little<9>{"0x7fffffffffffffffff"});
        EXPECT_LT(sint_little<10>{"0x80000000000000000000"}, 
                  sint_little<10>{"0x7fffffffffffffffffff"});
        EXPECT_LT(sint_little<11>{"0x8000000000000000000000"}, 
                  sint_little<11>{"0x7fffffffffffffffffffff"});
        EXPECT_LT(sint_little<20>{"0x8000000000000000000000000000000000000000"}, 
                  sint_little<20>{"0x7fffffffffffffffffffffffffffffffffffffff"});
    }
    
    TEST(SignTest, TestSign) {
        number::sign<int64> s_i;
        number::sign<sint_big<9>> s_b09;
        number::sign<sint_big<10>> s_b10;
        number::sign<sint_big<11>> s_b11;
        number::sign<sint_big<20>> s_b20;
        number::sign<sint_little<9>> s_l09;
        number::sign<sint_little<10>> s_l10;
        number::sign<sint_little<11>> s_l11;
        number::sign<sint_little<20>> s_l20;
        number::sign<Z> s_z;
        number::sign<Z_bytes<endian::order::little>> s_zbl;
        number::sign<Z_bytes<endian::order::big>> s_zbb;
        
        number::sign<uint64> s_u;
        number::sign<uint_big<9>> s_ub09;
        number::sign<uint_big<10>> s_ub10;
        number::sign<uint_big<11>> s_ub11;
        number::sign<uint_big<20>> s_ub20;
        number::sign<uint_little<9>> s_ul09;
        number::sign<uint_little<10>> s_ul10;
        number::sign<uint_little<11>> s_ul11;
        number::sign<uint_little<20>> s_ul20;
        number::sign<N> s_n;
        number::sign<N_bytes<endian::order::little>> s_nbl;
        number::sign<N_bytes<endian::order::big>> s_nbb;
        
        EXPECT_EQ(s_i(0),    zero);
        EXPECT_EQ(s_z(0),    zero);
        EXPECT_EQ(s_zbl(0),  zero);
        EXPECT_EQ(s_zbb(0),  zero);
        EXPECT_EQ(s_b09(0),  zero);
        EXPECT_EQ(s_b10(0),  zero);
        EXPECT_EQ(s_b11(0),  zero);
        EXPECT_EQ(s_b20(0),  zero);
        EXPECT_EQ(s_l09(0),  zero);
        EXPECT_EQ(s_l10(0),  zero);
        EXPECT_EQ(s_l11(0),  zero);
        EXPECT_EQ(s_l20(0),  zero);
        
        EXPECT_EQ(s_u(0),    zero);
        EXPECT_EQ(s_n(0),    zero);
        EXPECT_EQ(s_nbl(0),  zero);
        EXPECT_EQ(s_nbb(0),  zero);
        EXPECT_EQ(s_ub09(0), zero);
        EXPECT_EQ(s_ub10(0), zero);
        EXPECT_EQ(s_ub11(0), zero);
        EXPECT_EQ(s_ub20(0), zero);
        EXPECT_EQ(s_ul09(0), zero);
        EXPECT_EQ(s_ul10(0), zero);
        EXPECT_EQ(s_ul11(0), zero);
        EXPECT_EQ(s_ul20(0), zero);
        
        EXPECT_EQ(s_i(1),    positive);
        EXPECT_EQ(s_z(1),    positive);
        EXPECT_EQ(s_zbl(1),  positive);
        EXPECT_EQ(s_zbb(1),  positive);
        EXPECT_EQ(s_b20(1),  positive);
        EXPECT_EQ(s_b11(1),  positive);
        EXPECT_EQ(s_b10(1),  positive);
        EXPECT_EQ(s_b09(1),  positive);
        EXPECT_EQ(s_l20(1),  positive);
        EXPECT_EQ(s_l11(1),  positive);
        EXPECT_EQ(s_l10(1),  positive);
        EXPECT_EQ(s_l09(1),  positive);
        
        EXPECT_EQ(s_u(1),    positive);
        EXPECT_EQ(s_n(1),    positive);
        EXPECT_EQ(s_nbl(1),  positive);
        EXPECT_EQ(s_nbb(1),  positive);
        EXPECT_EQ(s_ub09(1), positive);
        EXPECT_EQ(s_ub10(1), positive);
        EXPECT_EQ(s_ub11(1), positive);
        EXPECT_EQ(s_ub20(1), positive);
        EXPECT_EQ(s_ul09(1), positive);
        EXPECT_EQ(s_ul10(1), positive);
        EXPECT_EQ(s_ul11(1), positive);
        EXPECT_EQ(s_ul20(1), positive);
        
        EXPECT_EQ(s_i(-1),   negative);
        EXPECT_EQ(s_z(-1),   negative);
        EXPECT_EQ(s_zbl(-1), negative);
        EXPECT_EQ(s_zbb(-1), negative);
        EXPECT_EQ(s_b09(-1), negative);
        EXPECT_EQ(s_b10(-1), negative);
        EXPECT_EQ(s_b11(-1), negative);
        EXPECT_EQ(s_b20(-1), negative);
        EXPECT_EQ(s_l09(-1), negative);
        EXPECT_EQ(s_l10(-1), negative);
        EXPECT_EQ(s_l11(-1), negative);
        EXPECT_EQ(s_l20(-1), negative);
        
        EXPECT_EQ(s_i(2),    positive);
        EXPECT_EQ(s_z(2),    positive);
        EXPECT_EQ(s_zbl(2),  positive);
        EXPECT_EQ(s_zbb(2),  positive);
        EXPECT_EQ(s_b09(2),  positive);
        EXPECT_EQ(s_b10(2),  positive);
        EXPECT_EQ(s_b11(2),  positive);
        EXPECT_EQ(s_b20(2),  positive);
        EXPECT_EQ(s_l09(2),  positive);
        EXPECT_EQ(s_l10(2),  positive);
        EXPECT_EQ(s_l11(2),  positive);
        EXPECT_EQ(s_l20(2),  positive);
        
        EXPECT_EQ(s_u(2),    positive);
        EXPECT_EQ(s_n(2),    positive);
        EXPECT_EQ(s_nbl(2),  positive);
        EXPECT_EQ(s_nbb(2),  positive);
        EXPECT_EQ(s_ub09(2), positive);
        EXPECT_EQ(s_ub10(2), positive);
        EXPECT_EQ(s_ub11(2), positive);
        EXPECT_EQ(s_ub20(2), positive);
        EXPECT_EQ(s_ul09(2), positive);
        EXPECT_EQ(s_ul10(2), positive);
        EXPECT_EQ(s_ul11(2), positive);
        EXPECT_EQ(s_ul20(2), positive);
        
        EXPECT_EQ(s_i(-2),   negative);
        EXPECT_EQ(s_z(-2),   negative);
        EXPECT_EQ(s_zbl(-2), negative);
        EXPECT_EQ(s_zbb(-2), negative);
        EXPECT_EQ(s_b09(-2), negative);
        EXPECT_EQ(s_b10(-2), negative);
        EXPECT_EQ(s_b11(-2), negative);
        EXPECT_EQ(s_b20(-2), negative);
        EXPECT_EQ(s_l09(-2), negative);
        EXPECT_EQ(s_l10(-2), negative);
        EXPECT_EQ(s_l11(-2), negative);
        EXPECT_EQ(s_l20(-2), negative);
        
        EXPECT_EQ(s_i(7076852110923542),    positive);
        EXPECT_EQ(s_z(7076852110923542),    positive);
        EXPECT_EQ(s_zbl(7076852110923542),  positive);
        EXPECT_EQ(s_zbb(7076852110923542),  positive);
        EXPECT_EQ(s_b09(7076852110923542),  positive);
        EXPECT_EQ(s_b10(7076852110923542),  positive);
        EXPECT_EQ(s_b11(7076852110923542),  positive);
        EXPECT_EQ(s_b20(7076852110923542),  positive);
        EXPECT_EQ(s_b09(7076852110923542),  positive);
        EXPECT_EQ(s_b10(7076852110923542),  positive);
        EXPECT_EQ(s_b11(7076852110923542),  positive);
        EXPECT_EQ(s_b20(7076852110923542),  positive);
        
        EXPECT_EQ(s_u(7076852110923542),    positive);
        EXPECT_EQ(s_n(7076852110923542),    positive);
        EXPECT_EQ(s_nbl(7076852110923542),  positive);
        EXPECT_EQ(s_nbb(7076852110923542),  positive);
        EXPECT_EQ(s_ub09(7076852110923542), positive);
        EXPECT_EQ(s_ub10(7076852110923542), positive);
        EXPECT_EQ(s_ub11(7076852110923542), positive);
        EXPECT_EQ(s_ub20(7076852110923542), positive);
        EXPECT_EQ(s_ul09(7076852110923542), positive);
        EXPECT_EQ(s_ul10(7076852110923542), positive);
        EXPECT_EQ(s_ul11(7076852110923542), positive);
        EXPECT_EQ(s_ul20(7076852110923542), positive);
        
        EXPECT_EQ(s_i(-7076852110923542),   negative);
        EXPECT_EQ(s_z(-7076852110923542),   negative);
        EXPECT_EQ(s_zbl(-7076852110923542), negative);
        EXPECT_EQ(s_zbb(-7076852110923542), negative);
        EXPECT_EQ(s_b09(-7076852110923542), negative);
        EXPECT_EQ(s_b10(-7076852110923542), negative);
        EXPECT_EQ(s_b11(-7076852110923542), negative);
        EXPECT_EQ(s_b20(-7076852110923542), negative);
        EXPECT_EQ(s_l09(-7076852110923542), negative);
        EXPECT_EQ(s_l10(-7076852110923542), negative);
        EXPECT_EQ(s_l11(-7076852110923542), negative);
        EXPECT_EQ(s_l20(-7076852110923542), negative);
        
    }
    /*
    TEST(SignTest, TestAbs) {
        
        number::abs<uint64, int64> abs_i{};
        number::abs<uint_big<20>, sint_big<20>> abs_b20{};
        number::abs<uint_big<9>, sint_big<9>> abs_b09{};
        number::abs<uint_big<10>, sint_big<10>> abs_b10{};
        number::abs<uint_big<11>, sint_big<11>> abs_b11{};
        
        number::abs<number::bounded<false, endian::little, 20>, 
            number::bounded<true, endian::little, 20>> abs_l20{};
        number::abs<number::bounded<false, endian::little, 9>, 
            number::bounded<true, endian::little, 9>> abs_l09{};
        number::abs<number::bounded<false, endian::little, 10>, 
            number::bounded<true, endian::little, 10>> abs_l10{};
        number::abs<number::bounded<false, endian::little, 11>, 
            number::bounded<true, endian::little, 11>> abs_l11{};
            
        number::abs<N, Z> abs_z{};
        number::abs<N_bytes<endian::little>, Z_bytes<endian::little>> abs_zbl{};
        number::abs<N_bytes<endian::big>, Z_bytes<endian::big>> abs_zbb{};
        
        EXPECT_EQ(abs_i(0), 0);
        EXPECT_EQ(abs_z(0), 0);
        EXPECT_EQ(abs_zbl(0), 0);
        EXPECT_EQ(abs_zbb(0), 0);
        EXPECT_EQ(abs_b09(0), 0);
        EXPECT_EQ(abs_b10(0), 0);
        EXPECT_EQ(abs_b11(0), 0);
        EXPECT_EQ(abs_b20(0), 0);
        EXPECT_EQ(abs_l09(0), 0);
        EXPECT_EQ(abs_l10(0), 0);
        EXPECT_EQ(abs_l11(0), 0);
        EXPECT_EQ(abs_l20(0), 0);
        
        EXPECT_EQ(abs_i(1), 1);
        EXPECT_EQ(abs_z(1), 1);
        EXPECT_EQ(abs_zbl(1), 1);
        EXPECT_EQ(abs_zbb(1), 1);
        EXPECT_EQ(abs_b09(1), 1);
        EXPECT_EQ(abs_b10(1), 1);
        EXPECT_EQ(abs_b11(1), 1);
        EXPECT_EQ(abs_b20(1), 1);
        EXPECT_EQ(abs_l09(1), 1);
        EXPECT_EQ(abs_l10(1), 1);
        EXPECT_EQ(abs_l11(1), 1);
        EXPECT_EQ(abs_l20(1), 1);
        
        EXPECT_EQ(abs_i(-1), 1);
        EXPECT_EQ(abs_z(-1), 1);
        EXPECT_EQ(abs_zbl(-1), 1);
        EXPECT_EQ(abs_zbb(-1), 1);
        EXPECT_EQ(abs_b09(-1), 1);
        EXPECT_EQ(abs_b10(-1), 1);
        EXPECT_EQ(abs_b11(-1), 1);
        EXPECT_EQ(abs_b20(-1), 1);
        EXPECT_EQ(abs_l09(-1), 1);
        EXPECT_EQ(abs_l10(-1), 1);
        EXPECT_EQ(abs_l11(-1), 1);
        EXPECT_EQ(abs_l20(-1), 1);
        
        EXPECT_EQ(abs_i(7076852110923542), 7076852110923542);
        EXPECT_EQ(abs_z(7076852110923542), 7076852110923542);
        EXPECT_EQ(abs_zbl(7076852110923542), 7076852110923542);
        EXPECT_EQ(abs_zbb(7076852110923542), 7076852110923542);
        EXPECT_EQ(abs_b09(7076852110923542), 7076852110923542);
        EXPECT_EQ(abs_b10(7076852110923542), 7076852110923542);
        EXPECT_EQ(abs_b11(7076852110923542), 7076852110923542);
        EXPECT_EQ(abs_b20(7076852110923542), 7076852110923542);
        EXPECT_EQ(abs_l09(7076852110923542), 7076852110923542);
        EXPECT_EQ(abs_l10(7076852110923542), 7076852110923542);
        EXPECT_EQ(abs_l11(7076852110923542), 7076852110923542);
        EXPECT_EQ(abs_l20(7076852110923542), 7076852110923542);
        
        EXPECT_EQ(abs_i(-7076852110923542), 7076852110923542);
        EXPECT_EQ(abs_z(-7076852110923542), 7076852110923542);
        EXPECT_EQ(abs_zbl(-7076852110923542), 7076852110923542);
        EXPECT_EQ(abs_zbb(-7076852110923542), 7076852110923542);
        EXPECT_EQ(abs_b09(-7076852110923542), 7076852110923542);
        EXPECT_EQ(abs_b10(-7076852110923542), 7076852110923542);
        EXPECT_EQ(abs_b11(-7076852110923542), 7076852110923542);
        EXPECT_EQ(abs_b20(-7076852110923542), 7076852110923542);
        EXPECT_EQ(abs_l09(-7076852110923542), 7076852110923542);
        EXPECT_EQ(abs_l10(-7076852110923542), 7076852110923542);
        EXPECT_EQ(abs_l11(-7076852110923542), 7076852110923542);
        EXPECT_EQ(abs_l20(-7076852110923542), 7076852110923542);
        
    }*/
    /*
    TEST(SignTest, TestArg) {
        
        arg<int64> arg_i{};
        arg<integer<9>> arg_b09{};
        arg<integer<10>> arg_b10{};
        arg<integer<11>> arg_b11{};
        arg<integer<20>> arg_b20{};
        arg<number::bounded<9, endian::little, true>> arg_l09{};
        arg<number::bounded<10, endian::little, true>> arg_l10{};
        arg<number::bounded<11, endian::little, true>> arg_l11{};
        arg<number::bounded<20, endian::little, true>> arg_l20{};
        arg<Z> arg_z{};
        arg<Z_bytes<endian::order::little>> arg_zbl{};
        arg<Z_bytes<endian::order::big>> arg_zbb{};
        
        EXPECT_THROW(arg_i(0),   division_by_zero);
        EXPECT_THROW(arg_z(0),   division_by_zero);
        EXPECT_THROW(arg_zbl(0), division_by_zero);
        EXPECT_THROW(arg_zbb(0), division_by_zero);
        EXPECT_THROW(arg_b09(0), division_by_zero);
        EXPECT_THROW(arg_b10(0), division_by_zero);
        EXPECT_THROW(arg_b11(0), division_by_zero);
        EXPECT_THROW(arg_b20(0), division_by_zero);
        EXPECT_THROW(arg_l09(0), division_by_zero);
        EXPECT_THROW(arg_l10(0), division_by_zero);
        EXPECT_THROW(arg_l11(0), division_by_zero);
        EXPECT_THROW(arg_l20(0), division_by_zero);
        
        EXPECT_EQ(arg_i(1),   1);
        EXPECT_EQ(arg_z(1),   1);
        EXPECT_EQ(arg_zbl(1), 1);
        EXPECT_EQ(arg_zbb(1), 1);
        EXPECT_EQ(arg_b20(1), 1);
        EXPECT_EQ(arg_b11(1), 1);
        EXPECT_EQ(arg_b10(1), 1);
        EXPECT_EQ(arg_b09(1), 1);
        EXPECT_EQ(arg_l20(1), 1);
        EXPECT_EQ(arg_l11(1), 1);
        EXPECT_EQ(arg_l10(1), 1);
        EXPECT_EQ(arg_l09(1), 1);
        
        EXPECT_EQ(arg_i(-1),   -1);
        EXPECT_EQ(arg_z(-1),   -1);
        EXPECT_EQ(arg_zbl(-1), -1);
        EXPECT_EQ(arg_zbb(-1), -1);
        EXPECT_EQ(arg_b20(-1), -1);
        EXPECT_EQ(arg_b11(-1), -1);
        EXPECT_EQ(arg_b10(-1), -1);
        EXPECT_EQ(arg_b09(-1), -1);
        EXPECT_EQ(arg_l20(-1), -1);
        EXPECT_EQ(arg_l11(-1), -1);
        EXPECT_EQ(arg_l10(-1), -1);
        EXPECT_EQ(arg_l09(-1), -1);
        
        EXPECT_EQ(arg_i(2),   1);
        EXPECT_EQ(arg_z(2),   1);
        EXPECT_EQ(arg_zbl(2), 1);
        EXPECT_EQ(arg_zbb(2), 1);
        EXPECT_EQ(arg_b20(2), 1);
        EXPECT_EQ(arg_b11(2), 1);
        EXPECT_EQ(arg_b10(2), 1);
        EXPECT_EQ(arg_b09(2), 1);
        EXPECT_EQ(arg_l20(2), 1);
        EXPECT_EQ(arg_l11(2), 1);
        EXPECT_EQ(arg_l10(2), 1);
        EXPECT_EQ(arg_l09(2), 1);
        
        EXPECT_EQ(arg_i(-2),   -1);
        EXPECT_EQ(arg_z(-2),   -1);
        EXPECT_EQ(arg_zbl(-2), -1);
        EXPECT_EQ(arg_zbb(-2), -1);
        EXPECT_EQ(arg_b20(-2), -1);
        EXPECT_EQ(arg_b11(-2), -1);
        EXPECT_EQ(arg_b10(-2), -1);
        EXPECT_EQ(arg_b09(-2), -1);
        EXPECT_EQ(arg_l20(-2), -1);
        EXPECT_EQ(arg_l11(-2), -1);
        EXPECT_EQ(arg_l10(-2), -1);
        EXPECT_EQ(arg_l09(-2), -1);
        
        EXPECT_EQ(arg_i(7076852110923542),   1);
        EXPECT_EQ(arg_z(7076852110923542),   1);
        EXPECT_EQ(arg_zbl(7076852110923542), 1);
        EXPECT_EQ(arg_zbb(7076852110923542), 1);
        EXPECT_EQ(arg_b20(7076852110923542), 1);
        EXPECT_EQ(arg_b11(7076852110923542), 1);
        EXPECT_EQ(arg_b10(7076852110923542), 1);
        EXPECT_EQ(arg_b09(7076852110923542), 1);
        EXPECT_EQ(arg_l20(7076852110923542), 1);
        EXPECT_EQ(arg_l11(7076852110923542), 1);
        EXPECT_EQ(arg_l10(7076852110923542), 1);
        EXPECT_EQ(arg_l09(7076852110923542), 1);
        
        EXPECT_EQ(arg_i(-7076852110923542),   -1);
        EXPECT_EQ(arg_z(-7076852110923542),   -1);
        EXPECT_EQ(arg_zbl(-7076852110923542), -1);
        EXPECT_EQ(arg_zbb(-7076852110923542), -1);
        EXPECT_EQ(arg_b20(-7076852110923542), -1);
        EXPECT_EQ(arg_b11(-7076852110923542), -1);
        EXPECT_EQ(arg_b10(-7076852110923542), -1);
        EXPECT_EQ(arg_b09(-7076852110923542), -1);
        EXPECT_EQ(arg_l20(-7076852110923542), -1);
        EXPECT_EQ(arg_l11(-7076852110923542), -1);
        EXPECT_EQ(arg_l10(-7076852110923542), -1);
        EXPECT_EQ(arg_l09(-7076852110923542), -1);
        
    }*/
    
    TEST(SignTest, TestMinus) {
        
        EXPECT_EQ(-Z{0}, Z{0});
        EXPECT_EQ(-Z_bytes<endian::big>{0}, Z_bytes<endian::big>{0});
        EXPECT_EQ(-Z_bytes<endian::little>{0}, Z_bytes<endian::little>{0});
        EXPECT_EQ(-sint_big<9>{0}, sint_big<9>{0});
        EXPECT_EQ(-sint_big<10>{0}, sint_big<10>{0});
        EXPECT_EQ(-sint_big<11>{0}, sint_big<11>{0});
        EXPECT_EQ(-sint_big<20>{0}, sint_big<20>{0});
        EXPECT_EQ(-sint_little<9>{0}, sint_little<9>{0});
        EXPECT_EQ(-sint_little<10>{0}, sint_little<10>{0});
        EXPECT_EQ(-sint_little<11>{0}, sint_little<11>{0});
        EXPECT_EQ(-sint_little<20>{0}, sint_little<20>{0});
        
        EXPECT_EQ(-Z{1}, Z{-1});
        EXPECT_EQ(-Z_bytes<endian::big>{1}, Z_bytes<endian::big>{-1});
        EXPECT_EQ(-Z_bytes<endian::little>{1}, Z_bytes<endian::little>{-1});
        EXPECT_EQ(-sint_big<9>{1}, sint_big<9>{-1});
        EXPECT_EQ(-sint_big<10>{1}, sint_big<10>{-1});
        EXPECT_EQ(-sint_big<11>{1}, sint_big<11>{-1});
        EXPECT_EQ(-sint_big<20>{1}, sint_big<20>{-1});
        EXPECT_EQ(-sint_little<9>{1}, sint_little<9>{-1});
        EXPECT_EQ(-sint_little<10>{1}, sint_little<10>{-1});
        EXPECT_EQ(-sint_little<11>{1}, sint_little<11>{-1});
        EXPECT_EQ(-sint_little<20>{1}, sint_little<20>{-1});
        
        EXPECT_EQ(-Z{-1}, Z{1});
        EXPECT_EQ(-Z_bytes<endian::big>{-1}, Z_bytes<endian::big>{1});
        EXPECT_EQ(-Z_bytes<endian::little>{-1}, Z_bytes<endian::little>{1});
        EXPECT_EQ(-sint_big<9>{-1}, sint_big<9>{1});
        EXPECT_EQ(-sint_big<10>{-1}, sint_big<10>{1});
        EXPECT_EQ(-sint_big<11>{-1}, sint_big<11>{1});
        EXPECT_EQ(-sint_big<20>{-1}, sint_big<20>{1});
        EXPECT_EQ(-sint_little<9>{-1}, sint_little<9>{1});
        EXPECT_EQ(-sint_little<10>{-1}, sint_little<10>{1});
        EXPECT_EQ(-sint_little<11>{-1}, sint_little<11>{1});
        EXPECT_EQ(-sint_little<20>{-1}, sint_little<20>{1});
        
        EXPECT_EQ(-Z{2}, Z{-2});
        EXPECT_EQ(-Z_bytes<endian::big>{2}, Z_bytes<endian::big>{-2});
        EXPECT_EQ(-Z_bytes<endian::little>{2}, Z_bytes<endian::little>{-2});
        EXPECT_EQ(-sint_big<9>{2}, sint_big<9>{-2});
        EXPECT_EQ(-sint_big<10>{2}, sint_big<10>{-2});
        EXPECT_EQ(-sint_big<11>{2}, sint_big<11>{-2});
        EXPECT_EQ(-sint_big<20>{2}, sint_big<20>{-2});
        EXPECT_EQ(-sint_little<9>{2}, sint_little<9>{-2});
        EXPECT_EQ(-sint_little<10>{2}, sint_little<10>{-2});
        EXPECT_EQ(-sint_little<11>{2}, sint_little<11>{-2});
        EXPECT_EQ(-sint_little<20>{2}, sint_little<20>{-2});
        
        EXPECT_EQ(-Z{-2}, Z{2});
        EXPECT_EQ(-Z_bytes<endian::big>{-2}, Z_bytes<endian::big>{2});
        EXPECT_EQ(-Z_bytes<endian::little>{-2}, Z_bytes<endian::little>{2});
        EXPECT_EQ(-sint_big<9>{-2}, sint_big<9>{2});
        EXPECT_EQ(-sint_big<10>{-2}, sint_big<10>{2});
        EXPECT_EQ(-sint_big<11>{-2}, sint_big<11>{2});
        EXPECT_EQ(-sint_big<20>{-2}, sint_big<20>{2});
        EXPECT_EQ(-sint_little<9>{-2}, sint_little<9>{2});
        EXPECT_EQ(-sint_little<10>{-2}, sint_little<10>{2});
        EXPECT_EQ(-sint_little<11>{-2}, sint_little<11>{2});
        EXPECT_EQ(-sint_little<20>{-2}, sint_little<20>{2});
        
        EXPECT_EQ(-Z{1}, Z{-1});
        EXPECT_EQ(-Z_bytes<endian::big>{1}, Z_bytes<endian::big>{-1});
        EXPECT_EQ(-Z_bytes<endian::little>{1}, Z_bytes<endian::little>{-1});
        EXPECT_EQ(-sint_big<9>{1}, sint_big<9>{-1});
        EXPECT_EQ(-sint_big<10>{1}, sint_big<10>{-1});
        EXPECT_EQ(-sint_big<11>{1}, sint_big<11>{-1});
        EXPECT_EQ(-sint_big<20>{1}, sint_big<20>{-1});
        EXPECT_EQ(-sint_little<9>{1}, sint_little<9>{-1});
        EXPECT_EQ(-sint_little<10>{1}, sint_little<10>{-1});
        EXPECT_EQ(-sint_little<11>{1}, sint_little<11>{-1});
        EXPECT_EQ(-sint_little<20>{1}, sint_little<20>{-1});
        
        EXPECT_EQ(-Z{-7076852110923542}, Z{7076852110923542});
        EXPECT_EQ(-Z_bytes<endian::big>{-7076852110923542}, Z_bytes<endian::big>{7076852110923542});
        EXPECT_EQ(-Z_bytes<endian::little>{-7076852110923542}, Z_bytes<endian::little>{7076852110923542});
        EXPECT_EQ(-sint_big<9>{-7076852110923542}, sint_big<9>{7076852110923542});
        EXPECT_EQ(-sint_big<10>{-7076852110923542}, sint_big<10>{7076852110923542});
        EXPECT_EQ(-sint_big<11>{-7076852110923542}, sint_big<11>{7076852110923542});
        EXPECT_EQ(-sint_big<20>{-7076852110923542}, sint_big<20>{7076852110923542});
        EXPECT_EQ(-sint_little<9>{-7076852110923542}, sint_little<9>{7076852110923542});
        EXPECT_EQ(-sint_little<10>{-7076852110923542}, sint_little<10>{7076852110923542});
        EXPECT_EQ(-sint_little<11>{-7076852110923542}, sint_little<11>{7076852110923542});
        EXPECT_EQ(-sint_little<20>{-7076852110923542}, sint_little<20>{7076852110923542});
        
    }
}
