#ifndef VIRTUALDISLOCATION_H
#define VIRTUALDISLOCATION_H

#include "../point.h"
#include "source.h"

namespace dd {

    class Domain;
    class SlipPlane;

    class VirtualDislocationPoint : public SourcePoint {
    public:

        VirtualDislocationPoint(Domain * domain, SlipPlane * sPlane, double slipPlanePosition) :
            SourcePoint(domain, sPlane, slipPlanePosition) { }
        VirtualDislocationPoint(Domain * domain, SlipPlane * sPlane,
                                pointContainer::iterator antecedentIt, double slipPlanePosition) :
            SourcePoint(domain, sPlane, antecedentIt, slipPlanePosition) { }

        virtual bool canRemove() const { return false; }
        virtual void remove();

    };
}

#endif // VIRTUALDISLOCATION_H
