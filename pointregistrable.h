#ifndef POINTREGISTRABLE_H
#define POINTREGISTRABLE_H

#include <list>

namespace dd {

    class Point;

    typedef std::list<Point *> pointContainer;

    /**
     * Point registrable object.
     *
     * TODO: Hide the public registration process to be Registrable-only.
     */
    class PointRegistrable {
    protected:
        pointContainer points;
    public:

        /**
         * Register the given point. This must not
         * be called outside of PointRegistration.
         */
        virtual pointContainer::iterator registerPoint(Point * p) {
            points.push_back(p);
            return --points.end();
        }

        /**
         * Erase the registration at the given iterator. This must not
         * be called outside of PointRegistration.
         */
        virtual void erasePoint(pointContainer::iterator it) {
            points.erase(it);
        }
    };

}

#endif // POINTREGISTRABLE_H
