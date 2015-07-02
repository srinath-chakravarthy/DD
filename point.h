#pragma once

#include "ddobject.h"
#include "domain.h"
#include "slipplane.h"
#include "pointregistration.h"
#include "vector.h"
#include <string>

namespace dd {

    /**
      * Abstract point class.
      */
    class Point : public DdObject {
    protected:
        PointRegistration<Domain> * domainRegistration = nullptr;
        PointRegistration<SlipPlane> * sPlaneRegistration = nullptr;
        double slipPlanePosition = 0;
    public:

        /**
         * Registers the point after the given iterator position within the sPlane.
         */
        Point(Domain * domain, SlipPlane * sPlane, pointContainer::iterator antecedentIt,
              double slipPlanePosition) :
                  slipPlanePosition(slipPlanePosition) {
            if(domain != nullptr) {
                this->domainRegistration = new PointRegistration<Domain>(this,
                                                                         domain);
            }
            if(sPlane != nullptr) {
                this->sPlaneRegistration = new PointRegistration<SlipPlane>(this,
                                                                            sPlane,
                                                                            antecedentIt);
            }
        }

        /**
         * Register the point to the end of the sPlane.
         */
        Point(Domain * domain, SlipPlane * sPlane, double slipPlanePosition) :
            Point::Point(domain, sPlane, sPlane->getEndIterator(), slipPlanePosition) { }

        /**
         * Destructor
         */
        virtual ~Point() {
            delete(domainRegistration);
            delete(sPlaneRegistration);
        }

        Domain * getDomain() const { return domainRegistration->getTarget(); }
        SlipPlane * getSlipPlane() const { return sPlaneRegistration->getTarget(); }
        Vector2d getLocation() const { return getSlipPlane()->getPointPosition(slipPlanePosition); }

        virtual bool canMove() const = 0;
        virtual void move();
        virtual bool canSpawn() const = 0;
        virtual void spawn();
        virtual bool canRemove() const = 0;
        virtual void remove();

        double getBurgersMagnitude() const;
        Vector2d getBurgersVector() const;

        virtual Vector2d getForce(const pointContainer & sources);
        virtual Vector2d getForce(std::string fromPointType);
    };
}
