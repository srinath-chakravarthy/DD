#include "domain.h"
#include "slipsystem.h"
#include "dderror.h"
#include "point.h"

namespace dd {

    Domain::Domain(long long slipSystemCount) {
        this->sSystems.reserve(slipSystemCount);
    }

    Domain::Domain() : Domain::Domain(0) { }

    void Domain::addSlipSystem(SlipSystem * slipSystem) {
        sSystems.push_back(slipSystem);
    }

    void Domain::addSlipSystem(const double & angle, const double & mag) {
        addSlipSystem(new SlipSystem(angle, mag));
    }
}
