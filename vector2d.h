#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <cmath>

namespace dd {
    /**
      * Stub to be replaced with PETSC vectors.
      */
    class Vector2d : public DdObject {
    public:
        double x, y;

        Vector2d(const double & x, const double & y) : x(x), y(y) { }
        Vector2d() : Vector2d::Vector2d(0, 0) { }
        Vector2d(const Vector2d & vec) : Vector2d(vec.x, vec.y) { }
        virtual ~Vector2d() { }

        double magnitude() const {
            return sqrt(x * x + y * y);
        }
        /**
         * Scale the vector
         */
        Vector2d scale(const double & factor) const {
            return Vector2d(x * factor, y * factor);
        }
        Vector2d operator*(const double & factor) const {
            return scale(factor);
        }

        /**
         * Vector addition
         */
        Vector2d translate(const double & dx, const double & dy) const {
            return Vector2d(x + dx, y + dy);
        }
        Vector2d translate(const Vector2d & dVec) const {
            return translate(dVec.x, dVec.y);
        }
        Vector2d operator+(const Vector2d & dVec) const {
            return translate(dVec);
        }
    };
}

#endif // VECTOR2D_H
