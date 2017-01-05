/*
 
 Mark Max 2016/09/25
 Assignment 2: bag.hpp
 CIS 279 with Geri Lamble
 
 Developed in Xcode 7.3.1
 
 CLASS PROVIDED: bag (part of the namespace MARK_MAX_BAG)

 TYPEDEFS and MEMBER CONSTRAINTS for the bag class:
    typedef _____ value_type
        bag::value_type is the data type of the items in the bag. It may be any
        of the C++ built-in types, a class with a default constructor, an
        assignment operator, and operators to test for equality and non-equality
 
    typedef _____ size_type
        bag::size_type is the data type of any variable that keeps track of how
        many items are in the bag.
 
    static const size_type CAPACITY = _____
        bag::CAPACITY is the maximum number of items that a bag can hold
 
 CONSTRUCTOR for the bag class:
    bag()
        Postcondition: The bag has been initialized as an empty bag.
 
 MODIFICATION MEMBER FUNCTIONS
    size_type erase(const value_type& target)
        Postcondition: All copies of target have been removed from the bag.
        The return value is the number of copies removed (which could be zero).
 
    bool erase_one(const value_type& target)
        Postcondition: If target was in the bag, then the first copy has been
        removed, otherwise the bag is unchanged. A true return value indicates
        that one copy was removed; false indicates that nothing was removed.
    
    void insert(const value_type& entry)
        Precondition: size() < CAPACITY.
        Postcondition: A new copy of entry has been added to the bag.
 
 CONSTANT MEMBER FUNCTIONS for the bag class:
    size_type size() const
        Postcondition: The return value is the total number of items in the bag.
 
    size_type count(const value_type& target) const
        Postcondition: The return value is the number of times target is in the
        bag.
 
    bool exist(const value_type& target) const
        Postcondition: A true return indicates that target is in the bag; false
        indicates that target is not in the bag.
 
 VALUE SEMANTICS for the bag class:
    Assignments and the copy constructor may be used with bag objects.
 */

#ifndef bag_hpp
#define bag_hpp

#include <stdio.h>

namespace MARK_MAX_BAG {
    class bag {
    
    public:
        // TYPEDEFS and MEMBER CONSTRAINTS
        typedef int value_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 20;
        // CONSTRUCTOR
        bag();
        // MODIFICATION MEMBER FUNCTIONS
        size_type erase(const value_type& target);
        bool erase_one(const value_type& target);
        void insert(const value_type& entry);
        // CONSTANT MEMBER FUNCTIONS
        size_type size() const {return used;};
        size_type count(const value_type& target) const;
        bool exist(const value_type& target) const;
    private:
        value_type data[CAPACITY];
        size_type used;
    };
}

#endif /* bag_hpp */
