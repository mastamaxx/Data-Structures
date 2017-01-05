/*
 
 Mark Max 2016/10/24
 Assignment 4: ListType.cpp
 CIS 279 with Geri Lamble
 
 Developed in Xcode 8.0
 
 CLASS IMPLEMENTED: ListType (see ListType.hpp for documentation)
 INVARIANT for the ListType class:
 1. The tree elements are of objects of WordType class.
 2. member variable rootPtr is a pointer to the first element of the tree
 3. The tree is s binary search tree.
 */

#include "ListType.hpp"
#include <iostream>
#include <fstream>

using namespace std;

namespace MarkMaxCIS279 {
    
    void ListType::PutOrIncrement(TreeType* tree, string word) {
        if (tree == NULL) {
            TreeType* tempTree = new TreeType;
            tempTree->info.Initialize(word);
            tempTree->left = NULL;
            tempTree->right = NULL;
            rootPtr = tempTree;
        } else if (tree->info.GetWord() == word) {
            tree->info.IncrementFrequency();
        } else if (tree->info.GetWord() > word) {
            if (tree->left == NULL) {
                TreeType* tempTree = new TreeType;
                tempTree->info.Initialize(word);
                tempTree->left = NULL;
                tempTree->right = NULL;
                tree->left = tempTree;
            } else {
                PutOrIncrement(Left(tree), word);
            }
        } else {
            if (tree->right == NULL) {
                TreeType* tempTree = new TreeType;
                tempTree->info.Initialize(word);
                tempTree->left = NULL;
                tempTree->right = NULL;
                tree->right = tempTree;
            } else {
                PutOrIncrement(Right(tree), word);
            }
        }
    }
    
    TreeType* ListType::Left(TreeType* tree) {
        tree = tree->left;
        return tree;
    }
    
    TreeType* ListType::Right(TreeType* tree) {
        tree = tree->right;
        return tree;
    }
    
    
    void ListType::Print(TreeType* tree, ofstream& out) {
        
        if (tree != NULL) {
        
            if (tree->left != NULL) {
                Print(Left(tree), out);
            }
            
            out << tree->info.GetWord() << ": " << tree->info.GetFrequency()
            << endl;
            
            if (tree->right != NULL) {
                Print(Right(tree), out);
            }
            
        }
         
    }
}
