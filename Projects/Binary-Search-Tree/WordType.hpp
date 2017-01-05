/*
 
 Mark Max 2016/11/17
 Assignment 4: WordType.hpp
 CIS 279 with Geri Lamble
 
 Developed in Xcode 8.0
 
 CLASS PROVIDED: WordType
 
 TYPEDEFS and MEMBER CONSTRAINTS for the WordType class:
    string is the data type of the key of the WordType class.
    size_t is the data type of the frequency of the key in the book
 
 
    const size_t MAX_LETTERS = _____
        WordType::MAX_ITEMS is the maximum number of letters that the key can
        containe
 
 CONSTRUCTOR for the WordType class:
    WordType(std::string inWord = "");
        Postcondition: The WordType has been initialized with a key of inWord or
        a blank string and a frequency of 1.
 
 MODIFICATION MEMBER FUNCTIONS
    void IncrementFrequency()
        Postcondition: the frequency variable has been increased by 1.
 
    void Initialize(std::string inWord)
        Postcondition: the object key is replaced with inWord.
 
 CONSTANT MEMBER FUNCTIONS for the WordType class:
    std::string GetWord() const;
        Postcondition: the object key is returned
 
    size_t GetFrequency() const;
        Postcondition: a variable representing the frequency of the key is 
        returned

 
 VALUE SEMANTICS for the WordType class:
    Assignments and the copy constructor may be used with WordType objects.
 */

#ifndef WordType_hpp
#define WordType_hpp

#include <stdio.h>
#include <string>


namespace MarkMaxCIS279 {
    
    
    
    class WordType {
        
    public:
        static const size_t MAX_LETTERS = 20;
        
        WordType(std::string inWord = "");
        void IncrementFrequency() {++frequency;};
        void Initialize(std::string inWord) {word = inWord;};
        std::string GetWord() const {return word;};
        size_t GetFrequency() const {return frequency;};
    private:
        std::string word;
        size_t frequency;
    };
}
#endif /* WordType_hpp */
