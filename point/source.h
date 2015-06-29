#ifndef SOURCE_H
#define SOURCE_H

#include "../point.h"
#include <string>

namespace dd {
    class Domain;
    class SlipPlane;

    class SourcePoint : public Point {
    public:

        SourcePoint(Domain * domain, SlipPlane * sPlane, double slipPlanePosition) :
            Point(domain, sPlane, slipPlanePosition) { }
        SourcePoint(Domain * domain, SlipPlane * sPlane,
                    pointContainer::iterator antecedentIt, double slipPlanePosition) :
            Point(domain, sPlane, antecedentIt, slipPlanePosition) { }

        double getStrength() const { return 0; }
        double getLength() const { return 0; }

        virtual bool canMove() const { return false; }

        virtual bool canSpawn() const { return true; }
        virtual void spawn();

        virtual bool canRemove() const { return true; }
    };
}

#endif // SOURCE_H
