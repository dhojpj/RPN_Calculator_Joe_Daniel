
#include "linkedlist.h"
#include "baseNode.h"
#include <iostream>
#include <string>
#include "queue2.h"
#include "queue.h"
#include <stdio.h>
#include <time.h>
using namespace std;

int main()
{
    srand(time(NULL));

    linkedList<int>* l = new linkedList<int>;

    for (int i = 0; i < 10; ++i)
        l->inserHead(rand() % 100);
    cout << *l << endl;

    return 0;
}


