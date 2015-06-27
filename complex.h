#ifndef COMPLEX_H
#define COMPLEX_H

#include "ddobject.h"
#include <complex>

namespace dd {

    class Vector2d;

    class Complex : public DdObject, public std::complex<double> {
    public:
        static const Complex i;

        Complex(const double & real, const double & imag) :
            std::complex<double>(real, imag) { }
        Complex(const std::complex<double> & comp) :
            Complex(comp.real(), comp.imag()) { }
        Complex(const Vector2d & vec);
        Complex operator*(const double &) const;
        Complex operator+(const double &) const;
        double abs() const;
        Complex conjugate() const;
    };
}


#endif // COMPLEX_H
