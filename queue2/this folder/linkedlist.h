#ifndef LINKEDLIST_H
#define LINKEDLIST_H



#include "baseNode.h"


enum LINKEDLISTERRORS {EMPTYLINKEDLIST_ERROR,FULLLINKEDLIST_ERROR};

template<typename T>
class linkedList
{
    public:
        linkedList(int maxSize = 10);
        //linkedList(){head=tail=NULL; maxQty = 10; qty = 0;}
        virtual ~linkedList();
        linkedList(const linkedList &other);
        linkedList operator = (const linkedList &other);

        bool empty();
        bool full();
        unsigned int size();
        unsigned int max_size();

        void insertTail(T data);
        void insertHead(T data);
        T remove();
        void erase(void *whom);
        void resize(unsigned int s);
        T font() const;
        T& back() const;



        template<typename R>
        friend
        ostream& operator<<(ostream& out, const linkedList<R> &s);

        template<typename R>
        friend
        istream& operator>>(istream& in, linkedList<R> &s);

    protected:
        baseNode<T> *head;
        baseNode<T> *tail;
//        void *head;
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
        if(empty())
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
void linkedList<T>::insertHead(T data)
{

    if(qty == maxQty)
            throw FULLLINKEDLIST_ERROR;

    baseNode<T> *newNode = new baseNode<T> (data);


    //when it's empty
    if(!head)
    {
        head = tail = newNode;

    }
    else
    {
        //point newNode next to the head
        //point head to the newNode;
        newNode->nextNode() = head;
        head = newNode;
    }
    qty++;
}

template<typename T>
T linkedList<T>::remove()
{
    if(!head)
        throw EMPTYLINKEDLIST_ERROR;

    // get data and move head to the next node
    T d = head->getData();

    baseNode<T> *temp = head;
    head = head->nextNode();

    // if the list is empty set head and tail to be empty
    if(!head)
        head = tail = NULL;

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
    if(!head)
        throw EMPTYLINKEDLIST_ERROR;
    return head->getData();
}

template<typename R>
ostream& operator<<(ostream& out, const linkedList<R> &s)
{
    baseNode<R> *ptr = s.head;
    baseNode<R> *ptrt = s.tail;
    for(; ptr&&(ptrt != ptr); ptr = ptr->nextNode())
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
    for(baseNode<T> *ptr = other.head; ptr&&(ptr!=tail); ptr = ptr->nextNode())
    {
        std::cout<<"copydata: "<<ptr->getData()<<" index: "<<i<<"\n";
        this->insertHead(ptr->getData());
        ++i;
    }

    this->qty = other.qty;
    std::cout<<"size in copy after copying: "<<qty<<std::endl;

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


#endif // BASENODE_H
