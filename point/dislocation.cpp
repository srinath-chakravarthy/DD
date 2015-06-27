
#include "../point.h"
#include "dislocation.h"
#include "../vector2d.h"
#include "../slipsystem.h"
#include "../slipplane.h"
#include "../domain.h"

namespace dd {

    void DislocationPoint::move() {

    }

    void DislocationPoint::spawn() {

    }

    void DislocationPoint::remove() {

    }

    double DislocationPoint::getBurgersMagnitude() const {
        return sPlaneRegistration->getTarget()->getSlipSystem()->getBurgersMagnitude();
    }

    Vector2d DislocationPoint::getBurgersVector() const {
        return sPlaneRegistration->getTarget()->getSlipSystem()->getDirection() *
               sPlaneRegistration->getTarget()->getSlipSystem()->getBurgersMagnitude();
    }

    Vector2d DislocationPoint::getForce() {
        return domainRegistration->getTarget()->getForceOn(this);
    }
}
