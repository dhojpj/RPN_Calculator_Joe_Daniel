#ifndef BASENODE_H
#define BASENODE_H


#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::ostream;
using std::istream;

template<typename T>
class baseNode
{
public:
        baseNode(T uData = T());

        T getData( ) const;
        void setData(T value);
        baseNode*& nextNode();

        void setNext(baseNode* nNode);

        baseNode(const baseNode& other);
        baseNode& operator = (const baseNode& other);


        bool operator<(const   baseNode &x)  const;
        bool operator<=(const  baseNode &x)  const;
        bool operator>(const   baseNode &x)  const;
        bool operator>=(const  baseNode &x)  const;
        bool operator==(const  baseNode &x)  const;
        bool operator!=(const  baseNode &x)  const;





    protected:
        T data;
        baseNode* next;
    private:
        void copy(const baseNode& other);

};

template<typename T>
baseNode<T>::baseNode(T uData)
{
    data = uData;
    next = NULL;
}

template<typename T>
T baseNode<T>::getData( ) const
{
    return data;
}

template<typename T>
void baseNode<T>::setData(T value)
{
    data = value;
}


template<typename T>
baseNode<T>*& baseNode<T>::nextNode()
{
    return next;
}

template<typename T>
void baseNode<T>::setNext(baseNode<T>* nextNode)
{
    next = nextNode;
}

template<typename T>
baseNode<T>::baseNode(const baseNode<T>& other)
{
    copy(other);
}

template<typename T>
baseNode<T>& baseNode<T>::operator = (const baseNode<T>& other)
{
    if(this != &other)
    {
        copy(other);
    }

    return *this;
}

template<typename T>
void baseNode<T>::copy(const baseNode<T>& other)
{
    data = other.data;
    next = other.next;
}


template<typename T>
bool baseNode<T>::operator<(const   baseNode<T> &x)  const
{
    return data < x.data;
}

template<typename T>
bool baseNode<T>::operator<=(const  baseNode<T> &x)  const
{
    return data < x.data;
}

template<typename T>
bool baseNode<T>::operator>(const   baseNode<T> &x)  const
{
    return data > x.data;
}

template<typename T>
bool baseNode<T>::operator>=(const  baseNode<T> &x)  const
{
    return data >= x.data;
}

template<typename T>
bool baseNode<T>::operator==(const  baseNode<T> &x)  const
{
    return data == x.data;
}

template<typename T>
bool baseNode<T>::operator!=(const  baseNode<T> &x)  const
{
    return data != x.data;
}

#endif // BASENODE_H
