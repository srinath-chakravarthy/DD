#include "point.h"
#include "dderror.h"
#include "vector.h"
#include "domain.h"
#include "complex.h"

namespace dd {
    void Point::move() {
        DdError::exception("Point cannot move.");
    }

    void Point::spawn() {
        DdError::exception("Point cannot spawn.");
    }

    void Point::remove() {
        DdError::exception("Point cannot be removed.");
    }

    double Point::getBurgersMagnitude() const {
        return getSlipPlane()->getBurgersMagnitude();
    }

    Vector2d Point::getBurgersVector() const {
        return getSlipPlane()->getBurgersVector();
    }

    Vector2d Point::getForce(const pointContainer & sources) {
        double thetaz = 1;
        double factor = 70e-3/(8 * 2.0*::asin(1)*(1-.3*.3));

        double cutOff = 2 * std::abs(this->getBurgersMagnitude());
        Complex b(this->getBurgersVector());
        Complex z(this->getLocation());

        double sig11 = 0;
        double sig22 = 0;
        double sig12 = 0;
        double sig11z = 0;
        double sig22z = 0;
        double sig12z = 0;

        for(Point * p : sources) {
            Complex zSource(p->getLocation());
            Complex dz = z - zSource;
            double zd = dz.abs();


            if(zd > cutOff) {
                Complex phi1 = -1. * Complex::i * factor * b / dz;
                Complex phi11 = Complex::i * factor * b / (dz * dz);
                Complex phi2 = Complex::i * factor * b.conjugate() / dz;

                Complex tmp1 = 2. * Complex(phi1 * phi1.conjugate());
                Complex tmp2 = -2. * Complex(dz * phi11.conjugate() * phi2.conjugate());

                sig11 += Complex(0.5 * (tmp1 + tmp2)).real();
                sig22 += Complex(0.5 * (tmp1 - tmp2)).real();
                sig12 += Complex(.5 * tmp2).imag();

                Complex phi1z = Complex::i * factor * b / (dz * dz) * thetaz;
                Complex phi11z = -2. * Complex::i * factor * b / (dz * dz * dz) * thetaz;
                Complex phi2z = -1. * factor * b.conjugate() / (dz * dz) * thetaz;
                Complex tmp1z = 2. * (phi1z + phi1z.conjugate());
                Complex tmp2z = -2. * (dz * phi11z.conjugate() + phi2z.conjugate());

                sig11z += Complex(.5 * (tmp1z + tmp2z)).real();
                sig22z += Complex(.5 * (tmp1z - tmp2z)).real();
                sig12z += Complex(.5 * tmp2z).imag();
            }
        }

        double cos2i = ::cos(2. * this->getSlipPlane()->getAngle());
        double sin2i = ::sin(2. * this->getSlipPlane()->getAngle());

        Complex bi = b * ((sig22 - sig11) * .5 * sin2i + sig12 * cos2i);

        return Vector2d({bi.real(), b.imag()});
    }

    Vector2d Point::getForce(string fromPointType) {
        return getForce(getDomain()->getContainer(fromPointType));
    }
}

