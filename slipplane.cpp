#include "slipplane.h"
#include "slipsystem.h"
#include "point.h"
#include "point/obstacle.h"

namespace dd {

    double SlipPlane::getAngle() const { return slipSystem->getAngle(); }
    double SlipPlane::getCos() const { return slipSystem->getCos(); }
    double SlipPlane::getSin() const { return slipSystem->getSin(); }
    double SlipPlane::getBurgersMagnitude() const { return slipSystem->getBurgersMagnitude(); }
    Vector2d SlipPlane::getBurgersVector() const { return slipSystem->getDirection() * getBurgersMagnitude(); }
    Vector2d SlipPlane::getOrigin() const { return origin; }
    Vector2d SlipPlane::getPointPosition(const double & slipPlaneLocation) const {
        return slipSystem->getPointPosition(slipPlaneLocation, origin);
    }

}
