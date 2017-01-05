/*
 
 Mark Max 2016/10/24
 Assignment 3: UnsortedType.hpp
 CIS 279 with Geri Lamble
 
 Developed in Xcode 8.0
 
 CLASS PROVIDED: UnsortedType
 
 STRUCTS and MEMBER CONSTRAINTS for the UnsortedType class:
    struct NodeType
        the structure type for one node of the linked list. It includes an
        ItemType object, info, and a pointer to NodeType, next.
 
    Contraint for maximum items in a list is contained in ItemType.hpp
 
    CONSTRUCTOR for the UnsortedType class:
        UnsortedType()
            Postcondition: An empty linked list is created.
 
 MODIFICATION MEMBER FUNCTIONS
    void MakeEmpty()
        Postcondition: list is empty
 
    void PutItem(ItemType item)
        Preconition: the list is not full
        Postcondition: item has been added to the list at the beginning
 
    void DeleteItem(ItemType item)
        Precondition: the list has been initialized
        Postcondition: if item is in the list, one copy of it has been deleted
 
    void ResetList()
        Function: Ititializes current position to front of list
        Precondition: list has been initialized
        Postcondition: current position is at the front of the list
 
    ItemType GetNextItem()
        Precondition: the list is not empty and the current position is not 
        pointing at the last ItemType
        Postcondition: the current position is moved to the next item in the
        list and that ItemType object is returned by the function
 
 
 CONSTANT MEMBER FUNCTIONS for the UnsortedType class:
    int GetLength() const
        Precondition: list has been initialized
        Postcondition: The return value is the length of the list
 
    bool isFull() const
        Precondition: list has been initialized
        Postcondition: The return value is true if list is full
 
    ItemType GetItem(ItemType item, bool& found) const
        Precondition: list has been initialized, key member of item has been 
        initialized
        Postcondition: If there is an element in the calling UnsortedType list
        that has a key equal to the key of item it will be returned and found
        will be set to true. If there is not an equivalent ItemType to item in
        the list, found will be set to false and item will be returned.
 
    ItemType GetFirstItem() const
        Precondition: the list is not empty
        Postconidition: the return value is the first ItemType in the list
 
 VALUE SEMANTICS for the UnsortedType class:
    Assignments and the copy constructor may be used with UnsortedType objects.
 
 DYNAMIC MEMORY USAGE by the UnsortedType class:
    If there is insufficient dynamic memory then the following functions throw
    bad_alloc:
    The constructors, put, assignment operator
 */

#ifndef UnsortedType_hpp
#define UnsortedType_hpp

#include <stdio.h>
#include <fstream>
#include "ItemType.hpp"

struct NodeType {
    ItemType info;
    NodeType* next;
};

class UnsortedType {
public:
    UnsortedType();
    UnsortedType(UnsortedType& list);
    ~UnsortedType();
    void MakeEmpty();
    int GetLength() const {return length;};
    bool isFull() const;
    ItemType GetItem(ItemType item, bool& found) const;
    void PutItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();
    ItemType GetFirstItem() const;
    ItemType GetNextItem();
    void operator =(const UnsortedType& source);
private:
    NodeType* listData; // pointer to the beginning of linked list
    int length; // number of items in linked list
    NodeType* currentPos;
};

#endif /* UnsortedType_hpp */
