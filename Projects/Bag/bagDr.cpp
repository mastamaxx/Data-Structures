/*

 Mark Max 2016/09/25
 Assignment 2: bagDr.cpp
 CIS 279 with Geri Lamble

 Developed in Xcode 7.3.1
 
 bagDr is a program designed to test the functionality of the container class
 bag. The program fills the bag to capacity by first inserting a double value
 that is rounded down to an int and then in a for loop inserting random integers
 1-6 until the bag is full. The program the tests the member functions erase_one
 and erase to erase one 4 and all 5s from the test bag.
 
 */
 
#include <iostream>
#include "bag.hpp"

using namespace std;
using namespace MARK_MAX_BAG;

int main() {
    
    // initialize a bag object
    bag testBag;
    
    // insert the first 4; if typedef is set to int it will round 4.7 down to 4
    testBag.insert(4.7);
    
    for (bag::size_type index = 0; index < bag::CAPACITY - 1; ++index) {
        testBag.insert(rand() % 5 + 1);
    }
    
    cout << "size of testBag = " << testBag.size() << endl;
    cout << "# of 4s in testBag = " << testBag.count(4) << endl;
    testBag.erase_one(4);
    cout << "After removing a 4:" << endl;
    cout << "size of testBag = " << testBag.size() << endl;
    cout << "# of 4s in testBag = " << testBag.count(4) << endl;
    cout << "# of 5s in testBag = " << testBag.count(5) << endl;
    testBag.erase(5);
    cout << "After removing all 5s:" << endl;
    cout << "# of 5s in testBag = " << testBag.count(5) << endl;
}


/*

 size of testBag = 20
 # of 4s in testBag = 6
 After removing a 4:
 size of testBag = 19
 # of 4s in testBag = 5
 # of 5s in testBag = 4
 After removing all 5s:
 # of 5s in testBag = 0

*/