#pragma once
#include <vector>
#include "pointregistrable.h"
#include "ddobject.h"

namespace dd {

    class SlipSystem;
    class Vector2d;

    /**
      * Problem domain.
      */
    class Domain : public PointRegistrable {
    private:
        std::vector<SlipSystem *> sSystems;
    public:
        Domain(long long SlipPlaneCount);
        Domain();
        void addSlipSystem(SlipSystem * ss);
        void addSlipSystem(const double &, const double &);
    };
}
