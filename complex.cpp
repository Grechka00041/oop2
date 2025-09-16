#include "headers/complex.h"

#include <cmath>

#include <iostream>

using namespace std;

TComplex:: TComplex(){
    im = re = 0;
}

TComplex:: TComplex(int re){
    this->re = re;
    im = 0;
}

TComplex:: TComplex(int re, int im){
    this->re = re;
    this->im = im;
}

int TComplex:: getRe(){
    return this->re;
}

int TComplex:: getIm(){
    return this->im;
}

std::istream &operator>>(std::istream & in, TComplex &complex){
    in >> complex.re >> complex.im;
    return in;
}
TComplex TComplex:: operator+(TComplex &second) const {
    return(re+second.re, im+second.im);
}
TComplex TComplex:: operator-(TComplex &second) const {
    return(re-second.re, im-second.im);
}

TComplex TComplex:: operator*(TComplex &second) const{
    double resRe, resIm;
    resRe = re*second.re-im*second.im;
    resIm = second.im*re + im*second.re;
    return TComplex(resRe, resIm);
}
TComplex TComplex:: operator/(TComplex &second) const{
    double resRe, resIm;
    resRe = (re*second.re+im*second.im)/(pow(second.re,2) +pow(second.im,2));
    resIm = (im*second.re-re*second.im)/(pow(second.re,2) +pow(second.im,2));
    return TComplex(resRe, resIm);
}
TComplex TComplex:: operator+=(TComplex second) {
    re += second.re;
    im += second.im;
    return TComplex(re, im);

}
TComplex TComplex:: operator-=(TComplex second){
    re -= second.re;
    im -= second.im;
    return TComplex(re, im);
}
TComplex TComplex::operator/=(TComplex second){
    double resRe,resIm;
    resRe = (re*second.re+im*second.im)/(pow(second.re,2) +pow(second.im,2));
    resIm = (im*second.re-re*second.im)/(pow(second.re,2) +pow(second.im,2));
    re = resRe;
    im = resIm;
    return TComplex(re, im);
}
TComplex TComplex::operator*=(TComplex second){
    double resRe, resIm;
    resRe = re*second.re-im*second.im;
    resIm = second.im*re + im*second.re;
    re = resRe;
    im = resIm;
    return TComplex(re, im);
}
bool TComplex::operator==(TComplex &second) const {
    if (re==second.re and im==second.im) {
        return true;
    }
    return false;
}
bool TComplex::operator!=(TComplex &second) const {
    if (re!=second.re or im!=second.im) {
        return true;
    }
    return false;
}
TComplex TComplex::operator=(double &second){
    return TComplex(second,0);
}

double TComplex::modulus(TComplex *complex) {
    double re = pow(complex->getRe(),2);
    double im = pow(complex->getIm(), 2);
    return pow(re + im, 0.5);
}
bool TComplex::operator<(TComplex &second){
    if(modulus(this) < modulus(&second)) return true;
    if(modulus(this) == modulus(&second)){
        if(::atan(this->im/this->re) < atan(second.im/second.re)) return true;
    }
    return false;
}

bool TComplex::operator>(TComplex &second){
    if(modulus(this) > modulus(&second)) return true;
    if(modulus(this) == modulus(&second)){
        if(atan(this->im/this->re) > atan(second.im/second.re)) return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const TComplex &complex){
    if (complex.im < 0 && complex.re != 0){
        os << complex.re << complex.im << "i";
    }else if (complex.im != 0 && complex.re == 0){
        os << complex.im << "i";
    }else if (complex.im > 0 && complex.re != 0){
        os << complex.re << "+" << complex.im << "i";
    }else if (complex.im == 0 && complex.re != 0){
        os << complex.re;
    }else {
        os << "0";
    }
    return os;
}

TComplex pow(TComplex complex, double n){
    double argZ;
    if(complex.re > 0) argZ = atan(complex.im / complex.re);
    else if(complex.re < 0 && complex.im >= 0) argZ = 3.14 - atan(complex.im / complex.re);
    else if(complex.re < 0 && complex.im < 0) argZ = -3.14 + atan(complex.im / complex.re);
    else if(complex.re == 0 && complex.im > 0) argZ = 3.14/2;
    else argZ = -3.14/2;
    return TComplex(std::pow(complex.modulus(&complex), n) * cos(argZ * n),
                    std::pow(complex.modulus(&complex), n) * sin(argZ * n));
}




