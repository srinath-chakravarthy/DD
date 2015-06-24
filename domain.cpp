#include "domain.h"
#include "slipplane.h"
#include "dderror.h"
#include "point.h"

namespace dd {

    Domain::Domain(int sPlaneCount) {
        this->sPlanes.reserve(sPlaneCount);
    }

    Domain::Domain() : Domain::Domain(0) { }

    Vector2d Domain::calculateForce(const Point & target) {
        if(target.getDomain() != this) {
            DdError::exception("Target is not in this domain.");
        }
        Vector2d result;

        for(Point * p : points) {
            const Point & currentPoint = *p;
            if(!currentPoint.equals(target)) {
                // ...
            }
        }

        return result;
    }
}
