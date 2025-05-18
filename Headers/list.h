#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <cstdlib>
#include <iostream>
#include <string>

#include "listexception.h"

template <class T, int ARRAYSIZE = 500>
class List {
    private:
        T data[ARRAYSIZE];
        int last;

        bool isValidPosition(const int&);
        void copyAll(const List<T, ARRAYSIZE>&);
    
    public:
        List();
        List(const List<T, ARRAYSIZE>&);
        
        bool isEmpty();
        bool isFull();

        void insertElement(const int&, const T&);
        void deleteElement(const int&);
        
        int getFirstPosition();
        int getLastPosition();
        int getPreviousPosition(const int&);
        int getNextPosition(const int&);

        T getElement(const int&);

        std::string toString();

        void deleteAll();

        List<T, ARRAYSIZE>& operator = (const List<T, ARRAYSIZE>&);
};

using namespace std;

// Private

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::copyAll(const List<T, ARRAYSIZE>& l) {
    int i(0);
    while(i <= l.last) {
        data[i] = l.data[i];
        i++;
    }
    last = l.last;
}

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isValidPosition(const int& pos) {
    return pos >= 0 and pos <= last;
}

// Public

template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List() : last(-1) {}

template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List(const List<T, ARRAYSIZE>& l) {
    copyAll(l);
}

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isEmpty() {
    return last == -1;
}

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isFull() {
    return last == ARRAYSIZE - 1;
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::insertElement(const int& pos, const T& e) {
    if(isFull()) {
        throw ListException("[insertElement] The list is full; no more elements can be inserted.");
    }

    if(pos != -1 and !isValidPosition(pos)) {
        throw ListException("[insertElement] The position is invalid.");
    }

    int i(last);
    while(i > pos) {
        data[i + 1] = data[i];
        i--;
    }

    data[pos + 1] = e;
    last++;
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::deleteElement(const int& pos) {
    if(!isValidPosition(pos)) {
        throw ListException("[deleteElement] The position is invalid.");
    }

    int i(last);
    while(i < last) {
        data[i] = data[i + 1];
        i++;
    }

    last--;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getFirstPosition() {
    if(isEmpty()) {
        return -1;
    }

    return 0;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getLastPosition() {
    return last;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getPreviousPosition(const int& pos) {
    if(pos == getFirstPosition() or !isValidPosition(pos)) {
        return -1;
    }

    return pos - 1;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getNextPosition(const int& pos) {
    if(pos == getLastPosition() or !isValidPosition(pos)) {
        return -1;
    }

    return pos + 1;
}

template <class T, int ARRAYSIZE>
T List<T, ARRAYSIZE>::getElement(const int& pos) {
    if(!isValidPosition(pos)) {
        throw ListException("[getElement] The position is invalid.");
    }

    return data[pos];
}

template <class T, int ARRAYSIZE>
string List<T, ARRAYSIZE>::toString() {
    string result;
    int i(0);

    while(i <= last) {
        result += data[i].toString() + "\n";
        i++;
    }

    result += "\n";
    return result;
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::deleteAll() {
    last = -1;
}

template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>& List<T, ARRAYSIZE>::operator = (const List<T, ARRAYSIZE>& l) {
    copyAll(l);
    
    return *this;
}

#endif // LIST_H_INCLUDED