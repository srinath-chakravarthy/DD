#ifndef VIRTUALDISLOCATION_H
#define VIRTUALDISLOCATION_H

#include "../point.h"
#include "source.h"

namespace dd {

    class Domain;
    class SlipPlane;

    class VirtualDislocationPoint : public SourcePoint {
    public:

        VirtualDislocationPoint(Domain * domain, SlipPlane * sPlane) :
            SourcePoint(domain, sPlane) { }

        virtual bool canRemove() const { return false; }
        virtual void remove();

    };
}

#endif // VIRTUALDISLOCATION_H
