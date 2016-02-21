#include "fraction.h"

// constructor//?????????????????????????????????????????????????
fraction::fraction(int n, int d)
{
    setNum(n,d);
//    int sign = 1;
//    if(d == 0)
//        throw ZERO_DENOM;
//    denom < 0  ? sign = -1:sign = 1;
//    denom = sign*d;
//    num = sign*n;
}

// destructor
fraction::~fraction()
{
    num = 0;
    denom = 1;
}

fraction::fraction(int x)
{
    num = x;
    denom = 1;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++
fraction::fraction(double x)
{
    denom = 1;
    double tempX = x;

    while(tempX != (int) tempX)
    {
        tempX=tempX*10;
        denom *=10;

        std::cout<<"tempx: "<<tempX<<" tempX: int: "<<(int) tempX<<std::endl;
        //std::cout<<"texP : "<<tempX<<std::endl;

        // infinity loop here
        if(tempX > 1000000)
            break;

    }
    num = tempX;
    reduce();
}


fraction::fraction(const fraction &other)
{
    copy(other);
}

fraction& fraction::operator=(const fraction &other)
{
    if (this != &other)
    {
        num = other.num;
        denom = other.denom;
    }
    return *this;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++
fraction& fraction::operator=(int other)
{
    setNum(other, 1);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++
fraction& fraction::operator=(double other)
{
    fraction temp(other);
    num = temp.numerator();
    denom = temp.denominator();
}

void fraction::setValue(int n, int d)
{
    setNum(n,d);
}

fraction& fraction::operator+=(const fraction &other)
{   // (a*d+b*c)/b*d
    num = num*other.denom+denom*other.num;
    denom = denom*other.denom;

    this->reduce();
    return *this;
}

fraction& fraction::operator-=(const fraction &other)
{
    num = num*other.denom-denom*other.num;
    denom = denom*other.denom;
    this->reduce();
    return *this;
}
fraction& fraction::operator*=(const fraction &other)
{
    num = num*other.num;
    denom = denom*other.denom;

    this->reduce();
    return *this;
}
fraction& fraction::operator/=(const fraction &other)
{
    num = num*other.denom;
    denom = denom*other.num;

    this->reduce();
    return *this;
}
fraction& fraction::operator^=(const fraction &other)
{
    //not sure yet
}
fraction& fraction::operator+=(int other)
{
    fraction c(other,1);
    return *this+=c;
}
fraction& fraction::operator-=(int other)
{
    fraction c(other,1);
    return *this-=c;
}
fraction& fraction::operator*=(int other)
{
    fraction c(other,1);
    return *this*=c;
}
fraction& fraction::operator/=(int other)
{
    fraction c(other,1);
    return *this/=c;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++
fraction& fraction::operator^=(int other){}


fraction& fraction::operator+=(double other)
{
    fraction doubleOther(other);
    return *this+=doubleOther;

}
fraction& fraction::operator-=(double other)
{
    fraction doubleOther(other);
    return *this-=doubleOther;
}

fraction& fraction::operator*=(double other)
{
    fraction doubleOther(other);
    return *this*=doubleOther;
}

fraction& fraction::operator/=(double other)
{
    fraction doubleOther(other);
    return *this/=doubleOther;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++
fraction& fraction::operator^=(double other){}


void fraction::reduce()
{
    int g = abs(gcd(this->num, this->denom));

    if (g > 1)
    {
        this->num /= g;
        this->denom /= g;
    }

}

void fraction::setNum(int n, int d)
{
    int sign = 1;
    if(d == 0)
        throw ZERO_DENOM;
    denom < 0  ? sign = -1:sign = 1;
    denom = sign*d;
    num = sign*n;

}

int& fraction::numerator()
{
    return num;
}

int& fraction::denominator()
{
    return denom;
}



void fraction::copy(const fraction& other)
{
    num = other.num;
    denom = other.denom;
}

int fraction::gcd(int p, int q)
{
    return !q ? p : gcd(q,p%q);
}


// need to remove the first const
fraction& operator+(fraction &x, const fraction &y)
{
    int n = x.num*y.denom+x.denom*y.num;
    int d = x.denom*y.denom;
    fraction a (n,d);
    return a;

}

fraction& operator-(const fraction &x, const fraction &y)
{
    int n = x.num*y.denom-x.denom*y.num;
    int d = x.denom*y.denom;
    fraction *a = new fraction(n,d);
    return *a;
}

fraction& operator*(const fraction &x, const fraction &y)
{
    int n = x.num*y.num;
    int d = x.denom*y.denom;
    fraction a (n,d);
    return a;
}

fraction& operator/(const fraction &x, const fraction &y)
{
    int n = x.num*y.denom;
    int d = x.denom*y.num;
    fraction a (n,d);
    return a;
}

//+++++++++++++++++++++++++++++++++++++
fraction& operator^(const fraction &x, const fraction &y){}


fraction& operator+(const fraction &x, int y)
{


}

fraction& operator-(const fraction &x, int y)
{
    fraction c(y,1);
//    this->num = x.num*c.denom-x.denom*c.num;
//    this->denom = x.denom*c.denom;
//    cout<<c<<endl;
//    cout<<x<<endl;
//    cout<<"dd: "<<(x - c);
    return (x - c);
}

fraction& operator*(const fraction &x, int y){}

fraction& operator/(const fraction &x, int y){}

fraction& operator^(const fraction &x, int y){}

fraction& operator+(int x, const fraction &y){}

fraction& operator-(int x, const fraction &y){}

fraction& operator*(int x, const fraction &y){}

fraction& operator/(int x, const fraction &y){}

fraction& operator^(int x, const fraction &y){}


fraction& operator+(const fraction &x, double y){}

fraction& operator-(const fraction &x, double y){}

fraction& operator*(const fraction &x, double y){}

fraction& operator/(const fraction &x, double y){}

fraction& operator^(const fraction &x, double y){}

fraction& operator+(double x, const fraction &y){}

fraction& operator-(double x, const fraction &y){}

fraction& operator*(double x, const fraction &y){}

fraction& operator/(double x, const fraction &y){}

fraction& operator^(double x, const fraction &y){}


bool operator==(const fraction &x, const fraction &y){}

bool operator!=(const fraction &x, const fraction &y){}

bool operator<=(const fraction &x, const fraction &y){}

bool operator>=(const fraction &x, const fraction &y){}

bool operator<(const fraction &x, const fraction &y){}

bool operator>(const fraction &x, const fraction &y){}


bool operator==(const fraction &x, int y){}

bool operator!=(const fraction &x, int y){}

bool operator<=(const fraction &x, int y){}

bool operator>=(const fraction &x, int y){}

bool operator<(const fraction &x, int y){}

bool operator>(const fraction &x, int y){}

bool operator==(int x, const fraction &y){}

bool operator!=(int x, const fraction &y){}

bool operator<=(int x, const fraction &y){}

bool operator>=(int x, const fraction &y){}

bool operator<(int x, const fraction &y){}

bool operator>(int x, const fraction &y){}


bool operator==(const fraction &x, double y){}

bool operator!=(const fraction &x, double y){}

bool operator<=(const fraction &x, double y){}

bool operator>=(const fraction &x, double y){}

bool operator<(const fraction &x, double y){}

bool operator>(const fraction &x, double y){}

bool operator==(double x, const fraction &y){}

bool operator!=(double x, const fraction &y){}

bool operator<=(double x, const fraction &y){}

bool operator>=(double x, const fraction &y){}

bool operator<(double x, const fraction &y){}

bool operator>(double x, const fraction &y){}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
ostream& operator<<(ostream& out, const fraction &frac)
{

    if (&out == &cout)
    {
        cout << frac.num << "/" << frac.denom;
    }

}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
istream& operator>>(istream& in, fraction &frac)
{
    if (&in == &cin)
    {
        in >> frac.num >> frac.denom;
    }
}
