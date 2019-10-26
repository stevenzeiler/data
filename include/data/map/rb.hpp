// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DATA_MAP_RB
#define DATA_MAP_RB

#include <data/list/linked.hpp>
#include <data/map.hpp>
#include <data/fold.hpp>
#include <milewski/RBMap/RBMap.h>
#include <data/io/unimplemented.hpp>
    
namespace data {
    
    template <typename K, typename V>
    struct rb_map {
        using entry = map::entry<K, V>;
        using map = milewski::okasaki::RBMap<K, V>;
    private:
        map Map;
        constexpr static const data::map::definition::countable<rb_map, K, V, list::linked<entry>> require_is_map{};
        
        rb_map(map m) : Map{m} {}
        
    public:
        V operator[](K k) const {
            return Map.findWithDefault(V{}, k);
        }
        
        rb_map insert(K k, V v) const {
            return Map.inserted(k, v);
        }
        
        rb_map operator+(entry e) {
            return Map.inserted(e.Key, e.Value);
        }
        
        bool contains(K k) const {
            return Map.member(k);
        }
        
        bool empty() const {
            return Map.isEmpty();
        }
        
        rb_map() : Map{} {}
        rb_map(std::initializer_list<std::pair<K, V>> init);
        
        list::linked<entry> entries() const;
        
        list::linked<K> keys() const {
            throw method::unimplemented{};
        }
        
        list::linked<V> values() const {
            throw method::unimplemented{};
        }
        
        bool valid() const;
        
    };
    
    template <typename K, typename V>
    inline rb_map<K, V> insert_rb_map(rb_map<K, V> m, map::entry<K, V> e) {
        m.insert(e);
    }
    
    template <typename K, typename V>
    inline rb_map<K, V>::rb_map(std::initializer_list<std::pair<K, V> > init)
        : Map{reduce(insert_rb_map<K, V>, make_iterator_list(init))} {}
    
}

#endif
