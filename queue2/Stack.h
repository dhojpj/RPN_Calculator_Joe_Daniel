#ifndef Stack_H
#define Stack_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include "linkedlist.h"

// might need cout and cin
using std::ostream;
using std::istream;
using std::endl;

enum STACK_ERRORS {STACK_EMPTY, STACK_FULL, INVALID_MAXSIZE};

template<typename T>
class Stack
{
public:
    Stack(size_t maxSize = 10);
    ~Stack();
    Stack(const Stack<T> &s);
    Stack<T>& operator=(const Stack<T> &s);

    size_t size();
    size_t max_size();

    bool empty();
    bool full();
    void clear();
    void resize(size_t newSize);

    void push(const T &d);
    T pop();
    T top();

    Stack<T>& operator<<(const T &d); //Chainable push
    Stack<T>& operator>>(T &d); // Chainable pop

    template<typename R>
    friend ostream& operator<<(ostream& out, const Stack<R> &s);

    template<typename R>
    friend istream& operator>>(istream& in, Stack<R> &s);

private:
    size_t qty, max_qty;

    void copy(const Stack<T> &s);
    void nukem();
};



template<typename T>
Stack<T>::Stack(size_t maxSize)
{
//    linkedList<T> *s = new linkedList<T>(maxSize);
//    max_qty = maxSize;

//    this = s;
}

template<typename T>
Stack<T>::~Stack()
{

}

template<typename T>
Stack<T>::Stack(const Stack<T> &s)
{

}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T> &s)
{

}

template<typename T>
size_t Stack<T>::size()
{

}

template<typename T>
size_t Stack<T>::max_size()
{

}

template<typename T>
bool Stack<T>::empty()
{

}


template<typename T>
bool Stack<T>::full()
{

}

template<typename T>
void Stack<T>::clear()
{

}

template<typename T>
void Stack<T>::resize(size_t newSize)
{

}

template<typename T>
void Stack<T>::push(const T &d)
{

}

template<typename T>
T Stack<T>::pop()
{

}

template<typename T>
T Stack<T>::top()
{

}






template<typename T>
Stack<T>& Stack<T>::operator<<(const T &d)
{

}

template<typename T>
Stack<T>& Stack<T>::operator>>(T &d)
{

}




template<typename T>
void Stack<T>::copy(const Stack<T>& s)
{

}

template<typename T>
void Stack<T>::nukem()
{

}




//friends
template<typename R>
ostream& operator<<(ostream& out, const Stack<R> &s)
{

}

template<typename R>
istream& operator>>(istream& in, Stack<R> &s)
{

}

#endif // Stack_H
