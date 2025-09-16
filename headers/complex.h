#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

//using namespace std;

class TComplex{
    private:
        int re;
        int im;
    public:
        TComplex();
        TComplex(int re, int im);
        TComplex(int re);
        int getRe();
        int getIm();

        TComplex operator+(TComplex &second) const;
        TComplex operator-(TComplex &second) const;
        TComplex operator*(TComplex &second) const;
        TComplex operator/(TComplex &second) const;
        TComplex operator/=(TComplex second);
        TComplex operator*=(TComplex second);
        TComplex operator+=(TComplex second);
        TComplex operator-=(TComplex second);
        bool operator==(TComplex &second) const;
        bool operator!=(TComplex &second) const;
        TComplex operator=(double &second);
        bool operator>(TComplex &second);
        bool operator<(TComplex &second);
        double modulus(TComplex *complex);

        friend std::istream& operator >> (std::istream & in, TComplex & c);
        friend std::ostream& operator << (std::ostream & os, const TComplex & c);
        friend TComplex pow(TComplex complex, double n);
};
#endif COMPLEX_H