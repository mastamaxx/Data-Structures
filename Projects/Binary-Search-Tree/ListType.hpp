/*
 
 Mark Max 2016/11/17
 Assignment 4: ListType.hpp
 CIS 279 with Geri Lamble
 
 Developed in Xcode 8.0
 
 CLASS PROVIDED: ListType
 
 STRUCTS and MEMBER CONSTRAINTS for the ListType class:
    struct TREEType
        the structure type for one node of the linked list. It includes an
        WordType object, info, and pointers to ListType, left and right.
 
 CONSTRUCTOR for the ListType class:
    ListType()
        Postcondition: An empty binary tree is created.
 
 MODIFICATION MEMBER FUNCTIONS
 
    void PutOrIncrement(TreeType* tree, std::string word);
        postcondition: if word is found in tree, the object with the key word
            has it's frequency incremented. if it is not, a new TreeType is
            created for the word at the position it belongs according to
            binary search tree logic.
 
 
 CONSTANT MEMBER FUNCTIONS for the ListType class:
    TreeType* GetRoot();
        postcondition: the a pointer to the root of the ListType is returned
 
    TreeType* Left(TreeType* tree);
        postconidition: the left branch of parameter tree is returned. if it
            doesn't have a left branch then NULL is returned.
 
 
    TreeType* Right(TreeType* tree);
        postconidition: the right branch of parameter tree is returned. if it
            doesn't have a right branch then NULL is returned.
 
    void Print(TreeType* tree, std::ofstream& out);
        postcondition: the contents of the binary search tree tree, are printed
            to the file in parameter out.
 
 VALUE SEMANTICS for the ListType class:
    Assignments and the copy constructor may not be used with ListType objects.
 
 DYNAMIC MEMORY USAGE by the ListType class:
    If there is insufficient dynamic memory then the following functions throw
    bad_alloc:
        The constructors, PutOrIncrement
 
 
 */

#ifndef ListType_hpp
#define ListType_hpp

#include <stdio.h>
#include "WordType.hpp"

struct TreeType {
    MarkMaxCIS279::WordType info;
    TreeType* left;
    TreeType* right;
};

namespace MarkMaxCIS279 {
    class ListType {
    public:
        ListType() {rootPtr = NULL;};
        void PutOrIncrement(TreeType* tree, std::string word);
        TreeType* GetRoot() {return rootPtr;};
        TreeType* Left(TreeType* tree);
        TreeType* Right(TreeType* tree);
        void Print(TreeType* tree, std::ofstream& out);
    private:
        TreeType* rootPtr;
    };
}

#endif /* ListType_hpp */
