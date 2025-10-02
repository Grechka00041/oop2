#include "headers/complex.h"

#include <cmath>

#include <iostream>

using namespace std;


TComplex:: TComplex(){
    im = re = 0;
}

TComplex:: TComplex(double re){
    this->re = re;
    im = 0;
}

TComplex:: TComplex(double re, double im){
    this->re = re;
    this->im = im;
}

std::istream &operator>>(istream & in, TComplex &num){
    in >> num.re >> num.im;
    return in;
}
double TComplex:: getRe(){
    return this->re;
}
double TComplex::getIm(){
    return this->im;
}
TComplex TComplex:: operator-(TComplex &num) const {
    return(re-num.re, im-num.im);
}
TComplex TComplex:: operator+(TComplex &num) const {
    return(re+num.re, im+num.im);
}
TComplex TComplex:: operator+=(TComplex num) {
    re += num.re;
    im += num.im;
    return TComplex(re, im);

}

TComplex TComplex::operator/=(TComplex num){
    double resRe,resIm;
    resRe = (re*num.re+im*num.im)/(pow(num.re,2) +pow(num.im,2));
    resIm = (im*num.re-re*num.im)/(pow(num.re,2) +pow(num.im,2));
    re = resRe;
    im = resIm;
    return TComplex(re, im);
}
TComplex TComplex::operator*(TComplex &num) const {
    double resRe;
    double resIm;
    resRe = re * num.re - im * num.im;
    resIm = re * num.im + im * num.re;
    return TComplex(resRe, resIm);
}

TComplex& TComplex::operator=(const TComplex &other) {
    if (this != &other) {
        re = other.re;
        im = other.im;
    }
    return *this;
}
double TComplex::modulus(TComplex *complex) {
    double re, im;
    re = pow(complex->re,2);
    im = pow(complex->im, 2);
    return pow(re + im, 0.5);
}

bool TComplex::operator<(TComplex &num){
    if(modulus(this) == modulus(&num)){
        if(::atan(this->im/this->re) < atan(num.im/num.re)) {
            return true;
        }
    }

    if(modulus(this) < modulus(&num)) {
        return true;
    }

    return false;
}

bool TComplex::operator>(TComplex &num){
    if(modulus(this) == modulus(&num)){
        if(atan(this->im/this->re) > atan(num.im/num.re)) {
            return true;
        }
    }

    if(modulus(this) > modulus(&num)) {
        return true;
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

TComplex pow(TComplex complex, double num) {
    double z;
    const double pi = 3.14;
    if(complex.re > 0) {
        z = atan(complex.im / complex.re);
    }
    else if(complex.re < 0 && complex.im >= 0) {
        z = pi - atan(complex.im / complex.re);
    }
    else if(complex.re < 0 && complex.im < 0) {
        z = -pi + atan(complex.im / complex.re);
    }
    else if(complex.re == 0 && complex.im < 0) {
        z = -pi/2;
    }
    else {
        z = pi/2;
    }
    return TComplex(pow(complex.modulus(&complex), num) * cos(z * num),
                    pow(complex.modulus(&complex), num) * sin(z * num));
}

/*TComplex TComplex::operator+=(double second){
    re += second;
    return TComplex(re, im);
}*/




