#pragma once
#include <vector>
#include "pointregistrable.h"
#include "hashedpointregistrable.h"
#include "ddobject.h"
#include "vector.h"
#include <string>

namespace dd {

    class SlipSystem;
    class DislocationPoint;

    /**
      * Problem domain.
      */
    class Domain : public HashedPointRegistrable {
#define DOMAIN_NAME "Domain"
    private:
        std::vector<SlipSystem *> sSystems;
    public:
        Domain(long long SlipPlaneCount);
        Domain();
        void addSlipSystem(SlipSystem * ss);
        Vector2d getForceOn(DislocationPoint * point);

        virtual string typeName() const { return DOMAIN_NAME; }
        static string staticTypeName() { return DOMAIN_NAME; }
    };
}
