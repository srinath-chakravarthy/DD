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
        /**
         * Registers the point after the given iterator position within the sPlane.
         */
        Point(Domain * domain, SlipPlane * sPlane, pointContainer::iterator antecedentIt) :
            domain(this, domain), sPlane(this, sPlane, antecedentIt) { }

        /**
         * Register the point to the end of the sPlane.
         */
        Point(Domain * domain, SlipPlane * sPlane) :
            domain(this, domain), sPlane(this, sPlane) { }

        /**
         * Destructor
         */
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
