#pragma once

#include "pointregistrable.h"
#include "domain.h"
#include "vector2d.h"

namespace dd {

    class ObstaclePoint;

    class SlipPlane : public PointRegistrable {
    private:
        Domain * domain;
        SlipSystem * slipSystem;
        Vector2d origin;

    public:
        SlipPlane(Domain * domain, SlipSystem * slipSystem, Vector2d origin) :
            domain(domain),
            slipSystem(slipSystem),
            origin(origin) { }

        double getAngle() const;
        double getSin() const;
        double getCos() const;
        double getBurgersMagnitude() const;
        Vector2d getBurgersVector() const;
        pointContainer::iterator getEndIterator();
        SlipSystem * getSlipSystem() { return slipSystem; }
        Vector2d getOrigin() const;
        Vector2d getPointPosition(const double & slipPlaneLocation) const;
    };
}