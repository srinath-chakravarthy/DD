#include "domain.h"
#include "slipsystem.h"
#include "point.h"
#include "vector.h"
#include "point/dislocation.h"
#include "point/source.h"
#include <cmath>
#include "complex.h"
#include <string>

namespace dd {

    Domain::Domain(long long slipSystemCount) {
        this->sSystems.reserve(slipSystemCount);
    }

    Domain::Domain() : Domain::Domain(0) { }

    void Domain::addSlipSystem(SlipSystem * slipSystem) {
        sSystems.push_back(slipSystem);
    }
}

