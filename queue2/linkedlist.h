#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "baseNode.h"

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

enum LINKEDLISTERRORS {EMPTYLINKEDLIST_ERROR,FULLLINKEDLIST_ERROR};

template<typename T>
class linkedList
{
    public:
        linkedList(int maxSize = 10);
        virtual ~linkedList();
        linkedList(const linkedList &other);
        linkedList operator = (const linkedList &other);

        bool empty();
        bool full();
        unsigned int size();
        unsigned int max_size();

//        void insertTail(T data);
        void insertanchor(T data);
        T remove();
        void erase(void *whom);
        void resize(unsigned int s);
//        T font() const;
//        T& back() const;



        template<typename R>
        friend
        ostream& operator<<(ostream& out, const linkedList<R> &s);

        template<typename R>
        friend
        istream& operator>>(istream& in, linkedList<R> &s);

    protected:
        baseNode<T> *anchor;
        unsigned int qty, maxQty;

    private:
        void copy(const linkedList &other);
        void nukem();
};

template<typename T>
linkedList<T>::linkedList(int maxSize)
{
    qty = 0;
    maxQty = maxSize;
    anchor = NULL;
}

template<typename T>
linkedList<T>::~linkedList()
{
    nukem();
}

template<typename T>
linkedList<T>::linkedList(const linkedList &other)
{
    copy(other);
}

template<typename T>
linkedList<T> linkedList<T>::operator =(const linkedList<T> &other)
{
    if(this != &other)
    {
        nukem();
        copy(other);
    }
    return *this;
}


template<typename T>
bool linkedList<T>::empty()
{
    return !anchor;
}

template<typename T>
bool linkedList<T>::full()
{
    return qty == maxQty;
}

template<typename T>
unsigned int linkedList<T>::size()
{
    return qty;
}

template<typename T>
unsigned int linkedList<T>::max_size()
{
    return maxQty;
}


// tail will be added to the queue
//template<typename T>
//void linkedList<T>::insertTail(T data)
//{
//    if(qty == maxQty)
//            throw FULLLINKEDLIST_ERROR;

//        baseNode<T> *newNode = new baseNode<T> (data);


//        //when it's empty
//        if(empty())
//        {
//            anchor = tail = newNode;

//        }
//        // when it's not empty add data to the tail
//        else
//        {
//            //link the tail's next node to the newNode
//            // set the newNode to be the last node in the list
//            tail->nextNode() = newNode;
//            tail = newNode;
//        }
//        ++qty;
//}

template<typename T>
void linkedList<T>::insertanchor(T data)
{

    if(qty == maxQty)
            throw FULLLINKEDLIST_ERROR;

    baseNode<T> *newNode = new baseNode<T> (data);


    //when it's empty
    if(!anchor)
    {
        anchor = newNode;

    }
    else
    {
        //point newNode next to the anchor
        //point anchor to the newNode;
        newNode->nextNode() = anchor;
        anchor = newNode;
    }
    qty++;
}

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

template<typename T>
void linkedList<T>::resize(unsigned int s)
{
    nukem();
    maxQty = s;
}

template<typename T>
T linkedList<T>::font() const
{
    if(!anchor)
        throw EMPTYLINKEDLIST_ERROR;
    return anchor->getData();
}

template<typename R>
ostream& operator<<(ostream& out, const linkedList<R> &s)
{
    baseNode<R> *ptr = s.anchor;
   // baseNode<R> *ptrt = s.tail;
    for(; ptr; ptr = ptr->nextNode())
        out<<"Data: "<<ptr->getData()<<endl;
    return out;
}

template<typename R>
istream& operator>>(istream& in, linkedList<R> &s)
{
    baseNode<R> newNode;
    while(in>>newNode)
        s<<newNode.getData();
    return in;
}


template<typename T>
void linkedList<T>::copy(const linkedList &other)
{    cout << "copy here0\n";

    //this->qty = other.qty; // don't need this cuz insert will add the size
    this->maxQty = other.maxQty;
    int i = 0;

    // loop the other list and get each data then insert it into the call list
    for(baseNode<T> *ptr = other.anchor; ptr; ptr = ptr->nextNode())
    {
        std::cout<<"copydata: "<<ptr->getData()<<" index: "<<i<<"\n";
        this->insertanchor(ptr->getData());
        ++i;
    }

    this->qty = other.qty;
    std::cout<<"size in copy after copying: "<<qty<<std::endl;

}

template<typename T>
void linkedList<T>::nukem()
{
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


#endif // BASENODE_H
