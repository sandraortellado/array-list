/*
 *
 *  COMP 15 HW 1 Cheshire ConCATenation - no chars attached
 *
 *  CharArrayList.cpp
 *
 *  PURPOSE 
 *  Define all functions in the CharArrayList class
 *  Modified by: Sandra Ortellado
 *           On: 9/22/22
 *
 */

#include <iostream>
#include <string>

#include "CharArrayList.h"

using namespace std;

//TODO: expand called repeatedly

//Default constructor initializes an empty array list
CharArrayList::CharArrayList() {
    numItems = 0;
    capacity = 0;
    arr = nullptr;
}

//Second constructor takes in a single character as a parameter and creates a one element array list 
//of that character, with an initial capacity of 1.
CharArrayList::CharArrayList(char c) {
    numItems = 1;
    capacity = 1;
    arr = new char[capacity];
    arr[0] = c;
}

//Third constructor takes an array of characters and the integer length of that array
//Creates an array list containing the characters in the array
//Initial capacity equal to that of given array
CharArrayList::CharArrayList(char input_arr[], int size) {
    numItems = size;
    capacity = size;
    char *new_arr = new char[capacity];
    for (int i = 0; i <= capacity; i++) {
        new_arr[i] = input_arr[i];
    }
    arr = new_arr;
}

//Copy constructor that makes a deep copy of a given instance
CharArrayList::CharArrayList(const CharArrayList &other) {
    numItems = other.numItems;
    capacity = other.capacity;
    char *new_arr = new char[capacity];
    for (int i = 0; i < capacity; i++) {
        new_arr[i] = other.arr[i];
    }
    arr = new_arr;
}

//Destructor that destroys/deletes/recycles all heap-allocated data 
//in the current array list
CharArrayList::~CharArrayList() {
    delete [] arr;
    arr = nullptr;
}

/* assignment operator
 * Purpose: Define an assignment operator for the class that recycles the storage
  associated with the instance on the left of the assignment and 
  makes a deep copy of the instance on the right hand side 
  into the instance on the left hand side
 * Parameters: memory address of CharArrayList instance
 * Returns: nothing
 */
void CharArrayList::operator=(const CharArrayList &other) {
    if (capacity < other.numItems) {
        this->expand();
    }
    CharArrayList temp = CharArrayList(other);
    numItems = temp.numItems;
    capacity = temp.capacity;
    for (int i = 0; i <= numItems; i++) {
        arr[i] = temp.arr[i];
    }
}

/* isEmpty
 * Purpose: Determine if this specific instance of the class is empty
 * Parameters: none
 * Returns: boolean true or false
 */
bool CharArrayList::isEmpty() const {
    return (numItems == 0);
}

/* clear
 * Purpose: Makes the instance into an empty array list
 * Parameters: none
 * Returns: nothing
 */
void CharArrayList::clear() {
    numItems = 0;
    char *empty = new char[capacity];
    delete [] arr;
    arr = empty;
}

/* size
 * Purpose: Determines the number of characters in the array list
 * Parameters: none
 * Returns: an integer value that is the number of characters in the array list
 */
int CharArrayList::size() const {
    return numItems;
}

/* first
 * Purpose: Fetch the first element (char) in the array list
 * Parameters: none
 * Returns: the first element (char) in the array list
 */
char CharArrayList::first() const {
    if (this->isEmpty()) {
       throw runtime_error("cannot get first of empty ArrayList");
    }
    return arr[0];
}

/* last
 * Purpose: Fetch the first element (char) in the array list
 * Parameters: none
 * Returns: the first element (char) in the array list
 */
char CharArrayList::last() const {
    if (this->isEmpty()) {
       throw runtime_error("cannot get last of empty ArrayList");
    }
    return arr[numItems - 1];
}

/* elementAt
 * Purpose: Gives the char in the array list at a given index
 * Parameters: integer index
 * Returns: char in the array list at that index
 */
char CharArrayList::elementAt(int index) const {
    if (index >= numItems || index < 0) {
        throw range_error("index (" + to_string(index) + ") not in range [0.." + to_string(numItems) + ")");
    }
    return arr[index];
}

/* toString
 * Purpose: Makes a string out of the chars in the array list
 * Parameters: none
 * Returns: a string which contains the characters of the CharArrayList
 */
string CharArrayList::toString() const {
    string stringed = "";
    if (this->isEmpty()) {
        stringed = "[CharArrayList of size 0 <<>>]";
        return stringed;
    }
    for (int i = 0; i < numItems; i++) {
        stringed += arr[i];
    }
    stringed = "[CharArrayList of size " + to_string(numItems) + " <<" + stringed + ">>]";
    return stringed;
}

/* toReverseString
 * Purpose: Makes a string out of the chars in the array list, reversed
 * Parameters: none
 * Returns: a string which contains the characters of the CharArrayList in reverse
 */
string CharArrayList::toReverseString() const {
    string reversed = "";
    if (this->isEmpty()) {
        reversed = "[CharArrayList of size 0 <<>>]";
        return reversed;
    }
    for (int i = numItems - 1; i >= 0; i--) {
        reversed += arr[i];
    }
    reversed = "[CharArrayList of size " + to_string(numItems) + " <<" + reversed + ">>]";
    return reversed;
}

/* pushAtBack
 * Purpose: Inserts given new char at the end of the existing chars
 * Parameters: an element (char)
 * Returns: nothing
 */
void CharArrayList::pushAtBack(char c) {
    if (numItems == capacity) {
        this->expand();
    }
    arr[numItems] = c;
    numItems++;
}

/* pushAtFront
 * Purpose: Inserts given new char at the front of existing char array
 * Parameters: an element (char)
 * Returns: nothing
 */
void CharArrayList::pushAtFront(char c) {
    if (numItems == capacity) {
        this->expand();
    }
    for (int i = numItems - 1; i >= 0; i--) {
        arr[i+1] = arr[i];
    }
    arr[0] = c;
    numItems++;
}

/* insertAt
 * Purpose: Inserts given new char at given index
 * Parameters: an element (char), and index (int)
 * Returns: nothing
 */
void CharArrayList::insertAt(char c, int index) {
    if (numItems == capacity) {
        this->expand();
    }
    if (index > numItems || index < 0) {
        throw range_error("index (" + to_string(index) + ") not in range [0.." + to_string(numItems) + "]");
    } else if (index == numItems) {
        arr[numItems] = c;
    } else {
        for (int i = numItems - 1; i >= index; i--) {
            arr[i+1] = arr[i];
        }
        arr[index] = c;
    }
    numItems++;
}

/* insertInOrder
 * Purpose: Inserts given new char in alphabetical order
 * Parameters: an element (char)
 * Returns: nothing
 */
void CharArrayList::insertInOrder(char c) {
    if (numItems == capacity) {
        this->expand();
    }
    for (int i = 0; i < numItems; i++) {
        if (c < arr[i]) {
            this->insertAt(c, i);
            return;
        }
    }
    this->pushAtBack(c);
}

/* popFromFront
 * Purpose: Removes the first element from the array list
 * Parameters: none
 * Returns: nothing
 */
void CharArrayList::popFromFront() {
    if (this->isEmpty()) {
        throw runtime_error("cannot pop from empty ArrayList");
    }
    char *new_arr = &arr[0] + 1;

    for (int i = 0; i <= numItems; i++) {
        arr[i] = new_arr[i];
    }
    numItems--;
}

/* popFromBack
 * Purpose: Removes the last element from the array list
 * Parameters: none
 * Returns: nothing
 */
void CharArrayList::popFromBack() {
    if (this->isEmpty()) {
        throw runtime_error("cannot pop from empty ArrayList");
    }
    char *new_arr = new char[capacity];
    for (int i = 0; i < numItems - 1; i++) {
        new_arr[i] = arr[i];
    }

    for (int i = 0; i <= numItems; i++) {
        arr[i] = new_arr[i];
    }
    numItems--;
}

/* removeAt
 * Purpose: Removes the element at the specified index
 * Parameters: index (int)
 * Returns: nothing
 */
void CharArrayList::removeAt(int index) {
    if (index >= numItems || index < 0) {
        throw range_error("index (" + to_string(index) + ") not in range [0.." + to_string(numItems) + ")");
    }
    for (int i = 0; i < numItems; i++) {
        if (i >= index) {
            arr[i] = arr[i + 1];
        }
    }
    this->popFromBack();
}

/* replaceAt
 * Purpose: Replaces the element at the specified index with the specified char
 * Parameters: element (char), index (int)
 * Returns: nothing
 */
void CharArrayList::replaceAt(char c, int index) {
    if (index >= numItems || index < 0) {
        throw range_error("index (" + to_string(index) + ") not in range [0.." + to_string(numItems) + ")");
    }
    arr[index] = c;
}

/* concatenate
 * Purpose: Adds a copy of the array list passed in to the end 
 * of the array list called from
 * Parameters: CharArrayList pointer
 * Returns: nothing
 */
void CharArrayList::concatenate(CharArrayList *other) {
    int new_capacity = numItems + other->numItems;
    if (capacity == 0 && other->numItems > 0) {
        capacity = other->numItems;
        this->expand();
    }
    while (new_capacity > capacity) {
        this->expand();
    }
    if (this->isEmpty() && !other->isEmpty()) {
        char *new_arr = new char[other->capacity];
        for (int i = 0; i < other->numItems; i++) {
            new_arr[i] = other->arr[i];
        }
        for (int i = 0; i < other->numItems; i++) {
            arr[i] = new_arr[i];
        }
        numItems = other->numItems;
    } else if (!this->isEmpty() && !other->isEmpty()) {
        for (int i = numItems; i < numItems + other->numItems; i++) {
            arr[i] = other->arr[i - numItems];
        }
        numItems += other->numItems;
    }
}

/* shrink
 * Purpose: Reduces object’s memory usage to bare minimum required to store elements
 * Parameters: none
 * Returns: nothing
 */
void CharArrayList::shrink() {
    this->resize(numItems);
}

/* expand
 * Purpose: Helper function to double the size of array
 * Parameters: none
 * Returns: nothing
 */
void CharArrayList::expand() {
    if (capacity == 0) {
        capacity = 1;
    } else {
        capacity *= 2;  
    }
    this->resize(capacity);
}

/* resize
 * Purpose: Helper function to resize array to given size
 * Parameters: size (int)
 * Returns: nothing
 */
void CharArrayList::resize(int newSize) {
    char *temp = new char[numItems];
    for (int i = 0; i < numItems; i++) {
        temp[i] = arr[i];
    }
    arr = new char[newSize];
    for (int i = 0; i <= numItems; i++) {
        arr[i] = temp[i];
    }
}
