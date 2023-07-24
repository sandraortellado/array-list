/*
 *
 *  COMP 15 HW 1 Cheshire ConCATenation - no strings attached
 *
 *  CharArrayList.h
 *
 *  PURPOSE
 *  Define CharArrayList class
 *  Modified by: Sandra Ortellado
 *           on: 9/22/22
 *
 */

#ifndef CHARARRAYLIST_H_
#define CHARARRAYLIST_H_

#include <string>
#include <ostream>

using namespace std;


class CharArrayList
{
    public: 
        CharArrayList();
        CharArrayList(char c);
        CharArrayList(char input_arr[], int size);
        CharArrayList(const CharArrayList &other);
        void operator=(const CharArrayList &other);

        ~CharArrayList();
        bool isEmpty() const;
        void clear();
        int size() const;
        char first() const;
        char last() const;
        char elementAt(int index) const;
        string toString() const;
        string toReverseString() const;
        void pushAtBack(char c);
        void pushAtFront(char c);
        string recurseString(int size);
        void insertAt(char c, int index);
        void insertInOrder(char c);
        void popFromFront();
        void popFromBack();
        void removeAt(int index);
        void replaceAt(char c, int index);
        void concatenate(CharArrayList *other);
        void shrink();
        void expand();
        void resize(int newSize);

    private:
        static const int DEFAULT_SIZE = 5;
        char *arr; 
        int numItems;
        int capacity; 

        

};

#endif 