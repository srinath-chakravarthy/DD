#pragma once
#include <vector>
#include "pointregistrable.h"
#include "hashedpointregistrable.h"
#include "ddobject.h"
#include <string>

namespace dd {

    class SlipSystem;
    class DislocationPoint;
    class Vector2d;

    /**
      * Problem domain.
      */
    class Domain : public HashedPointRegistrable {
    private:
        std::vector<SlipSystem *> sSystems;
    public:
        Domain(long long SlipPlaneCount);
        Domain();
        void addSlipSystem(SlipSystem * ss);
        Vector2d getForceOn(DislocationPoint * point);
    };
}
