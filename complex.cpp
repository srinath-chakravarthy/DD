#include "complex.h"
#include <cmath>
#include "vector2d.h"

namespace dd {

    const Complex Complex::i = Complex(0, 1);
    Complex::Complex(const Vector2d & vec) :
        Complex::Complex(vec.x, vec.y) { }
    Complex Complex::operator*(const double & val) const {
        return Complex(real() * val, imag() * val);
    }
    Complex Complex::operator+(const double & val) const {
        return Complex(real() + val, imag());
    }
    double Complex::abs() const { return std::abs(*this); }
    Complex Complex::conjugate() const { return Complex(real(), -imag()); }

}
