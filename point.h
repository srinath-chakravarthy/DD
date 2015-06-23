#pragma once

#include "ddobject.h"
#include "domain.h"
#include "slipplane.h"
#include "pointregistration.h"
#include "vector2d.h"

namespace dd {
    /**
      * Abstract point class.
      */
    class Point : public DdObject {
    private:
        PointRegistration<Domain> domain;
        PointRegistration<SlipPlane> sPlane;
    public:
        Point(Domain * domain, SlipPlane * sPlane) :
            domain(this, domain), sPlane(this, sPlane) { }
        ~Point() { }

        Domain * getDomain() const { return domain.get(); }
        SlipPlane * getSlipPlane() const { return sPlane.get(); }

        virtual void move();
        virtual void spawn();
        virtual void remove();
        virtual Vector2d getForce();
    };
}
