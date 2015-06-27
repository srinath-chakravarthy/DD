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
        double burgersMagnitude;
        double sin;
        double cos;
        Vector2d directionVector;
    public:
        /**
         * Default constructor
         */
        SlipSystem(const double & angle, const double & burgersMagnitude) :
            angle(angle),
            burgersMagnitude(burgersMagnitude),
            sin(::sin(angle)),
            cos(::cos(angle)),
            directionVector(cos, sin) { }

        virtual void addSlipPlane(SlipPlane * sPlane);
        double getAngle() const { return angle; }
        double getSin() const { return sin; }
        double getCos() const { return cos; }
        Vector2d getDirection() const { return directionVector; }
        virtual Vector2d getPointPosition(const double & slipPlaneLocation,
                                          const Vector2d & slipPlaneOrigin) const;

    };
}

#endif // SLIPSYSTEM_H
