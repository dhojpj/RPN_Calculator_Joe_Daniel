#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <sstream>

enum FRACTION_ERRORS{ZERO_DENOM};


//using namespace std;
using std::cout;
using std::cin;
using std::ostream;
using std::istream;
using std::endl;


class fraction
{
public:
    fraction(long n = 0, int d = 1);
    ~fraction();
    fraction(int x);
    fraction(double x);
    fraction(const fraction &other);
    fraction& operator=(const fraction &other);
    fraction& operator=(int other);
    fraction& operator=(double other);
    int get_num() const;
    int get_denom() const;
    void setValue(int n = 0, int d = 1);


    fraction& operator+=(const fraction &other);
    fraction& operator-=(const fraction &other);
    fraction& operator*=(const fraction &other);
    fraction& operator/=(const fraction &other);
    fraction& operator^=(const fraction &other);
    fraction& operator+=(int other);
    fraction& operator-=(int other);
    fraction& operator*=(int other);
    fraction& operator/=(int other);
    fraction& operator^=(int other);
    fraction& operator+=(double other);
    fraction& operator-=(double other);
    fraction& operator*=(double other);
    fraction& operator/=(double other);
    fraction& operator^=(double other);


    // need to remove the first const
    friend
    fraction operator+(const fraction &x, const fraction &y);
    friend
    fraction operator-(const fraction &x, const fraction &y);
    friend
    fraction operator*(const fraction &x, const fraction &y);
    friend
    fraction operator/(const fraction &x, const fraction &y);
    friend
    fraction operator^(const fraction &x, const fraction &y);

    friend
    fraction operator+(const fraction &x, int y);
    friend
    fraction operator-(const fraction &x, int y);
    friend
    fraction operator*(const fraction &x, int y);
    friend
    fraction operator/(const fraction &x, int y);
    friend
    fraction operator^(const fraction &x, int y);
    friend
    fraction operator+(int x, const fraction &y);
    friend
    fraction operator-(int x, const fraction &y);
    friend
    fraction operator*(int x, const fraction &y);
    friend
    fraction operator/(int x, const fraction &y);
    friend
    fraction operator^(int x, const fraction &y);

    friend
    fraction operator+(const fraction &x, double y);
    friend
    fraction operator-(const fraction &x, double y);
    friend
    fraction operator*(const fraction &x, double y);
    friend
    fraction operator/(const fraction &x, double y);
    friend
    fraction operator^(const fraction &x, double y);
    friend
    fraction operator+(double x, const fraction &y);
    friend
    fraction operator-(double x, const fraction &y);
    friend
    fraction operator*(double x, const fraction &y);
    friend
    fraction operator/(double x, const fraction &y);
    friend
    fraction operator^(double x, const fraction &y);

    friend
    bool operator==(const fraction &x, const fraction &y);
    friend
    bool operator!=(const fraction &x, const fraction &y);
    friend
    bool operator<=(const fraction &x, const fraction &y);
    friend
    bool operator>=(const fraction &x, const fraction &y);
    friend
    bool operator<(const fraction &x, const fraction &y);
    friend
    bool operator>(const fraction &x, const fraction &y);

    friend
    bool operator==(const fraction &x, int y);
    friend
    bool operator!=(const fraction &x, int y);
    friend
    bool operator<=(const fraction &x, int y);
    friend
    bool operator>=(const fraction &x, int y);
    friend
    bool operator<(const fraction &x, int y);
    friend
    bool operator>(const fraction &x, int y);
    friend
    bool operator==(int x, const fraction &y);
    friend
    bool operator!=(int x, const fraction &y);
    friend
    bool operator<=(int x, const fraction &y);
    friend
    bool operator>=(int x, const fraction &y);
    friend
    bool operator<(int x, const fraction &y);
    friend
    bool operator>(int x, const fraction &y);

    friend
    bool operator==(const fraction &x, double y);
    friend
    bool operator!=(const fraction &x, double y);
    friend
    bool operator<=(const fraction &x, double y);
    friend
    bool operator>=(const fraction &x, double y);
    friend
    bool operator<(const fraction &x, double y);
    friend
    bool operator>(const fraction &x, double y);
    friend
    bool operator==(double x, const fraction &y);
    friend
    bool operator!=(double x, const fraction &y);
    friend
    bool operator<=(double x, const fraction &y);
    friend
    bool operator>=(double x, const fraction &y);
    friend
    bool operator<(double x, const fraction &y);
    friend
    bool operator>(double x, const fraction &y);

    friend
    ostream& operator<<(ostream& out, const fraction &frac);

    friend
    istream& operator>>(istream& in, fraction &frac);

protected:
    int& numerator();
    int& denominator();
    void reduce();
    void setNum(int n, int d);

private:
    int num, denom;
    void copy(const fraction& other);
    int gcd(int p, int q);


};


#endif // FRACTION_H
