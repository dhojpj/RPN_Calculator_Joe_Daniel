#include "mixed.h"

mixed::mixed(int w, int n, int d){}
mixed::mixed(const fraction& x){}
mixed::mixed(int x){}
mixed::mixed(double x){}
mixed::mixed(const mixed &x){}
mixed::mixed(int x, const fraction &f){}
mixed& mixed::operator=(const mixed &other){}
mixed& mixed::operator=(int x){}
mixed& mixed::operator=(double x){}
mixed& mixed::operator=(const fraction &x){}
mixed::~mixed(){}
void mixed::value(int w, int n, int d){}
void mixed::value(double x){}
void mixed::value(const fraction &x){}

ostream& operator<<(ostream& out, const mixed &number){}

istream& operator>>(istream& in, mixed &number){}
