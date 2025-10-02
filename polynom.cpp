#include "headers/polynom.h"
#include "headers/array.h"
#include "number.h"
#include <cmath>
#include <iostream>

using namespace std;

Polynom::Polynom() {
    degree = 0;
    an = number(1,0);
    roots = new Array(degree);
    coefficients = new Array(degree+1);
}
Polynom::Polynom(int n, number an_value) {
    degree = n;
    an = an_value;
    roots = new Array(degree);
    coefficients = new Array(degree+1);
    for (int i=0; i<degree; i++) {
        roots->changeElem(i, number(1,0));
    }
    calculateCoefficients();
}
Polynom::Polynom(int n, number an_value, Array& roots_array) {
    degree = n;
    an = an_value;
    roots = new Array(roots_array);
    coefficients = new Array(degree + 1);
    calculateCoefficients();
}

void Polynom::calculateCoefficients() {
    if (degree == 0) {
        coefficients->changeElem(0,an);
    }
    number* coeffs = new number[degree + 1];
    for (int i = 0; i <= degree; i++) {
        coeffs[i] = number(0, 0);
    }

    coeffs[0] = number(1, 0);

    // (x - root_i) для каждого корня
    for (int i = 0; i < degree; i++) {
        number root = roots->findElem(i);

        for (int j = degree; j > 0; j--) {
            number term1 = coeffs[j - 1];
            number current_coeff = coeffs[j];
            double a = current_coeff.getRe();
            double b = current_coeff.getIm();
            double c = root.getRe();
            double d = root.getIm();
            number term2 = number(a * c - b * d, a * d + b * c);
            term2 = number(-term2.getRe(), -term2.getIm());
            coeffs[j] = number(term1.getRe() + term2.getRe(), term1.getIm() + term2.getIm());
        }
        double c_re = coeffs[0].getRe();
        double c_im = coeffs[0].getIm();
        double r_re = root.getRe();
        double r_im = root.getIm();
        coeffs[0] = number(-(c_re * r_re - c_im * r_im), -(c_re * r_im + c_im * r_re));
    }

    double an_re = an.getRe();
    double an_im = an.getIm();

    for (int i = 0; i <= degree; i++) {
        double coeff_re = coeffs[i].getRe();
        double coeff_im = coeffs[i].getIm();
        double new_re = coeff_re * an_re - coeff_im * an_im;
        double new_im = coeff_re * an_im + coeff_im * an_re;

        coefficients->changeElem(i, number(new_re, new_im));
    }

    delete[] coeffs;
}


int Polynom::getDegree() {
    return degree;
}

number Polynom::getCoefficient(int index) {
    if (index >= 0 && index <= degree) {
        return coefficients->findElem(index);
    }
    return number(0);
}

number Polynom::getRoot(int index) {
    if (index >= 0 && index < degree) {
        return roots->findElem(index);
    }
    return number(0);
}
void Polynom::input(std::istream& in) {
    cout << "Введите степень полинома: ";
    in >> degree;

    cout << "Введите коэффициент an: ";
    in >> an;
    roots = new Array(degree);
    coefficients = new Array(degree + 1);
    if (degree > 0) {
        cout << "Введите " << degree << " корней полинома:" << endl;
        for (int i = 0; i<degree; i++) {
            cout << "Корень номер"<< i+1<<endl;
            number root;
            in >> root;
            roots->changeElem(i,root);
        }
    }
    calculateCoefficients();
    cout << "Полином успешно создан!!"<<endl;
}
//p(x) = anxn + an-1xn-1 + ... + a1x + a0
void Polynom::outputForm1(std::ostream& out) {
    bool firstItem = false;
    for (int i =degree; i>=0; i--) {
        number coeff = coefficients->findElem(i);
        if (coeff.getRe() == 0 && coeff.getIm() == 0) {
            continue;
        }
        if (!firstItem) {
            if (coeff.getRe() > 0 || (coeff.getRe() == 0 && coeff.getIm() > 0)) {
                out << " + ";
            } else {
                out << " - ";
            }
            if (i == 0) {
                out << coeff;
            } else {
                if (!(coeff.getRe() == 1 && coeff.getIm() == 0)) {
                    if (!(coeff.getRe() == -1 && coeff.getIm() == 0)) {
                        out << coeff;
                        if (i > 0) {
                            out << "*";
                        }
                    } else if (i > 0) {
                        out << "-";
                    }
                }
            }

                if (i > 0) {
                    out << "x";
                    if (i > 1) {
                        out << "^" << i;
                    }
                }
            }
            firstItem = false;
        }
    if (firstItem) {
        out << "0";
    }
}
//p(x) = an(x-rn)(x-rn-1) ... (x-r1)
void Polynom::outputForm2(std::ostream& out) {
    out << an;
    for (int i = 0; i < degree; i++) {
        number root = roots->findElem(i);
        out << "(x";
        if (root.getRe() > 0.0) {
            out << " - " << root.getRe();
        } else if (root.getRe() < 0.0) {
            out << " + " << (-root.getRe());
        }
        if (root.getIm() != 0.0) {
            if (root.getIm() > 0.0) {
                out << " - " << root.getIm() << "i";
            } else {
                out << " + " << (-root.getIm()) << "i";
            }
        }

        out << ")";
    }
}

number Polynom::findNumberInPoint(number x) {
    number result = number(0);

    for (int i = degree; i >= 0; i--) {
        number coeff = coefficients->findElem(i);
        double result_re = result.getRe();
        double result_im = result.getIm();
        double x_re = x.getRe();
        double x_im = x.getIm();

        double mul_re = result_re * x_re - result_im * x_im;
        double mul_im = result_re * x_im + result_im * x_re;
        result = number(mul_re + coeff.getRe(), mul_im + coeff.getIm());
    }

    return result;
}