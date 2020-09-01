// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <data/math/number/gmp/N.hpp>
#include <data/encoding/digits.hpp>

namespace data::math::number::gmp {
    
    Z Z_read_N_gmp(string_view s) {
        Z z{};
        //std::cout << "    Z_read_N_gmp: " << s << std::endl;
        mpz_init(z.MPZ);
        mpz_set_str(z.MPZ, std::string{s}.c_str(), 0);
        return z;
    }
    
    Z Z_read_N_data(string_view x) {
        if (encoding::decimal::valid(x)) {
            string s{x};
            return Z_read_N_gmp(s);
        } 
        
        if (encoding::hexidecimal::valid(x)) {
            if (encoding::hexidecimal::zero(x)) return Z{0};
            int first_nonzero_index = 2;
            while (true) {
                if (first_nonzero_index == x.size()) return Z{0};
                if (x[first_nonzero_index] != '0') break;
                first_nonzero_index++;
            }
            std::stringstream ss;
            ss << "0x";
            ss << x.substr(first_nonzero_index);
            return Z_read_N_gmp(ss.str());
        }
        
        return Z{}; // shouldn't really happen;
    }
    
    Z Z_read_hex_positive(string_view x) {
        int first_nonzero_index = 2;
        while (true) {
            if (first_nonzero_index == x.size()) return Z{0};
            if (x[first_nonzero_index] != '0') break;
            first_nonzero_index++;
        }
        std::stringstream ss;
        ss << "0x";
        ss << x.substr(first_nonzero_index); 
        return Z_read_N_gmp(ss.str());
    }
    
    Z Z_read_hex(string_view x) {
        //std::cout << "  reading in Z with hexidecimal representation " << x << std::endl;
        if (encoding::hexidecimal::zero(x)) return Z{0};
        //std::cout << "  representation is nonzero. " << std::endl;
        if (encoding::integer::negative(x)) {
        //std::cout << "  representation is negative. " << std::endl;
            std::stringstream ss;
            ss << "0x01";
            for (int i = 0; i < x.size() - 2; i += 2) ss << "00";
            //std::cout << "  returning " << Z{N{x}} << " minus " << std::endl;
            return Z_read_hex_positive(x) - Z_read_hex_positive(ss.str());
        };
        return Z_read_hex_positive(x);
    }
    
    Z Z::read(string_view s) {
        //std::cout << "  reading in Z with representation " << s << std::endl;
        if (!encoding::integer::valid(s)) return Z{};
        //std::cout << "  representation is valid " << s << std::endl;
        if (encoding::hexidecimal::valid(s)) return Z_read_hex(s);
        //std::cout << "  representation is not hexidecimal " << s << std::endl;
        return encoding::integer::negative(s) ? -Z_read_N_gmp(s.substr(1)) : Z_read_N_gmp(s);
    }
    
    std::ostream& Z_write_dec(std::ostream& o, const Z& n) {
        if (n == 0) return o << "0";
        if (n < 0) return Z_write_dec(o << "-", -n);
        return o << encoding::write_base<N<Z>>(abs<Z>{}(n), encoding::decimal::characters());
    }
    
    std::ostream& Z_write_hexidecimal(std::ostream& o, const Z& z) {
        if (z == 0) return o << "0x00";
        std::string str;
        char fill;
        o << "0x";
        if (z > 0) {
            fill = '0';
            str = encoding::write_base<N<Z>>(abs<Z>{}(z), encoding::hex::characters_lower());
            if (str[0] > '7') o << "00";
        } else { 
            fill = 'f';
            N<Z> n = abs<Z>{}(z); 
            N<Z> pow = 1;
            
            // find the smallest power of 256 bigger than z. 
            while (pow <= n) pow = pow << 8; 
        
            str = encoding::write_base<N>(data::abs<Z>(pow.Value + z), encoding::hex::characters_lower());
            if (str[0] <= '7') o << "ff";
        } 
        if (str.size() % 2 != 0) o << fill;
        return o << str;
    }
    
}

namespace data::encoding::hexidecimal {
    
    std::string write(const math::number::gmp::Z& n) {
        std::stringstream ss;
        ss << std::hex << n;
        return ss.str();
    }
    
}

namespace data::encoding::integer {
    
    std::string write(const math::number::gmp::Z& n) {
        std::stringstream ss;
        ss << std::dec << n;
        return ss.str();
    }
    
}


namespace data::math::number::gmp {
        
    std::ostream& operator<<(std::ostream& o, const Z& n) {
        if (o.flags() & std::ios::hex) {
            Z_write_hexidecimal(o, n);
            return o;
        }
        if (o.flags() & std::ios::dec) {
            return Z_write_dec(o, n);
        }
        o << &n.MPZ;
        return o;
    }
    
    Z N_read_hex(string_view x) {
        if (encoding::hexidecimal::zero(x)) return Z{0};
        return Z_read_hex_positive(x);
    }
    
    Z N_read(string_view x) {
        if (!encoding::integer::valid(x)) return Z{};
        if (encoding::hexidecimal::valid(x)) return N_read_hex(x);
        if (encoding::integer::negative(x)) return Z{};
        return Z_read_N_gmp(x);
    }
        
    Z::operator int64() const {
        if (operator>(std::numeric_limits<int64>::max())) throw std::logic_error{"too big"};
        if (operator<(std::numeric_limits<int64>::min())) throw std::logic_error{"too big"};
        return mpz_get_si(MPZ);
    } 
    
    Z::operator uint64() const {
        if (__gmp_binary_greater::eval(MPZ, (unsigned long int)(std::numeric_limits<uint64>::max())))
            throw std::logic_error{"too big"};
        if (operator<(0)) throw std::logic_error{"too big"};
        return mpz_get_ui(MPZ);
    } 

}
