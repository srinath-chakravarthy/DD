#pragma once
#include <vector>
#include "pointregistrable.h"
#include "ddobject.h"

namespace dd {

    class SlipPlane;
    class Vector2d;

    /**
      * Problem domain.
      */
    class Domain : public PointRegistrable {
    private:
        std::vector<SlipPlane> sPlanes;
    public:
        Domain(int SlipPlaneCount);
        Domain();
        Vector2d calculateForce(const Point &);
    };
}
