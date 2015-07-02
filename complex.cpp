#include "complex.h"
#include <cmath>
#include <complex>
#include "vector2d.h"
#include <iostream>
namespace dd {

    const Complex Complex::i = Complex(0, 1);
    Complex::Complex(const Vector2d & vec) :
        Complex::Complex(vec.x, vec.y) { }

    Complex Complex::operator-() const {
        return Complex(-real(), -imag());
    }

    double Complex::abs() const { return std::abs(*this); }
    Complex Complex::conjugate() const { return Complex(real(), -imag()); }
}
