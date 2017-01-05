/*
 
 Mark Max 2016/10/24
 Assignment 3: listDr.cpp
 CIS 279 with Geri Lamble
 
 Developed in Xcode 8.0
 
 listDr is a program designed to test the functionality of the linked list 
 class UnsortedList which is a class for creating a linked list of Item objects.
 
 */

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include "ItemType.hpp"
#include "UnsortedType.hpp"
using namespace std;

void PrintList(UnsortedType& list);
bool eof(ifstream& in);
ofstream out("a3testMarkMax.txt");


int main(int argc, const char * argv[]) {
    
    UnsortedType testList;

    ifstream in("listData.txt");
    assert(in);
    
    while (!eof(in)) {
        string action;
        int inputInt;
        
        in >> action;
        
        if (action == "GetLength") {
            out << "List length: " << testList.GetLength() << endl;
        } else if (action == "PutItem") {
            in >> inputInt;
            ItemType* temp = new ItemType;
            temp->Initialize(inputInt);
            testList.PutItem(*temp);
            delete temp;
        } else if (action == "PrintList") {
            PrintList(testList);
        } else if (action == "GetItem") {
            in >> inputInt;
            bool found;
            ItemType* temp = new ItemType;
            temp->Initialize(inputInt);
            testList.GetItem(*temp, found);
            delete temp;
            
            if (found == true) {
                out << inputInt << " was found in list!" << endl;
            } else {
                out << inputInt << " was not found in list." << endl;
            }
        } else if (action == "IsFull") {
            if (testList.isFull()) {
                out << "List is full." << endl;
            } else {
                out << "List is not full." << endl;
            }
        } else if (action == "DeleteItem") {
            in >> inputInt;
            ItemType* temp = new ItemType;
            temp->Initialize(inputInt);
            testList.DeleteItem(*temp);
            delete temp;
        } else if (action == "MakeEmpty") {
            testList.MakeEmpty();
        } else if (action == "Error") {
            // do nothing
        } else {
            // do nothing
        }
    }
}
             

void PrintList(UnsortedType& list) {
    list.ResetList();
    out << "List: ";
    
    
    if(list.GetLength() != 0) {
        ItemType temp = list.GetFirstItem();
        temp.Print(out);
        out << " ";
    }
    
    for (int count = 0; count < list.GetLength() - 1; count++) {
        ItemType temp = list.GetNextItem();
        temp.Print(out);
        out << " ";
    }
    
    out << endl;
    
}

bool eof(ifstream& in)
{
    char ch;
    in >> ch;
    in.putback(ch);
    return !in;
}
