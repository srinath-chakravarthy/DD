
#include "../point.h"
#include "dislocation.h"
#include "../vector.h"
#include "../slipsystem.h"
#include "../slipplane.h"
#include "../domain.h"

namespace dd {

    DislocationPoint::DislocationPoint(Domain * domain, SlipPlane * sPlane, double slipPlanePosition, int burgersSign,
                     typename list<ObstaclePoint *>::iterator nextObstacle,
                     typename list<ObstaclePoint *>::reverse_iterator prevObstacle) :
            Point(domain, sPlane, slipPlanePosition),
            BetweenPoints<ObstaclePoint>(nextObstacle, prevObstacle),
            burgersSign(burgersSign) { }
    DislocationPoint::DislocationPoint(Domain * domain, SlipPlane * sPlane,
                         typename list<Point *>::iterator antecedentIt, double slipPlanePosition, int burgersSign,
                         typename list<ObstaclePoint *>::iterator nextObstacle,
                         typename list<ObstaclePoint *>::reverse_iterator prevObstacle) :
            Point(domain, sPlane, antecedentIt, slipPlanePosition),
            BetweenPoints<ObstaclePoint>(nextObstacle, prevObstacle),
            burgersSign(burgersSign) { }

    void DislocationPoint::move() {

    }

    void DislocationPoint::spawn() {

    }

    void DislocationPoint::remove() {

    }
}
