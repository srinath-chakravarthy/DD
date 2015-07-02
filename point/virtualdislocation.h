#ifndef VIRTUALDISLOCATION_H
#define VIRTUALDISLOCATION_H

#include "../point.h"
#include "source.h"

namespace dd {

    class Domain;
    class SlipPlane;

    class VirtualDislocationPoint : public Point {
    public:

        VirtualDislocationPoint(Domain * domain, SlipPlane * sPlane, double slipPlanePosition) :
            Point(domain, sPlane, slipPlanePosition) { }
        VirtualDislocationPoint(Domain * domain, SlipPlane * sPlane,
                                pointContainer::iterator antecedentIt, double slipPlanePosition) :
            Point(domain, sPlane, antecedentIt, slipPlanePosition) { }
    };
}

#endif // VIRTUALDISLOCATION_H
