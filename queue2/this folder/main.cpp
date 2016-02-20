
#include "linkedlist.h"
#include "baseNode.h"
#include <iostream>
#include <string>
#include "queue2.h"
#include "queue.h"

using namespace std;
void test1();

int main()
{
    // test out insertfrom tail and from head
    linkedList<string> str;
    str.insertTail("first");
    str.insertTail("second");
    str.insertTail("third");




    cout<<str.remove()<<endl;
    cout<<str.remove()<<endl;
    cout<<str.remove()<<endl;


    for(int i = 0; i < 5; i++)
    {
        str.insertHead(to_string(i));
    }

    for(int i = 0; i < 5; i++)
    {
        cout<<str.remove()<<endl;
    }


    //testing linked list with objects
    linkedList<baseNode<int>> intNode;
    baseNode<int> intNode1(12);
    intNode.insertTail(intNode1);
    cout<<intNode.remove().getData()<<endl;

    cout << "int2   0\n";


    // testing copy contructor and assignment operator
    linkedList<int> int2, intcopy1, intassign;
    for(int i = 0; i < 5; ++i)
    {
        int2.insertTail(i);
    }

        cout << "int2   1\n";

    cout<<"int2 size"<<int2.size()<<endl;

// why doesn't this print all five data?
    cout<<int2<<endl;

    //create a linked list using copy constructor
    cout << "testing here0\n";

    linkedList<int> intcopy(int2);
    cout << "testing here00\n";

    cout<<"copied: "<<intcopy<<endl;
    cout<<"int copy copy size: "<<intcopy.size()<<endl;

    //remove and print
    cout << "testing here1\n";

    cout<<int2.remove()<<endl;
    cout << "testing here2\n";

    cout<<int2.remove()<<endl;
    cout << "testing here3\n";

    cout<<intcopy.font()<<endl;
    cout << "testing here4\n";


    intassign = int2;
    cout<<"intass: "<<intassign<<endl;
    return 0;
}


void test1()
{
    string str1;
    queue<string> strq;
    cout<<"is empty should be 1: "<<strq.empty()<<endl;

    cout<<"size should be 0: "<<strq.size();
    strq.enqueue("ss:)");
    strq.enqueue("ada");
    cout<<endl<<strq<<endl;
    strq.dequeue(str1);
    cout<<"should be \"ss:)\" : "<<str1;
    cout<<"size should be 1: "<<strq.size()<<endl;
    cout<<"is empty should be 0: "<<strq.empty()<<endl;
    strq.clear();
    cout<<"size should be 0: "<<strq.size()<<endl;
    cout<<"is empty should be 1: "<<strq.empty()<<endl;




    qqueue<char> qa;
    char c = 'c';
    char b = 'b';
    char d = 'd';
    char z;
    qa.enqqueue(b);
    qa.enqqueue(d);
    qa.enqqueue(c);

    qa.deqqueue(z);
    cout<<"should be 'c': "<<c<<endl;
    qa.deqqueue(z);
    cout<<"should be 'b': "<<z<<endl;
    cout<<"is empty? "<<qa.empty();



}
