#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class TComplex{
    private:
        double re;
        double im;
    public:
        TComplex();
        TComplex(double re, double im);
        TComplex(double re);
        double getRe();

        TComplex operator-(TComplex &second) const;
        TComplex operator/=(TComplex second);
        TComplex operator+=(TComplex second);
        //TComplex operator+=(double second);
        bool operator>(TComplex &second);
        bool operator<(TComplex &second);
        double modulus(TComplex *complex);

        friend std::istream& operator >> (std::istream & in, TComplex & c);
        friend std::ostream& operator << (std::ostream & os, const TComplex & c);
        friend TComplex pow(TComplex complex, double n);
};
#endif COMPLEX_H