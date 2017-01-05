/*
 
 Mark Max 2016/11/17
 Assignment 4: WordType.cpp
 CIS 279 with Geri Lamble
 
 Developed in Xcode 8.0
 
 CLASS IMPLEMENTED: WordType (see WordType.hpp for documentation)
 INVARIANT for the WordType class:
 1. The key of the WordType is stored in the member variable word
 2. The number of times the word is in the book is stored in variable frequency
 */

#include "WordType.hpp"

namespace MarkMaxCIS279 {
    WordType::WordType(std::string inWord) {
        word = inWord;
        frequency = 1;
    }
}
