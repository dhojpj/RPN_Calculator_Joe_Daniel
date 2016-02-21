#include <iostream>
#include "fraction.h"
#include "mixed.h"

using namespace std;

int main()
{
//    mixed a,b,c;
//    c = a + b;


    fraction f(1,2);
    fraction c(1,2);
    fraction a, b(22,2), d(1,4),z;
    cout<<"before"<<endl;
    z = b - 2;

    cout<<"z: "<<z<<endl;
    cout<<"z: "<<(f - c)<<endl;
    return 0;
}

