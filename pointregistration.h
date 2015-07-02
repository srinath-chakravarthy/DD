#ifndef POINTREGISTRATION_H
#define POINTREGISTRATION_H

#include "pointregistrable.h"

namespace dd {

    /**
      * Registration record for Point objects' registrations to
      * PointRegistrable.
      *
      * T must extend PointRegistrable
      */
    template<typename T>
    class PointRegistration {
    private:
        Point * point;
        T * target;
        pointContainer::iterator containerIterator;
    public:
        /**
         * Get the registration target.
         */
        T * getTarget() const { return target; }

        /**
         * Get the registration point.
         */
        Point * getPoint() const { return point; }

        /**
         *
         */
         pointContainer::iterator getIterator() const { return containerIterator; }

        /**
         * Default constructor.
         *
         * @param point Point to be registered.
         * @param target Target PointRegistrable object.
         */
        PointRegistration(Point * point, T * target) {
            this->target = target;
            this->containerIterator = target->registerPoint(point);
        }

        /**
         * Default constructor.
         *
         * @param point Point to be registered.
         * @param target Targ
        PointRegistration(Poet PointRegistrable object.
         */
        PointRegistration(Point * point, T * target, pointContainer::iterator antecedentIt) {
            this->target = target;
            this->containerIterator = target->registerPoint(point, antecedentIt);
        }

        /**
         * Default destructor
         */
        virtual ~PointRegistration() {
            target->erasePoint(containerIterator);
            target = nullptr;
        }
    };
}

#endif // POINTREGISTRATION_H
