


#include "linkedlist.h"
#include "baseNode.h"


#ifndef queue2_H
#define queue2_H


template<typename T>
class qqueue :public linkedList<T>
{
public:
        qqueue(size_t s = 10);
        ~qqueue();
        qqueue(const qqueue<T>& other);
        qqueue<T>& operator=(const qqueue<T>& other);

        bool full();
        bool empty();
        size_t max_size();
        size_t size();
        void clear();
        void resize(size_t s);
        qqueue<T>& operator<<(const T& data);
        qqueue<T>& operator>>(T &data);
        void enqqueue(const T& data);
        void deqqueue(T &data);
        T& front() const;

        template<typename Y>
        friend
        ostream& operator<<(ostream &out, const qqueue<Y>& q);

        template<typename Y>
        friend
        istream& operator>>(istream &in, qqueue<Y>& q);

    private:
        linkedList<T>* container;
        size_t  maxQty, qty;

        void copy(const qqueue<T>& other);
        void nukem();

};



template<typename T>
qqueue<T>::qqueue(size_t s)
{
    maxQty = s;
    qty = 0;
    container = new linkedList<T>(s);
}

template<typename T>
qqueue<T>::~qqueue()
{
    nukem();
    qty = maxQty = 0;
}

template<typename T>
qqueue<T>::qqueue(const qqueue<T>& other)
{
   copy(other);
}


template<typename T>
qqueue<T>& qqueue<T>::operator=(const qqueue<T> &other)
{
    if(this != other)
    {
        nukem();
        copy(other);
    }
    return *this;
}


template<typename T>
bool qqueue<T>::full()
{
    return container->full();
}


template<typename T>
bool qqueue<T>::empty()
{
    return container->empty();
}


template<typename T>
size_t qqueue<T>::max_size()
{
    return container->max_size();
}

template<typename T>
size_t qqueue<T>::size()
{
    return container->size();
}

template<typename T>
void qqueue<T>::clear()
{
    nukem();
}


template<typename T>
void qqueue<T>::resize(size_t s)
{
    container->resize(s);
}


template<typename T>
qqueue<T>& qqueue<T>::operator<<(const T& data)
{
    enqqueue(data);
    //container->insertTail(data);
    return *this;
}


template<typename T>
qqueue<T>& qqueue<T>::operator>>(T &data)
{
    deqqueue(data);
    //data = container->remove();
    return *this;
}


template<typename T>
void qqueue<T>::enqqueue(const T&data)
{
    container->insertTail(data);
}


template<typename T>
void qqueue<T>::deqqueue(T &data)
{
    data = container->remove();
}


template<typename T>
T& qqueue<T>::front() const
{
    return container->font();
}

template<typename T>
T &linkedList<T>::back() const
{

    return tail->getData();
}

template<typename T>
void qqueue<T>::copy(const qqueue<T>& other)
{
    container = other.container;
}


template<typename T>
void qqueue<T>::nukem()
{
    while(!container->empty())
    {
        container->remove();
    }
}


template<typename Y>
ostream& operator<<(ostream &out, const qqueue<Y>& q)
{
    return out;
}

template<typename Y>
istream& operator>>(istream &in, qqueue<Y>& q)
{
    return in;
}




#endif // qqueue2_H
