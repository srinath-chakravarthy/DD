#ifndef VECTOR_H
#define VECTOR_H

namespace dd {


    /**
     * Fixed-size vector class.
     */
    template <unsigned size>
    class Vector {
    private:
        double data[size];
    public:

        /**
         * Size getter
         */
        constexpr double getSize() const { return size; }

        /**
         * Immutable get
         */
        const double & operator[](unsigned index) const {
            return data[index];
        }

        /**
         * Mutable get
         */
        double & operator[](unsigned index) {
            return data[index];
        }

        /**
         * Populate the vector with the given value.
         */
        void fill(const double & value) {
           for(unsigned i = 0; i < size; i++) {
                data[i] = value;
            }
        }

        /**
         * Zero-fill
         */
        void zero() { fill(0); }

        /**
         * Fill constructor
         */
        Vector(const double & value) { fill(value); }

        /**
         * Scale the vector
         */
        void scale(double scaleValue) {
            for(unsigned i = 0; i < size; i++) {
                data[i] *= scaleValue;
            }
        }

        /**
         * Zero constructor
         */
        Vector() : Vector(0) { }

        /**
         * Copy constructor
         */
        Vector(const Vector & other) {
            for(unsigned i = 0; i < size; i++) {
                data[i] = other[i];
            }
        }

        /**
         * Unary minus
         */
        Vector operator-() const {
            return Vector(*this).scale(-1);
        }

        /**
         * Vector addition
         */
        Vector operator+(const Vector & other) const {
            Vector result;
            for(unsigned i = 0; i < size; i++) {
                result[i] = data[i] + other[i];
            }
            return result;
        }

        /**
         * Vector subtraction
         */
        Vector operator-(const Vector & other) const {
            return (*this) + (-Vector(other));
        }

        /**
         * Scaling
         */
        Vector operator*(const double & factor) const {
            return Vector(*this).scale(factor);
        }
    };
}

#endif // VECTOR_H