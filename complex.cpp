#include "complex.h"
#include <cmath>
#include <complex>
#include "vector2d.h"
#include <iostream>
namespace dd {

    const Complex Complex::i = Complex(0, 1);
    Complex::Complex(const Vector2d & vec) :
        Complex::Complex(vec.x, vec.y) { }

    template<typename T>
    Complex Complex::operator*(const T & val) const {
        return Complex(real() + val, imag());
    }
    template<>
    Complex Complex::operator*<Complex>(const Complex & val) const {
        return (static_cast<std::complex<double>> (*this)) *
               (static_cast<std::complex<double>> (val));
    }

    template<typename T>
    Complex Complex::operator+(const T & val) const {
        return Complex(real() + val, imag());
    }
    template<>
    Complex Complex::operator+<Complex>(const Complex & val) const {
        return (static_cast<std::complex<double>> (*this)) +
               (static_cast<std::complex<double>> (val));
    }

    template<typename T>
    Complex Complex::operator-(const T & val) const {
        return Complex(real() - val, imag());
    }
    template<>
    Complex Complex::operator-<Complex>(const Complex & val) const {
        return (static_cast<std::complex<double>> (*this)) -
               (static_cast<std::complex<double>> (val));
    }

    template<typename T>
    Complex Complex::operator/(const T & val) const {
        return Complex(real() / val, imag() / val);
    }
    template<>
    Complex Complex::operator/<Complex>(const Complex & val) const {
        return (static_cast<std::complex<double>> (*this)) /
               (static_cast<std::complex<double>> (val));
    }

    Complex Complex::operator-() const {
        return Complex(-real(), -imag());
    }

    double Complex::abs() const { return std::abs(*this); }
    Complex Complex::conjugate() const { return Complex(real(), -imag()); }
}
