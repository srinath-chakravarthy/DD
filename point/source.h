#ifndef SOURCE_H
#define SOURCE_H

#include "../point.h"

namespace dd {

    class Domain;
    class SlipPlane;

    class SourcePoint : public Point {
    public:
        SourcePoint(Domain * domain, SlipPlane * sPlane) :
            Point(domain, sPlane) { }

        virtual bool canMove() const { return false; }

        virtual bool canSpawn() const { return true; }
        virtual void spawn();

        virtual bool canRemove() const { return true; }
    };
}

#endif // SOURCE_H
