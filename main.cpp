#include "ddobject.h"
#include "domain.h"
#include "point.h"
#include "dderror.h"
#include "slipsystem.h"
#include "slipplane.h"
#include <iostream>
#include "point/dislocation.h"
#include "point/source.h"
#include <string>
#include <list>
#include "hashedpointregistrable.h"
#include "complex.h"

using namespace dd;
typedef long long ll;

int main() {

    /*

    Domain d(1);
    SlipSystem s(2. * asin(1) / 6, .25e-3);
    d.addSlipSystem(&s);
    SlipPlane sp0(&d, &s, Vector2d(0, 0));
    SlipPlane sp1(&d, &s, Vector2d(1, 0));
    SlipPlane sp2(&d, &s, Vector2d(2, 0));

    s.addSlipPlane(&sp0);
    s.addSlipPlane(&sp1);
    s.addSlipPlane(&sp2);

    SourcePoint src0 = SourcePoint(&d, &sp0, 0);
    SourcePoint src1 = SourcePoint(&d, &sp0, 2);

    DislocationPoint disloc0(&d, &sp1, 1);
    DislocationPoint disloc1(&d, &sp2, 2);

    std::cout << disloc0.getTypeName() << "\n"; */


    //std::cout << disloc0.getForce().x << " " << disloc0.getForce().y << "\n";

}
