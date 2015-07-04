#pragma once
#include <vector>
#include "hashedregistrable.h"
#include "ddobject.h"
#include "vector.h"
#include <string>

namespace dd {

    class SlipSystem;
    class Point;
    class DislocationPoint;

    /**
     * Problem domain.
     */
    class Domain : public HashedRegistrable<Point> {
#define DOMAIN_NAME "Domain"
    private:
        double propModulus;
        double propPassionsRatio;
        std::vector<SlipSystem *> sSystems;
    public:
        Domain(const double & propModulus, const double & propPassionsRatio);
        Domain();


        void addSlipSystem(SlipSystem * ss);


        double getModulus() const;
        double getPassionsRatio() const;

        virtual string typeName() const { return DOMAIN_NAME; }
        static string staticTypeName() { return DOMAIN_NAME; }
    };
}
