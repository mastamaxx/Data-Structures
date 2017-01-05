/*
 
 Mark Max 2016/10/24
 Assignment 3: UnsortedType.cpp
 CIS 279 with Geri Lamble
 
 Developed in Xcode 8.0
 
 CLASS IMPLEMENTED: ItemType (see ItemType.hpp for documentation)
 INVARIANT for the ItemType class:
 1. The key of the ItemType is stored in the member variable value
 */

#include "ItemType.hpp"
#include <fstream>

RelationType ItemType::ComparedTo(const ItemType otherItem) const {
    
    if (this->value < otherItem.value) {
        return LESS;
    } else if (this->value > otherItem.value) {
        return GREATER;
    }
    
    return EQUAL;
}

void ItemType::Print(std::ostream& os) const{
    os << value;
}

void ItemType::Initialize(int number) {
    value = number;
}
