#include "slipsystem.h"
#include "slipplane.h"
#include "vector2d.h"

namespace dd {

    void SlipSystem::addSlipPlane(SlipPlane * sPlane) {
        sPlanes.push_back(sPlane);
    }

    Vector2d SlipSystem::getPointPosition(const double & slipPlaneLocation,
                                          const Vector2d & slipPlaneOrigin) const {
        return directionVector * slipPlaneLocation + slipPlaneOrigin;
    }
}