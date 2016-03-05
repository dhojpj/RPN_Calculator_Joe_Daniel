#ifndef BASENODE_H
#define BASENODE_H

#include <iostream>

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

    baseNode& operator<<(T d);
    baseNode& operator>>(T& d);

    // const at the end prevents changes to *this
    bool operator<(const baseNode &x) const;
    bool operator<=(const baseNode &x) const;
    bool operator>(const baseNode &x) const;
    bool operator>=(const baseNode &x) const;
    bool operator==(const baseNode &x) const;
    bool operator!=(const baseNode &x) const;

    template<typename R>
    friend ostream& operator<<(ostream& out, const baseNode<R>& whom);

    template<typename R>
    friend istream& operator>>(istream& in, baseNode<R>& whom);

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
    return data <= x.data;
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
ostream& operator<<(ostream& out, const baseNode<R>& whom)
{
    if (out == cout)
    {
        out << "Data: " << whom.getData();
    }
    else // writing to a file
    {

    }

    return out;
}

template<typename T>
baseNode<T>& baseNode<T>::operator<<(T d)
{
    this->data = d;

    return *this;
}

// this is more straightforward writing
// got rid of the menu; let the children take care of the file writing
//need file read data ++++++++++++++++++++++++++++++++++++++++++++++++++
template<typename R>
istream& operator>>(istream& in, baseNode<R>& whom)
{
    in >> whom.data;

    return in;
}

template<typename T>
baseNode<T>& baseNode<T>::operator>>(T& d)
{
    d = this->data;

    return *this;
}


#endif // BASENODE_H
