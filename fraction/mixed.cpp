#include "mixed.h"

mixed::mixed(int w, int n, int d)
{
    setValue((n+w*d),d);
}

mixed::mixed(const fraction& x)
{
    this->setValue(x.get_num(),x.get_denom());

}

mixed::mixed(long x)
{
    setValue((int)x,1);
}

mixed::mixed(double x)
{
    fraction temp(x);
    this->setValue(temp.get_num(),temp.get_denom());
}

mixed::mixed(const mixed &x):fraction(x.get_num(),x.get_denom())
{

}

mixed::mixed(int x, const fraction &f)
{
    //int*denom+num/ denom
    this->setValue((x*f.get_denom()+f.get_num()),f.get_denom());
}

mixed& mixed::operator=(const mixed &other)
{
    this->setValue(other.get_num(), other.get_denom());
    return *this;
}

mixed& mixed::operator=(int x)
{
    this->setValue(x,1);
    return *this;
}
mixed& mixed::operator=(double x)
{
   fraction temp(x);
   this->setValue(temp.get_num(), temp.get_denom());
   return *this;
}

mixed& mixed::operator=(const fraction &x)
{
    this->setValue(x.get_num(), x.get_denom());
    return *this;
}

mixed::~mixed()
{
    this->setValue(0,1);
}

void mixed::value(int w, int n, int d)
{
    this->setValue(w*d+n,d);
}


void mixed::value(double x)
{
    fraction xx(x);
    this->setValue(xx.get_num(),xx.get_denom());
}


void mixed::value(const fraction &x)
{
    this->setValue(x.get_num(), x.get_denom());
}

ostream& operator<<(ostream& out, const mixed &number)
{
    out<<number.get_num()<<"/"<<number.get_denom();
    return out;
}

istream& operator>>(istream& in, mixed &number)
{


    return in;
}
