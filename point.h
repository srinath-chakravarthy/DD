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
    protected:
        PointRegistration<Domain> domain;
        PointRegistration<SlipPlane> sPlane;
    public:
        Point(Domain * domain, SlipPlane * sPlane) :
            domain(this, domain), sPlane(this, sPlane) { }
        ~Point() { }

        Domain * getDomain() const { return domain.get(); }
        SlipPlane * getSlipPlane() const { return sPlane.get(); }

        virtual bool canMove() const;
        virtual void move();
        virtual bool canSpawn() const;
        virtual void spawn();
        virtual bool canRemove() const;
        virtual void remove();
        virtual Vector2d getForce() { return domain.get()->calculateForce(*this); }
    };
}
