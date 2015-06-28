#ifndef POINTREGISTRABLE_H
#define POINTREGISTRABLE_H

#include <list>
#include "ddobject.h"

namespace dd {

    class Point;
    template <typename T> class PointRegistration;

    /**
     * Type used for point containers.
     */
    typedef std::list<Point *> pointContainer;

    /**
     * Point registrable object.
     */
    class PointRegistrable : public DdObject {
        template <typename T> friend class PointRegistration;
    protected:
        pointContainer points;

        /**
         * Register the given point before the given position.
         */
        virtual pointContainer::iterator registerPoint(Point * toRegister,
                                                       pointContainer::iterator antecedentIt) {
            points.insert(antecedentIt, toRegister);
            return --antecedentIt;
        }

        /**
         * Register the given point at the end of the container.
         */
        pointContainer::iterator registerPoint(Point * p) {
            return registerPoint(p, points.end());
        }

        /**
         * Erase the registration at the given iterator. This must not
         * be called outside of PointRegistration.
         */
        virtual void erasePoint(pointContainer::iterator it) {
            points.erase(it);
        }
    public:
    };

}

#endif // POINTREGISTRABLE_H
