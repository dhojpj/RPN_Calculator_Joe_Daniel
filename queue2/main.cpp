
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


    cout << "\nl = " << l << endl << *l << endl;
    cout << "l size = " << l->size() << endl;
    cout << "empty? " << l->empty() << endl;
    cout << "full? " << l->full() <<endl;

    for (size_t i = 0; i < l->max_size(); ++i)
    {

        cout << l->remove() << " is popped \n";

    }

    cout << "\nl = " << l << endl << *l << endl;
    cout << "l size = " << l->size() << endl;
    cout << "\nl = " << l << endl << *l << endl;
    cout << "empty? " << l->empty() << endl;
    cout << "full? " << l->full() <<endl <<endl;

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

    srand(time(NULL));

    linkedList<int>* l = new linkedList<int>;

    for (int i = 0; i < 10; ++i)
    {


        l->insert(rand() % 100);
    }


    cout << "\nl = " << l << endl << *l << endl;
    cout << l->size() << endl << endl;


    linkedList<int>* m = new linkedList<int>;

    *m = *l;

    cout << "m = " << m; //<< endl << *m << endl;
    cout << m->size() << endl << endl;

    l->resize(5);
    cout << "l = " << l << endl << *l << endl;
    cout << "l size = " << l->size() << "  l max = " << l->max_size() << endl << endl;

---------------------

0xb22e68   85
0xb22e78   57
0xb22f78   34
0xb22f88   10
0xb22f98   34
0xb22fa8   5
0xb22fb8   95
0xb22fc8   40
0xb22fd8   37
0xb20f88   13

l = 0xb22e50
0xb22fa8    5
0xb22f88    10
0xb20f88    13
0xb22f98    34
0xb22f78    34
0xb22fd8    37
0xb22fc8    40
0xb22e78    57
0xb22e68    85
0xb22fb8    95

10

0xb20fb0   5
0xb20fc0   10
0xb20fd0   13
0xb20fe0   34
0xb20ff0   34
0xb26d08   37
0xb21018   40
0xb21028   57
0xb21038   85
0xb21048   95
copy the object 0xb20f98
0xb21058   5
0xb21068   10
0xb21078   13
0xb21088   34
0xb21098   34
0xb210a8   37
0xb210b8   40
0xb210c8   57
0xb210d8   85
0xb210e8   95
destructed 0x28fe84
m = 0xb20f9810

l = 0xb22e50

l size = 0  l max = 5

Press <RETURN> to close this window...

************************



 */
