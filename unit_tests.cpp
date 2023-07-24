#include "CharArrayList.h"
#include <cassert>
#include <iostream>

//TODO: add cases to tests! esp concat
//Q: passing in of &other?

void constructor_test() {
    //default constructor
    CharArrayList basic = CharArrayList();
    assert(basic.isEmpty());
    assert(basic.size() == 0);

    //secondconstructor
    CharArrayList solo = CharArrayList('a');
    assert(solo.size() == 1);
    assert(solo.elementAt(0) == 'a');

    //third constructor
    char *tarr = new char[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'c';
    tarr[3] = 'd';
    CharArrayList charArr = CharArrayList(tarr, 4);
    assert(charArr.size() == 4);
    assert(charArr.elementAt(0) == 'a');
    assert(charArr.elementAt(1) == 'b');
    assert(charArr.elementAt(2) == 'c');
    assert(charArr.elementAt(3) == 'd');
    
    //copy constructor
    CharArrayList copy = CharArrayList(charArr);
    assert(copy.size() == 4);
    assert(copy.elementAt(0) == 'a');

    delete [] tarr;
}

void assignment_test() {
    CharArrayList orig_solo = CharArrayList('b');
    char *tarr = new char[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'c';
    tarr[3] = 'd';
    CharArrayList new_solo = CharArrayList(tarr, 4);
    new_solo = orig_solo;
    assert(new_solo.elementAt(0) == 'b');
    delete [] tarr;
}

void empty_test() {
    CharArrayList empty = CharArrayList();
    assert(empty.isEmpty() == true);
}

void clear_test() {
    CharArrayList solo = CharArrayList('a');
    solo.clear();
    assert(solo.isEmpty());
}

void size_test() {
  CharArrayList solo = CharArrayList('a');
  assert(solo.size() == 1);  
}

void first_test() {
    char *tarr = new char[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'c';
    tarr[3] = 'd';
    CharArrayList fchar = CharArrayList(tarr, 4);
    assert(fchar.first() == 'a');
    try {
       CharArrayList empty = CharArrayList();
       empty.first(); 
       assert(false);
    } catch (runtime_error) {
    }

    delete [] tarr;
}

void last_test() {
    char *tarr = new char[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'c';
    tarr[3] = 'd';
    CharArrayList fchar = CharArrayList(tarr, 4);
    assert(fchar.last() == 'd');
    try {
       CharArrayList empty = CharArrayList();
       empty.last(); 
       assert(false);
    } catch (runtime_error) {
    }

    delete [] tarr;
}

void elementAt_test() {
    char *tarr = new char[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'c';
    tarr[3] = 'd';
    CharArrayList echar = CharArrayList(tarr, 4);
    assert(echar.elementAt(2) == 'c');
    try {
       echar.elementAt(5);
       echar.elementAt(-1);
       assert(false);
    } catch (range_error) {
    }

    delete [] tarr;
}

void toString_test() {
    char *tarr = new char[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'c';
    tarr[3] = 'd';
    CharArrayList schar = CharArrayList(tarr, 4);
    assert(schar.toString() == "[CharArrayList of size 4 <<abcd>>]");

    CharArrayList empty = CharArrayList();
    assert(empty.toString() == "[CharArrayList of size 0 <<>>]");

    delete [] tarr;
}

void toReverseString_test() {
    char *tarr = new char[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'c';
    tarr[3] = 'd';
    CharArrayList rchar = CharArrayList(tarr, 4);
    assert(rchar.toReverseString() == "[CharArrayList of size 4 <<dcba>>]");

    CharArrayList empty = CharArrayList();
    assert(empty.toReverseString() == "[CharArrayList of size 0 <<>>]");

    delete [] tarr;
}

void pushAtBack_test() {
    CharArrayList solo = CharArrayList('a');
    solo.pushAtBack('c');
    assert(solo.elementAt(1) == 'c');
}

void pushAtFront_test() {
    CharArrayList solo = CharArrayList('a');
    solo.pushAtFront('c');
    assert(solo.elementAt(0) == 'c');
}

void insertAt_test() {
    char *tarr = new char[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'c';
    tarr[3] = 'd';
    CharArrayList ichar = CharArrayList(tarr, 4);
    ichar.insertAt('e', 4);
    assert(ichar.elementAt(4) == 'e');

    ichar.insertAt('f', 1);
    assert(ichar.elementAt(1) == 'f');

    assert(ichar.size() == 6);

    try {
       ichar.elementAt(6);
       ichar.elementAt(-1);
       assert(false);
    } catch (range_error) {
    }

    delete [] tarr;
}

void insertInOrder_test() {
    char *tarr = new char[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'd';
    tarr[3] = 'e';
    CharArrayList ochar = CharArrayList(tarr, 4);
    ochar.insertInOrder('c');
    cout << ochar.elementAt(0);
    cout << ochar.elementAt(1);
    cout << ochar.elementAt(2);
    cout << ochar.elementAt(3);
    cout << ochar.elementAt(4);
    
    // assert(ochar.elementAt(0) == 'a');
    // assert(ochar.elementAt(1) == 'b');
    // assert(ochar.elementAt(2) == 'c');
    // assert(ochar.elementAt(3) == 'd');
    // assert(ochar.elementAt(4) == 'e');

    delete [] tarr;
}

void popFromFront() {
    char *tarr = new char[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'd';
    tarr[3] = 'e';
    CharArrayList pchar = CharArrayList(tarr, 4);
    pchar.popFromFront();
    assert(pchar.elementAt(0) == 'b');
    assert(pchar.size() == 3);

    try {
       CharArrayList empty = CharArrayList();
       empty.first(); 
       assert(false);
    } catch (runtime_error) {
    }

    delete [] tarr;

}

void popFromBack() {
    char *tarr = new char[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'd';
    tarr[3] = 'e';
    CharArrayList pchar = CharArrayList(tarr, 4);
    pchar.popFromBack();
    assert(pchar.elementAt(0) == 'a');
    assert(pchar.elementAt(2) == 'd');
    assert(pchar.size() == 3);

    try {
       CharArrayList empty = CharArrayList();
       empty.first(); 
       assert(false);
    } catch (runtime_error) {
    }

    delete [] tarr;
}

void replaceAt_test() {
    char *tarr = new char[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'd';
    tarr[3] = 'e';
    CharArrayList rchar = CharArrayList(tarr, 4);
    rchar.replaceAt('c', 2);
    assert(rchar.elementAt(2) == 'c');
    assert(rchar.size() == 4);
    try {
       rchar.elementAt(5);
       rchar.elementAt(-1);
       assert(false);
    } catch (range_error) {
    }

    delete [] tarr;
}

void concatenate_test() {
    char *tarr = new char[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'd';
    tarr[3] = 'e';

    char *tarr2 = new char[4];
    tarr2[0] = 'a';
    tarr2[1] = 'b';
    tarr2[2] = 'd';
    tarr2[3] = 'e';
    CharArrayList charArr = CharArrayList(tarr, 4);
    CharArrayList charArr2 = CharArrayList(tarr2, 4);
    charArr.concatenate(&charArr2);
    assert(charArr.elementAt(2) == 'd');
    assert(charArr.elementAt(6) == 'd');
    assert(charArr.elementAt(5) == 'b');
    assert(charArr.first() == 'a');
    assert(charArr.last() == 'e');

    try {
       CharArrayList empty = CharArrayList();
       empty.first(); 
       assert(false);
    } catch (runtime_error) {
    }

    delete [] tarr;
    delete [] tarr2;
}

void expand_shrink_test() {
     char *tarr = new char[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'd';
    tarr[3] = 'e';
    CharArrayList charArr = CharArrayList(tarr, 4);

    charArr.pushAtBack('a');
    charArr.pushAtBack('b');
    charArr.pushAtBack('c');
    charArr.pushAtBack('d');
    charArr.pushAtBack('e');

    assert(charArr.size() == 9);
    
    charArr.pushAtBack('f');
    //now capacity should be 16

    charArr.shrink();
    delete [] tarr;
}

//resize is tested as part of the expand test
//calling shrink in main but since capacity is private, 
//I'm assuming a non-seg fault means that shrink works properly


int main() {
    constructor_test();
    assignment_test();
    empty_test();
    clear_test();
    size_test();
    first_test();
    last_test();
    elementAt_test();
    toString_test();
    toReverseString_test();
    pushAtBack_test();
    pushAtFront_test();
    insertAt_test();
    insertInOrder_test();
    popFromFront();
    popFromBack();
    replaceAt_test();
    concatenate_test();
    expand_shrink_test();
}