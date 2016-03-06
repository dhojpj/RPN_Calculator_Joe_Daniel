#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include "Node.h"
// use void pointers?
using std::cin;
using std::cout;
using std::ostream;
using std::istream;
using std::endl;
using std::string;

enum QUEUE_ERRORS {QUEUE_EMPTY, QUEUE_FULL, BAD_QUEUE_SIZE};

template<typename T>
class Queue
{
public:
    Queue(unsigned int s = 10);
    ~Queue();
    Queue(const Queue<T>& other);
    Queue<T>& operator=(const Queue<T>& other);

    bool full();
    bool empty();
    unsigned int max_size();
    unsigned int size();
    void clear();
    void resize(unsigned int s);
    Queue<T>& operator<<(const T& data);
    Queue<T>& operator>>(T& data); // return a queue to chain it
    void enqueue(const T& data); // starting at the tail
    void dequeue(T& data);
    T& front() const; // so can't change it and won't fire a copy constructor // how??

    // friends for when two objects are interacting with each other
    template<typename R>
    friend ostream& operator<<(ostream& out, const Queue<T>& q);

    template<typename R>
    friend istream& operator>>(istream& in, Queue<R>& q);

private:
    Node<T> *head, *tail;
    unsigned int qty, max_qty;
    void copy(const Queue<T>& other);
    void nukem();
};

template<typename T>
Queue<T>::Queue(unsigned int s)
{
    qty = 0;
    max_qty = s;
    head = tail = NULL;
}

template<typename T>
Queue<T>::~Queue()
{

}

template<typename T>
Queue<T>::Queue(const Queue<T>& other)
{
    copy(other);
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{

}

template<typename T>
bool Queue<T>::full()
{

}

template<typename T>
bool Queue<T>::empty()
{

}

template<typename T>
unsigned int Queue<T>::max_size()
{

}

template<typename T>
unsigned int Queue<T>::size()
{

}

template<typename T>
void Queue<T>::clear()
{

}

template<typename T>
void Queue<T>::resize(unsigned int s)
{

}

template<typename T>
Queue<T>& Queue<T>::operator<<(const T& data)
{

}

template<typename T>
Queue<T>& Queue<T>::operator>>(T& data)
{

}
// return a queue to chain it
template<typename T>
void Queue<T>::enqueue(const T& data)
{

}

// starting at the tail
template<typename T>
void Queue<T>::dequeue(T& data)
{

}

template<typename T>
T& Queue<T>::front() const
{} // so can't change it and won't fire a copy constructor // how??

template<typename T>
void Queue<T>::copy(const Queue<T>& other)
{

}


template<typename T>
void Queue<T>::nukem()
{

}


// friends for when two objects are interacting with each other
template<typename R>
ostream& operator<<(ostream& out, const Queue<R>& q)
{

}


template<typename R>
istream& operator>>(istream& in, Queue<R>& q)
{

}






#endif // QUEUE_H
