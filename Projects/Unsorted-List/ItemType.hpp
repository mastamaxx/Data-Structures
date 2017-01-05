/*
 
 Mark Max 2016/10/24
 Assignment 3: ItemType.hpp
 CIS 279 with Geri Lamble
 
 Developed in Xcode 8.0
 
 CLASS PROVIDED: ItemType
 
 TYPEDEFS and MEMBER CONSTRAINTS for the ItemType class:
    int is the data type of the key of the ItemType class.
 
    enum RelationType{LESS, GREATER, EQUAL}
        ItemType::RelationType is an enum for comparing the keys of two 
        different ItemType objects
 
    const int MAX_ITEMS = _____
        ItemType::MAX_ITEMS is the maximum number of ItemType objects that a
        container class or linked list can have.
 
 CONSTRUCTOR for the ItemType class:
    ItemType()
        Postcondition: The ItemType has been initialized with a key of 0.
 
 MODIFICATION MEMBER FUNCTIONS
    void Initialize(int number)
        Postcondition: the key of the ItemType object is now equal to number.
 
 CONSTANT MEMBER FUNCTIONS for the ItemType class:
    RelationType ComparedTo(const ItemType otherItem) const
        Precondition: Self and otherItem have their key members initialized
        Postcondition: The return value is: 
                        LESS if key of self is less than key of otherItem
                        GREATER if key of self is greater than key of otherItem
                        EQUAL if key of self is equal to key of otherItem
 
    void Print(std::ostream& os) const
        Postcondition: the outstream os is addended with the key of the calling
        ItemType object.
 
 VALUE SEMANTICS for the ItemType class:
    Assignments and the copy constructor may be used with ItemType objects.
 */


#ifndef ItemType_hpp
#define ItemType_hpp

#include <stdio.h>
#include <fstream>

const int MAX_ITEMS = 5;
enum RelationType {LESS, GREATER, EQUAL};

class ItemType {

public:
    ItemType() {value = 0;};
    RelationType ComparedTo(const ItemType otherItem) const;
    void Print(std::ostream& os) const;
    void Initialize(int number);
private:
    int value;
};

#endif /* ItemType_hpp */
