#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "baseNode.h"

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

enum LINKEDLISTERRORS {EMPTYLINKEDLIST_ERROR, FULLLINKEDLIST_ERROR};

template<typename T>
class linkedList
{
public:
    linkedList(int maxSize = 10);
    virtual ~linkedList();
    linkedList(const linkedList &other);
    linkedList operator=(const linkedList &other);

    bool empty();
    bool full();

    unsigned int size();
    unsigned int max_size();

    T remove();
    void resize(unsigned int s);

    template<typename R>
    friend ostream& operator<<(ostream& out, const linkedList<R> &s);

    template<typename R>
    friend istream& operator>>(istream& in, linkedList<R> &s);


//==========================================================================================
    // should be protected
    void insert(T data);
    void erase(void *whom);

protected:
    baseNode<T> *anchor;
    unsigned int qty, maxQty;




private:
    void copy(const linkedList &other);
    void nukem();
};

// CHECKED
template<typename T>
linkedList<T>::linkedList(int maxSize)
{
    qty = 0;
    maxQty = maxSize;
    anchor = NULL;
}

//========================= this doesn't seem to be calling
template<typename T>
linkedList<T>::~linkedList()
{
        cout << "destructed " << this << endl;
    nukem();
}

// CHECKED, works not for lhs pointer
template<typename T>
linkedList<T>::linkedList(const linkedList &other)
{
    copy(other);
}

// CHECKED
template<typename T>
linkedList<T> linkedList<T>::operator=(const linkedList<T> &other)
{
    if(this != &other)
    {
        nukem();
        copy(other);
    }
    return *this;
}

// CHECKED
template<typename T>
bool linkedList<T>::empty()
{
    return !qty;
}

// CHECKED
template<typename T>
bool linkedList<T>::full()
{
    return qty == maxQty;
}

// CHECKED
template<typename T>
unsigned int linkedList<T>::size()
{
    return qty;
}

// CHECKED
template<typename T>
unsigned int linkedList<T>::max_size()
{
    return maxQty;
}

// CHECKED
template<typename T>
void linkedList<T>::insert(T data)
{    

    if(qty == maxQty)
            throw FULLLINKEDLIST_ERROR;

        baseNode<T> *newNode = new baseNode<T> (data);


        //when it's empty
        if(!anchor)
        {
            anchor = newNode;
        }
        // when it's not empty add data to the tail
        else
        {
            //link the tail's next node to the newNode
            // set the newNode to be the last node in the list
            newNode->nextNode() = anchor;
            anchor = newNode;
        }
        ++qty;


    /*
     * if(qty == maxQty)
        throw FULLLINKEDLIST_ERROR;

    // constructing with the data in parameter
    baseNode<T> *newNode = new baseNode<T>(data);
    ++qty;
    //+++++++++++++++++++++++++++this line just makes sure the addresses are the same when repointing
    cout << newNode << "   " << data << endl;

    //when it's empty
    if(!anchor)
    {
        anchor = newNode; // and newNode's next is already NULL
    }
    else
    {
        baseNode<T> *i = anchor;
        for(;   // while there's a nextnode an the next is less than the data
            i->nextNode() && i->nextNode()->getData() < data;
            i = i->nextNode());


        // if the data entered is less than the anchor
        if ((anchor == i) && (i->getData() > data))
        {
            newNode->nextNode() = anchor;
            anchor = newNode;
            return;
        }
        else if (!i) // or if it gets to the end without finding anything
        {
            i->nextNode() = newNode;
            return;
        }

        // no need for else bracket
        // but it's found something where data is bigger than previous node
        // so the data must be
        newNode->nextNode() = i->nextNode();
        i->nextNode() = newNode;
    }
*/
}

// CHECKED
template<typename T>
T linkedList<T>::remove()
{
    if(!anchor)
        throw EMPTYLINKEDLIST_ERROR;

    // get data and move anchor to the next node
    T d = anchor->getData();

    baseNode<T> *temp = anchor;
    anchor = anchor->nextNode();

    // if the list is empty set anchor and tail to be empty
    if(!anchor)
        anchor = NULL;

    //remove and return
    delete temp;
    --qty;
    return d;
}

// CHECKED
template<typename T>
void linkedList<T>::resize(unsigned int s)
{
    nukem();
    maxQty = s;
}


// CHECKED
template<typename T>
void linkedList<T>::copy(const linkedList &other)
{
    this->maxQty = other.maxQty;

    for(baseNode<T> *ptr = other.anchor; ptr; ptr = ptr->nextNode())
    {
        this->insert(ptr->getData());
    }

//    technically we don't even need this line because insert increments everything
//    this->qty = other.qty;
}

//CHECKED
template<typename T>
void linkedList<T>::nukem()
{
    cout << "nuking " << this << endl;

    for(baseNode<T> *ptr = anchor; ptr; ptr = anchor)
    {
        anchor = anchor->nextNode();
        ptr->setData(T());
        delete ptr;
    }

    qty = 0;
    maxQty = 0;
    anchor = NULL;
}

//+++++++++FIX THE OUTPUT TO THE PREVIOUS //
// NEED FILE WRITE
template<typename R>
ostream& operator<<(ostream& out, const linkedList<R> &s)
{
    baseNode<R> *ptr = s.anchor;

    for(; ptr; ptr = ptr->nextNode())
//        out<<"Data: "<<ptr->getData()<<endl;
        out<< ptr << "    " << ptr->getData()<<endl;
    return out;
}

//==================NEED TO CHECK THIS================
// NEED FILE READ
template<typename R>
istream& operator>>(istream& in, linkedList<R> &s)
{
    baseNode<R> newNode;
    while(in>>newNode)
        s<<newNode.getData();
    return in;
}


#endif // BASENODE_H
