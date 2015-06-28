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

        template <typename T>
        Complex operator*(const T & val) const {
            return static_cast<std::complex<double>>(*this) * val;
        }

        template <typename T>
        Complex operator+(const T & val) const {
            return static_cast<std::complex<double>>(*this) + val;
        }

        template <typename T>
        Complex operator-(const T & val) const {
            return (*this) + (-val);
        }

        template <typename T>
        Complex operator/(const T & val) const {
            return static_cast<std::complex<double>>(*this) / val;
        }

        Complex operator-() const;

        double abs() const;
        Complex conjugate() const;
    };
}


#endif // COMPLEX_H
