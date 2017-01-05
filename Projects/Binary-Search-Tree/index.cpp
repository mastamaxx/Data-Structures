/*
 
 Mark Max 2016/11/17
 Assignment 4: index.cpp
 CIS 279 with Geri Lamble
 
 Developed in Xcode 8.0
 
 index is a program designed to test the functionality of the binary search tree
 class ListType which is a class for creating an alphabetically sorted tree of 
 WordType objects.
 
 */

#include <iostream>
#include <fstream>
#include "WordType.hpp"
#include "ListType.hpp"

using namespace std;
using namespace MarkMaxCIS279;

bool eof(ifstream& in);
string getString(ifstream& in);

int main() {
    
    ofstream out("a4testMarkMax.txt");
    ifstream in("index.in");
    
    const size_t MAX_LETTERS = WordType::MAX_LETTERS;
    const size_t MIN_LETTERS = 3;
    
    string letters;
    letters = getString(in);
    ListType list;
    
    while(!eof(in)) {
        if (letters.length() >= MIN_LETTERS && letters.length() <= MAX_LETTERS) {
            list.PutOrIncrement(list.GetRoot(), letters);
        }
        
        letters = getString(in);
    }
    
    
    list.Print(list.GetRoot(), out);
    
}

bool eof(ifstream& in)
{
    char ch;
    in >> ch;
    in.putback(ch);
    return !in;
}

string getString(ifstream& in) {
    string letters;
    char letter;
    in.get(letter);
    
    
    while (!eof(in) && !isalnum(letter)) {
        in.get(letter);
    }
    
    if (eof(in)) {
        return letters;
    } else {
        do {
            letter = tolower(letter);
            letters += letter;
            in >> noskipws >> letter;
        } while (isalnum(letter) && !eof(in));
        
    }
    
    return letters;
}
