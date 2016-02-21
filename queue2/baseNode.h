#ifndef BASENODE_H
#define BASENODE_H

#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;


template<typename T>
class baseNode
{
public:
    baseNode(T uData = T()); // constructor
    baseNode(const baseNode& other); // copy constructor
    baseNode& operator=(const baseNode& other); // assignment operator

    T getData( ) const;
    void setData(T value);
    baseNode*& nextNode(); // lhs and rhs
    void setNext(baseNode* nNode);

    // const at the end prevents changes to *this
    bool operator<(const baseNode &x) const;
    bool operator<=(const baseNode &x) const;
    bool operator>(const baseNode &x) const;
    bool operator>=(const baseNode &x) const;
    bool operator==(const baseNode &x) const;
    bool operator!=(const baseNode &x) const;

    template<typename R>
    friend ostream& operator << (ostream& out, const baseNode<R>& whom);

    template<typename R>
    friend istream& operator >> (istream& in, baseNode<R>& whom);

protected:
    T data;
    baseNode* next; // link
private:
    void copy(const baseNode& other);

};

// constructor
template<typename T>
baseNode<T>::baseNode(T uData)
{
    data = uData;
    next = NULL;
}

template<typename T>
T baseNode<T>::getData() const
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

    return this;
}

template<typename T>
void baseNode<T>::copy(const baseNode<T>& other)
{
    data = other.data;
    next = other.next;
}


template<typename T>
bool baseNode<T>::operator<(const baseNode<T> &x) const
{
    return data < x.data;
}

template<typename T>
bool baseNode<T>::operator<=(const baseNode<T> &x) const
{
    return data < x.data;
}

template<typename T>
bool baseNode<T>::operator>(const baseNode<T> &x) const
{
    return data > x.data;
}

template<typename T>
bool baseNode<T>::operator>=(const baseNode<T> &x) const
{
    return data >= x.data;
}

template<typename T>
bool baseNode<T>::operator==(const baseNode<T> &x) const
{
    return data == x.data;
}

template<typename T>
bool baseNode<T>::operator!=(const baseNode<T> &x) const
{
    return data != x.data;
}

//need file write data ++++++++++++++++++++++++++++++++++++++++++++++++++
template<typename R>
ostream& operator << (ostream& out, const baseNode<R>& whom)
{
    if (out == cout)
    {
        out << "Data: " << whom.getData();
    }
    return out;
}

//need file read data ++++++++++++++++++++++++++++++++++++++++++++++++++
template<typename R>
istream& operator >> (istream& in, baseNode<R>& whom)
{
    if (in == cin)
    {
        cout << "Enter data: ";
        in >> whom.data;
    }
    return in;
}


#endif // BASENODE_H
