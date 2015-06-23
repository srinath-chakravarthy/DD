#pragma once

#include "ddobject.h"
#include "domain.h"
#include "slipplane.h"
#include "vector2d.h"

namespace dd {
    /**
      * Abstract point class.
      */
    class Point : public DdObject {
    private:
        Domain * domain;
        SlipPlane * sPlane;
        pointContainer::iterator domainIterator;
        pointContainer::iterator sPlaneIterator;
    public:
        Point(Domain * domain, SlipPlane * sPlane) {
            this->domain = domain;
            this->sPlane = sPlane;
            this->domainIterator = domain->registerPoint(this);
            this->sPlaneIterator = sPlane->registerPoint(this);
        }
        ~Point() {
            this->domain->erasePoint(domainIterator);
        }
        virtual void move();
        virtual void spawn();
        virtual void remove();
        virtual Vector2d getForce();
    };
}
