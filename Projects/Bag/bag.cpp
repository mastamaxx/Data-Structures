/*
 
 Mark Max 2016/09/25
 Assignment 2: bag.cpp
 CIS 279 with Geri Lamble
 
 Developed in Xcode 7.3.1
 
 CLASS IMPLEMENTED: bag (see bag.hpp for documentation)
 INVARIANT for the bag class:
    1. The number of items in the bag is in the member variable used.
    2. For an empty bag, we do not care what is stored in any of data; for a
       non-empty bag, the items in the bag are stored in data[0] through
       data[used-1], and we don't care what's in the rest of data.
 */

#include <algorithm>
#include <cassert>
#include "bag.hpp"

using namespace std;

namespace MARK_MAX_BAG {
    const bag::size_type bag::CAPACITY;
    
    bag::bag() {
        used = 0;
    }
    
    bag::size_type bag::erase(const value_type& target) {
        size_type eraseCount = 0;
        
        while (erase_one(target)) {
            ++eraseCount;
        }
        
        return eraseCount;
    }
    
    bool bag::erase_one(const value_type& target) {
        size_type index = 0;
        
        while (index < used && data[index] != target) {
            ++index;
        }
        
        if (index == used) {
            return false;
        }
        
        --used;
        data[index] = data[used];
        return true;
    }
    
    // Library facilities used: cassert
    void bag::insert(const value_type& entry) {
        assert(size() < CAPACITY);
        
        data[used] = entry;
        ++used;
    }
    
    bag::size_type bag::count(const value_type& target) const {
        size_type answer = 0;
        
        for (size_type i = 0; i < used; ++i) {
            if (target == data[i]) {
                ++answer;
            }
        }
        
        return answer;
    }
    
    bool bag::exist(const value_type& target) const {
        for (size_type i = 0; i < used; ++i) {
            if (target == data[i]) {
                return true;
            }
        }
        return false;
    }

}
     
     
