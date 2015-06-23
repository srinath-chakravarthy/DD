#ifndef POINTREGISTRABLE_H
#define POINTREGISTRABLE_H

#include <list>

namespace dd {

    class Point;

    typedef std::list<Point *> pointContainer;

    class PointRegistrable {
    protected:
        pointContainer points;
    public:
        virtual pointContainer::iterator registerPoint(Point * p) {
            points.push_back(p);
            return --points.end();
        }
        virtual void erasePoint(pointContainer::iterator it) {
            points.erase(it);
        }
    };

}

#endif // POINTREGISTRABLE_H
