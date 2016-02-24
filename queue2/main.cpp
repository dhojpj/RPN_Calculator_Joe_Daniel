
#include "linkedlist.h"
//#include "baseNode.h"
#include <iostream>
//#include <string>
//#include "queue2.h"
//#include "queue.h"
#include <stdio.h>
#include <time.h>
using namespace std;

int main()
{



    srand(time(NULL));

    linkedList<int>* l = new linkedList<int>;

    for (int i = 0; i < 10; ++i)
    {


        l->insert(rand() % 100);
    }



    linkedList<int>* m = new linkedList<int>;

    *m = *l;

    cout << endl << "l:\n" << *l << endl;
    cout << l->size() << endl << endl;
    cout << "m:\n" << *m << endl;
    cout << m->size() << endl << endl;

    return 0;
}


/*************baseNode.h SAMPLE RUN

    baseNode<int>* b = new baseNode<int>;

    cin>>*b;
    cout << * b << endl;

  ------------------

Enter data: 452345
Data: 452345
Press <RETURN> to close this window...




***************linkedList.h SAMPLE RUN

// NOTE: In order to run this, void insert(T data) needs to be public (not protected)

    srand(time(NULL));

    linkedList<int>* l = new linkedList<int>;

    int j;

    for (int i = 0; i < 10; ++i)
    {
        j = rand() % 100;

        cout << "j = " << j << endl;

        l->insert(j);
    }
    cout << endl << *l << endl;

---------------------
j = 91
j = 64
j = 42
j = 75
j = 29
j = 24
j = 0
j = 13
j = 89
j = 3

Data: 0
Data: 3
Data: 13
Data: 24
Data: 29
Data: 42
Data: 64
Data: 75
Data: 89
Data: 91

Press <RETURN> to close this window...

************************

 */
