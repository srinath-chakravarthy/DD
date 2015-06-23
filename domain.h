#pragma once
#include <vector>
#include "pointregistrable.h"
#include "ddobject.h"

namespace dd {

    class SlipPlane;

    /**
      * Problem domain.
      */
    class Domain : public PointRegistrable {
    private:
        std::vector<SlipPlane> sPlanes;
    public:
        Domain(int SlipPlaneCount);
        Domain();
    };
}
