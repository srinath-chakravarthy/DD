#pragma once

#include "pointregistrable.h"
#include "domain.h"
#include <cmath>

namespace dd {

    class SlipPlane : public PointRegistrable {
    private:
        Domain * domain;
        double xIntercept;
        double angle;
        double sin;
        double cos;
    public:
        SlipPlane(Domain * domain, double xIntercept, double angle) {
            this->domain = domain;
            this->xIntercept = xIntercept;
            this->angle = angle;
            this->sin = ::sin(angle);
            this->cos = ::cos(angle);
        }

        double getXIntercept() { return xIntercept; }
        double getAngle() { return angle; }
        double getSin() { return sin; }
        double getCos() { return cos; }
    };
}
