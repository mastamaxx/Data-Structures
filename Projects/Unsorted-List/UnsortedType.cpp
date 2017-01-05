/*
 
 Mark Max 2016/10/24
 Assignment 3: UnsortedType.cpp
 CIS 279 with Geri Lamble
 
 Developed in Xcode 8.0
 
 CLASS IMPLEMENTED: UnsortedType (see UnsortedType.hpp for documentation)
 INVARIANT for the UnsortedType class:
 1. The number of items in the list is in the member variable length.
 2. The list elements are of objects of ItemType class.
 3. member variable listData is a pointer to the first element of the list
 4. member variable currentPos is a pointer to the last accessed member of the 
    list
 */

#include "UnsortedType.hpp"
#include "ItemType.hpp"
#include <fstream>
#include <cassert>

UnsortedType::UnsortedType() {
    length = 0;
    listData = NULL;
    currentPos = NULL;
}

UnsortedType::UnsortedType(UnsortedType& list) {
    NodeType* nodePtr = list.listData;
    
    if (list.listData == NULL) {
        length = 0;
        listData = NULL;
        currentPos = NULL;
    } else {
        length = list.length;
        
        NodeType* tempNode = new NodeType;
        tempNode->info = list.listData->info;
        tempNode->next = NULL;
        
        listData = tempNode;
        nodePtr = nodePtr->next;
        
        while (nodePtr != NULL) {
            tempNode->next = new NodeType;
            tempNode = tempNode->next;
            tempNode->info = nodePtr->info;
            tempNode->next = NULL;
            
            nodePtr = nodePtr->next;
        }
    }
}

UnsortedType::~UnsortedType() {
    MakeEmpty();
    length = 0;
}

void UnsortedType::MakeEmpty() {
    ResetList();
    
    while(listData != NULL) {
        NodeType* removeNode = listData;
        listData = listData->next;
        delete removeNode;
        --length;
        ResetList();
    }
    
    length = 0;
}

bool UnsortedType::isFull() const{
    return length == MAX_ITEMS;
}

ItemType UnsortedType::GetItem(ItemType item, bool& found) const {
    
    NodeType* findNode = listData;
    
    while (findNode != NULL) {
        if (findNode->info.ComparedTo(item) == EQUAL) {
            found = true;
            return findNode->info;
        }
        
        findNode = findNode->next;
    }

    found = false;
    return item;
}

void UnsortedType::PutItem(ItemType item) {
    
    if (length < MAX_ITEMS) {
        NodeType* temp;
        
        temp = new NodeType;
        temp->info = item;
        temp->next = listData;
        listData = temp;
        
        ++length;
    }
}

void UnsortedType::DeleteItem(ItemType item) {
    
    if (listData != NULL) {
    
        bool deleted = false;
    
        ResetList();
    
        if(item.ComparedTo(listData->info) == EQUAL) {
            NodeType* removeNode = listData;
            listData = listData->next;
            delete removeNode;
            --length;
            deleted = true;
            ResetList();
        }
    
        while (currentPos->next != NULL && deleted == false) {
            NodeType* previousPos = currentPos;
        
            if(item.ComparedTo(GetNextItem()) == EQUAL) {
                NodeType* removeNode = currentPos;
                previousPos->next = currentPos->next;
                delete removeNode;
                --length;
                deleted = true;
                ResetList();
            }
        }
    }
}

void UnsortedType::ResetList() {
    currentPos = listData;
}

ItemType UnsortedType::GetFirstItem() const {
    assert(listData != NULL);
    
    return listData->info;
}

ItemType UnsortedType::GetNextItem() {
    
    if (currentPos->next == NULL) {
        throw "End of List!";
    }
    
    if (currentPos == NULL) {
        throw "Empty List!";
    }
    
    currentPos = currentPos->next;
    return currentPos->info;
}

void UnsortedType::operator =(const UnsortedType& source) {
    
    if (this == &source) {
        return;
    }
    
    NodeType* nodePtr = source.listData;
    
    if (source.listData == NULL) {
        length = 0;
        listData = NULL;
        currentPos = NULL;
    } else {
        length = source.length;
        
        NodeType* tempNode = new NodeType;
        tempNode->info = source.listData->info;
        tempNode->next = NULL;
        
        listData = tempNode;
        nodePtr = nodePtr->next;
        
        while (nodePtr != NULL) {
            tempNode->next = new NodeType;
            tempNode = tempNode->next;
            tempNode->info = nodePtr->info;
            tempNode->next = NULL;
            
            nodePtr = nodePtr->next;
        }
    }
    
    
}

