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
    c += 2;
    cout<< "sum :"<<c <<endl;

//    cout << f.gcd(f.numerator(), f.denominator()) << endl;
//    f.reduce();
    cout << f << endl;

    return 0;
}

