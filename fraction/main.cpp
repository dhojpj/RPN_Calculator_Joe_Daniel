#include <iostream>
#include "fraction.h"
#include "mixed.h"

using namespace std;
void test_constructor();
void test_boolean_double();
void addition();

int main()
{

    /// comment in the test u want u run
    fraction half(11,2);
    //test_constructor();

    //test_boolean_double();
    addition();
    return 0;
}

void test_constructor()
{
    int     one = 1;
    int     two = 2;

    //    int& numerator();
    //    int& denominator();
    cout<<"Created fraction 1/2 using numerator = "<<one<<", denominator = "<<two<<". "<<endl;
    fraction half(one,two);
    cout<<"Fraction output: "<<half<<endl<<endl;

    cout<<"Created fraction 1/2 using numerator = 1, denominator = -2.  "<<endl;
    fraction negative_half(1,-2);
    cout<<"Fraction output: "<<negative_half<<endl<<endl;

    cout<<"Created fraction 1/2 using numerator = -1, denominator = -2. "<<endl;
    fraction __half(-1,-2);
    cout<<"Fraction output: "<<__half<<endl<<endl;

    cout<<"Created fraction 1/2 using numerator = -1, denominator = 2. "<<endl;
    fraction __1half(-1,2);
    cout<<"Fraction output: "<<__1half<<endl<<endl;

    cout<<"Created fraction using integer 2.0. "<<endl;
    fraction double_F(2.0);
    cout<<"Fraction output: "<<double_F<<endl<<endl;

    cout<<"Created fraction using 2.22222. "<<endl;
    fraction double_A(2.22222);
    cout<<"Fraction output: "<<double_A<<endl<<endl;

    cout<<"Created fraction using -2.333. "<<endl;
    fraction double_nega(-2.333);
    cout<<"Fraction output: "<<double_nega<<endl<<endl;

    cout<<"Created fraction using double 4.444. "<<endl;
    fraction double_pos(4.444);
    cout<<"Fraction output: "<<double_pos<<endl<<endl;

    //444 is consider type long
    // had trouble with int and double cuz the ambiguous error
    cout<<"Created fraction using double 444. "<<endl;
    fraction int_p(444);
    cout<<"Fraction output: "<<int_p<<endl<<endl;

    cout<<"Created fraction using double -88888. "<<endl;
    fraction int_p2(-88888);
    cout<<"Fraction output: "<<int_p2<<endl<<endl;

    cout<<"Created fraction using double 0. "<<endl;
    fraction int_p3(0);
    cout<<"Fraction output: "<<int_p3<<endl<<endl;
}

void test_boolean_double()
{
    fraction two_two(2.2);
    fraction half(1,2);
    fraction n_half(-1,2);
    fraction _11_5(11,5);
    fraction _3(3);
    fraction _3_33(3.3);

    cout<<"==Testing for double with greater than sign \">\""<<endl;
    cout<<"2.2 > 1/2: "<<(2.2 > half ? "true.":"false.")<<endl;
    cout<<"2.2 > -1/2: "<<(2.2 > n_half ? "true.":"false.")<<endl;
    cout<<"-2.2 > -1/2: "<<(-2.2 > n_half ? "true.":"false.")<<endl;
    cout<<"-2.2 > 1/2: "<<(-2.2 > half ? "true.":"false.")<<endl;
    cout<<"0.5 > 1/2: "<<(0.5 > half ? "true.":"false.")<<endl;

    cout<<endl<<endl;
    cout<<"==Testing for double with greater than or equal sign \">=\""<<endl;
    cout<<"2.2 >= 1/2: "<<(2.2 >= half ? "true.":"false.")<<endl;
    cout<<"2.2 >= -1/2: "<<(2.2 >= n_half ? "true.":"false.")<<endl;
    cout<<"-2.2 >= -1/2: "<<(-2.2 >= n_half ? "true.":"false.")<<endl;
    cout<<"-2.2 >= 1/2: "<<(-2.2 >= half ? "true.":"false.")<<endl;
    cout<<"0.5 >= 1/2: "<<(0.5 >= half ? "true.":"false.")<<endl;

    cout<<endl<<endl;
    cout<<"==Testing for double with greater than sign \"<\""<<endl;
    cout<<"2.2<1/2: "<<(2.2 < half ? "true.":"false.")<<endl;
    cout<<"2.2 < -1/2: "<<(2.2 < n_half ? "true.":"false.")<<endl;
    cout<<"-2.2 < -1/2: "<<(-2.2 < n_half ? "true.":"false.")<<endl;
    cout<<"-2.2 < 1/2: "<<(-2.2 < half ? "true.":"false.")<<endl;
    cout<<"0.5 < 1/2: "<<(0.5 < half ? "true.":"false.")<<endl;

    cout<<endl<<endl;
    cout<<"==Testing for double with greater than or equal sign \"<=\""<<endl;
    cout<<"2.2 <= 1/2: "<<(2.2 <= half ? "true.":"false.")<<endl;
    cout<<"2.2 <= -1/2: "<<(2.2 <= n_half ? "true.":"false.")<<endl;
    cout<<"-2.2 <= -1/2: "<<(-2.2 <= n_half ? "true.":"false.")<<endl;
    cout<<"-2.2 <= 1/2: "<<(-2.2 <= half ? "true.":"false.")<<endl;
    cout<<"0.5 <= 1/2: "<<(0.5 >= half ? "true.":"false.")<<endl;

    cout<<"2.2 == 1/2: "<<(2.2 == half ? "true.":"false.")<<endl;



}

void addition()
{
    fraction half(1,2);
    fraction one_third(1,3);
    fraction one(1);

    cout<<"half + 1/3: "<<(half+one_third)<<endl;
    cout<<".5+1/2: "<<(.5+half)<<endl;

}
