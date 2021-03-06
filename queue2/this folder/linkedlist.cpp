#include "linkedlist.h"

template<typename T>
linkedList<T>::linkedList(int maxSize)
{
    qty = 0;
    maxQty = maxSize;
    head = tail = NULL;
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
    if(this != other)
    {
        nukem();
        copy(other);
    }
    return *this;
}


template<typename T>
bool linkedList<T>::empty()
{
    return !head;
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

template<typename T>
void linkedList<T>::insertTail(T data)
{
    if(qty == maxQty)
            throw FULLLINKEDLIST_ERROR;

        baseNode<T> *newNode = new baseNode<T> (data);


        //when it's empty
        if(!head)
        {
            head = tail = newNode;
        }
        // when it's not empty add data to the tail
        else
        {
            //link the tail's next node to the newNode
            // set the newNode to be the last node in the list
            tail->nextNode() = newNode;
            tail = newNode;
        }
        ++qty;
}

template<typename T>
T linkedList<T>::remove()
{
    if(!head)
        throw EMPTYLINKEDLIST_ERROR;

    // get data and move head to the next node
    T d = head->getData();
    baseNode<T> temp = head;
    head = head->nextNode();

    // if the list is empty set head and tail to be empty
    if(!head)
        head = tail = NULL;

    //remove and return
    delete temp;
    return d;
}

template<typename T>
void linkedList<T>::resize(unsigned int s)
{
    nukem();
    maxQty = s;
}

template<typename T>
T &linkedList<T>::font() const
{
    if(empty())
        throw EMPTYLINKEDLIST_ERROR;
    return head->getData();
}


template<typename T>
void linkedList<T>::copy(const linkedList &other)
{
    qty = other.qty;
    maxQty = other.maxQty;

    // loop the other list and get each data then insert it into the call list
    for(baseNode<T> *ptr = other.head; ptr; ptr = ptr->nextNode())
        insert(ptr->getData());
}

template<typename T>
void linkedList<T>::nukem()
{
    for(baseNode<T> *ptr = head; ptr; ptr = head)
    {
        head = head->nextNode();
        delete ptr;
    }

    qty = 0;
    maxQty = 0;
    head = tail = NULL;
}

template<typename T>
T &linkedList<T>::back() const
{
    return tail->getData();
}
