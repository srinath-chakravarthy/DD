#pragma once

#include "ddobject.h"
#include "domain.h"
#include "slipplane.h"
#include "registration.h"
#include "vector.h"
#include <string>

namespace dd {

    /**
      * Abstract point class.
      */
    class Point : public DdObject {
#define POINT_NAME "Point"
    protected:
        Registration<Point, Domain> * domainRegistration = nullptr;
        Registration<Point, SlipPlane> * sPlaneRegistration = nullptr;
        double slipPlanePosition = 0;
    public:

        /**
         * Registers the point after the given iterator position within the sPlane.
         */
        Point(Domain * domain, SlipPlane * sPlane, typename list<Point *>::iterator antecedentIt,
              double slipPlanePosition) :
                  slipPlanePosition(slipPlanePosition) {
            if(domain != nullptr) {
                this->domainRegistration = new Registration<Point, Domain>(this,
                                                                           domain);
            }
            if(sPlane != nullptr) {
                this->sPlaneRegistration = new Registration<Point, SlipPlane>(this,
                                                                              sPlane,
                                                                              antecedentIt);
            }
        }

        /**
         * Register the point to the end of the sPlane.
         */
        Point(Domain * domain, SlipPlane * sPlane, double slipPlanePosition) :
            slipPlanePosition(slipPlanePosition) {
            if(domain != nullptr) {
                this->domainRegistration = new Registration<Point, Domain>(this, domain);
            }
            if(sPlane != nullptr) {
                this->sPlaneRegistration = new Registration<Point, SlipPlane>(this, sPlane);
            }
        }

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

        virtual void addForceContribution(const Point * &, Vector<2> &,
                                          Vector<2> &, Vector<3> &);
        virtual void addForceContribution(const list<Point *> &, Vector<2> &,
                                          Vector<2> &, Vector<3> &);

        virtual string typeName() const { return POINT_NAME; }
        static string staticTypeName() { return POINT_NAME; }
    };
}
