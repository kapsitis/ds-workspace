#include <iostream>
#include <stdexcept>
#include "CircularList.h"

using namespace ds_course;
using namespace std;

// Do not use this; used just to make head/tail stubs.
static int dummyVariable;

/**
 * Construct an empty list
 */
CircularList::CircularList() {
}

/**
 * Free/delete all nodes reserved by this list.
 */
CircularList::~CircularList() {
}

/**
 * Return true iff size is 0.
 */
bool CircularList::isEmpty() const
{
    return false;
}

/**
 * Should return reference to the info field of the last node
 */
int &CircularList::tail() const {
    return dummyVariable;
}

/**
 * Should return reference to the info field of the last node
 */
int &CircularList::head() const
{
    return dummyVariable;
}

/**
 * Before this method: "[0, 1, 2]" 
 * After this method "tail_" points to the first element of the old list: "[1, 2, 0]"
 */
void CircularList::moveNext() {
}

/**
 * Before this method: "[0, 1, 2]" 
 * After this method "tail_" steps back and list rotates: "[2, 0, 1]"
 */
void CircularList::movePrev() {
}


/**       
 * Before this method: "[0, 1, 2, 3, 4]"
 * After this method: "[5, 0, 1, 2, 3, 4]"
 */
void CircularList::pushFront(int val) {
}

/**       
 * Before this method: "[0, 1, 2, 3, 4]"
 * After this method: "[1, 2, 3, 4]"
 */
void CircularList::popFront() {
}

/**
 * Empty list returns "[]"
 * One-element list returns "[num0]"
 * Longer list returns "[num0, num1, ..., numN]"
 * Commas and spaces are mandatory for readability + testing.
 */
string CircularList::toString() {
    return "[]";
}

/**
 * Returns the size of the list
 */
int CircularList::getSize() {
    return size;
}

/**
 * Before this method: [1, 2, 3, 4], pos=2, val=11
 * After this method: [1, 2, 11, 3, 4]
 */
void CircularList::insertAt(int pos, int val) {
    cerr << "LOG: insertAt(" << pos << ", " << val << ")" << endl;
}

/**
 * Before this method: [1, 2, 3, 4], pos=2
 * After this method: [1, 2, 4]
 * (The tail stays where it was; if last element is erased, it moves back by 1)
 */
void CircularList::eraseAt(int pos) {
    cerr << "LOG: eraseAt(" << pos << ")" << endl;
}

/**
 * Before this method: [1, 2, 3, 4], pos=2, val=11
 * After this method: [1, 2, 11, 3, 4]
 */
void CircularList::assignAt(int pos, int val) {
    cerr << "LOG: assignAt(" << pos << ", " << val << ")" << endl;
}
