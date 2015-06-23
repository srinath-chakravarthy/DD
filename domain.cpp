#include "domain.h"
#include "slipplane.h"

namespace dd {

    Domain::Domain(int sPlaneCount) {
        this->sPlanes.reserve(sPlaneCount);
    }

    Domain::Domain() : Domain::Domain(0) { }

}
