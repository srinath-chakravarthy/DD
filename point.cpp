#include "point.h"
#include "dderror.h"
#include <string>

namespace dd {
    void Point::move() {
        DdError::exception("Point cannot move.");
    }

    void Point::spawn() {
        DdError::exception("Point cannot spawn.");
    }

    void Point::remove() {
        DdError::exception("Point cannot be removed.");
    }
}

