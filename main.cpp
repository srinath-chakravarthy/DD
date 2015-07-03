#include "ddobject.h"
#include "domain.h"
#include "point.h"
#include "dderror.h"
#include "slipsystem.h"
#include "slipplane.h"
#include <iostream>
#include "point/dislocation.h"
#include "point/obstacle.h"
#include "point/source.h"
#include <string>
#include <list>
#include "complex.h"
#include "vector.h"
#include "hashedregistrable.h"

using namespace dd;
typedef long long ll;

int main() {

    Domain d(1);

    SlipSystem ss0 = SlipSystem(1, 1);
    d.addSlipSystem(&ss0);

    SlipPlane sp0 = SlipPlane(&d, &ss0, {0, 0});

    DislocationPoint dis0 = DislocationPoint(&d, &sp0, 0, 1,
                                             sp0.getContainer<ObstaclePoint>().end(),
                                             sp0.getContainer<ObstaclePoint>().rend());
    DislocationPoint dis1 = DislocationPoint(&d, &sp0, 1, -1,
                                             sp0.getContainer<ObstaclePoint>().end(),
                                             sp0.getContainer<ObstaclePoint>().rend());

    std::cout << "Dislocation point count: " << sp0.getContainer<DislocationPoint>().size() << "\n";
    Vector<2> force, v2;
    Vector<3> stress;

    dis0.addForceContribution<DislocationPoint>(force, v2, stress);

    std::cout << force[0] << " " << force[1] << "\n";

    return 0;
}
