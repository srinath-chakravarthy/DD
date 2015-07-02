#ifndef VIRTUALDISLOCATION_H
#define VIRTUALDISLOCATION_H

#include "../point.h"
#include "source.h"
#include "../betweenpoints.h"

namespace dd {

    class Domain;
    class SlipPlane;

    class VirtualDislocationPoint : public Point, public BetweenPoints<ObstaclePoint> {
#define VIRTUALDISLOCATION_NAME "VirtualDislocation"
    public:

        VirtualDislocationPoint(Domain * domain, SlipPlane * sPlane, double slipPlanePosition,
                                list<ObstaclePoint *>::iterator next,
                                list<ObstaclePoint *>::reverse_iterator prev) :
            Point(domain, sPlane, slipPlanePosition),
            BetweenPoints<ObstaclePoint>(next, prev) { }
        VirtualDislocationPoint(Domain * domain, SlipPlane * sPlane,
                                list<Point *>::iterator antecedentIt, double slipPlanePosition,
                                list<ObstaclePoint *>::iterator next,
                                list<ObstaclePoint *>::reverse_iterator prev) :
            Point(domain, sPlane, antecedentIt, slipPlanePosition),
            BetweenPoints<ObstaclePoint>(next, prev) { }

        virtual string typeName() const { return VIRTUALDISLOCATION_NAME; }
        static string staticTypeName() { return VIRTUALDISLOCATION_NAME; }
    };
}

#endif // VIRTUALDISLOCATION_H
