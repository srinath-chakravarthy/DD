#ifndef SLIPSYSTEM_H
#define SLIPSYSTEM_H

#include "ddobject.h"
#include "vector2d.h"
#include <cmath>
#include <list>

namespace dd {

    class SlipPlane;

    class SlipSystem {
    private:
        std::list<SlipPlane *> sPlanes;
        double angle;
        double sin;
        double cos;
        Vector2d directionVector;
        double bMag;
    public:
        /**
         * Default constructor
         */
        SlipSystem(const double & angle,
                   const double & bMag) :
            angle(angle),
            sin(::sin(angle)),
            cos(::cos(angle)),
            directionVector(cos, sin),
            bMag(bMag) { }

        virtual void addSlipPlane(SlipPlane * sPlane);
        double getAngle() const { return angle; }
        double getSin() const { return sin; }
        double getCos() const { return cos; }
        double getBurgersMagnitude() const { return bMag; }
        Vector2d getDirection() const { return directionVector; }
        virtual Vector2d getPointPosition(const double & slipPlaneLocation,
                                          const Vector2d & slipPlaneOrigin) const;

    };
}

#endif // SLIPSYSTEM_H
