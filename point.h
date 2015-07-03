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

        /**
         * Destruct domain registration
         */
        void destructDomainRegistration() {
            if(domainRegistration != nullptr) {
                delete domainRegistration;
                domainRegistration = nullptr;
            }
        }

        /**
         * Destruct sPlaneRegistration
         */
        void destructsPlaneRegistration() {
            if(sPlaneRegistration != nullptr) {
                delete sPlaneRegistration;
                sPlaneRegistration = nullptr;
            }
        }

        /**
         * Destruct both registrations
         */
        void destructRegistrations() {
            destructDomainRegistration();
            destructsPlaneRegistration();
        }

        /**
         * Sets the Registration objects.
         *
         * setRegistrations is implemented for registration after construction.
         * During the construction process, the correct type name string is not
         * produced due to unfinished vtable.
         */
        void setRegistrations(Domain * domain, SlipPlane * sPlane, const typename list<Point *>::iterator & antecedentIt) {
            destructRegistrations();
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
         * Externally set the registrations
         */
        void setRegistrations(Domain * domain, SlipPlane * sPlane) {
            destructRegistrations();
            if(domain != nullptr) {
                this->domainRegistration = new Registration<Point, Domain>(this,
                                                                           domain);
            }
            if(sPlane != nullptr) {
                this->sPlaneRegistration = new Registration<Point, SlipPlane>(this,
                                                                              sPlane);
            }
        }

    public:

        /**
         * Registers the point after the given iterator position within the sPlane.
         */
        Point(Domain * domain, SlipPlane * sPlane, typename list<Point *>::iterator antecedentIt,
              double slipPlanePosition) :
                  slipPlanePosition(slipPlanePosition) {
            setRegistrations(domain, sPlane, antecedentIt);
        }

        /**
         * Register the point to the end of the sPlane.
         */
        Point(Domain * domain, SlipPlane * sPlane, double slipPlanePosition) :
            slipPlanePosition(slipPlanePosition) {
            setRegistrations(domain, sPlane);
        }

        /**
         * Unregistered constructor
         */
        Point(double slipPlanePosition) :
            Point(nullptr, nullptr, slipPlanePosition) { }


        /**
         * Destructor
         */
        virtual ~Point() {
            destructRegistrations();
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
        virtual void addForceContribution(const string &, Vector<2> &, Vector<2> &, Vector<3> &);
        template <typename T>
        void addForceContribution(Vector<2> & f, Vector<2> & v, Vector<3> & s) {
            addForceContribution(getDomain()->getContainer<T>(), f, v, s);
        }

        virtual string typeName() const { return POINT_NAME; }
        static string staticTypeName() { return POINT_NAME; }
    };
}
