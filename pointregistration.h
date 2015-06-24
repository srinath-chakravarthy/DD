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
        T * get() const { return target; }

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
         * Default destructor
         */
        ~PointRegistration() {
            target->erasePoint(containerIterator);
            target = nullptr;
        }
    };
}

#endif // POINTREGISTRATION_H
