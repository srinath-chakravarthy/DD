#include "slipplane.h"
#include "slipsystem.h"

namespace dd {

    double SlipPlane::getAngle() const { return slipSystem->getAngle(); }
    double SlipPlane::getCos() const { return slipSystem->getCos(); }
    double SlipPlane::getSin() const { return slipSystem->getSin(); }
    pointContainer::iterator SlipPlane::getEndIterator() { return points.end(); }
    Vector2d SlipPlane::getOrigin() const { return origin; }
    Vector2d SlipPlane::getPointPosition(const double & slipPlaneLocation) const {
        return slipSystem->getPointPosition(slipPlaneLocation, origin);
    }
}
