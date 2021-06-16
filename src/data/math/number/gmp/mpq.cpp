// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <gmp/gmpxx.h>
#include <data/math/number/gmp/mpq.hpp>

namespace data {
    
    namespace math {
    
        namespace number {
            
            namespace gmp {
                bool mpq::operator==(const mpq&& n) const {
                    return __gmp_binary_equal::eval(&MPQ, &n.MPQ);
                }
                
                bool mpq::operator<(const mpq&& n) const {
                    return __gmp_binary_less::eval(&MPQ, &n.MPQ);
                }
                
                bool mpq::operator>(const mpq&& n) const {
                    return __gmp_binary_greater::eval(&MPQ, &n.MPQ);
                }
                
                bool mpq::operator<=(const mpq&& n) const {
                    return !__gmp_binary_greater::eval(&MPQ, &n.MPQ);
                }
                
                bool mpq::operator>=(const mpq&& n) const {
                    return !__gmp_binary_less::eval(&MPQ, &n.MPQ);
                }

            }
            
        }
    
    }

}
