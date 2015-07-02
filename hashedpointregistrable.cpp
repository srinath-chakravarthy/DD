#include "point.h"
#include <unordered_map>

namespace dd {

    std::string HashedPointRegistrable::getKey(const Point * p) const {
        return p->typeName();
    }

    std::string HashedPointRegistrable::getKey(const pointContainer::iterator & it) const {
        return getKey(*it);
    }

    pointContainer::iterator HashedPointRegistrable::registerPoint(Point * toRegister,
                                                                   pointContainer::iterator antecedentIt) {
        containers[getKey(antecedentIt)].insert(antecedentIt, toRegister);
        return --antecedentIt;
    }

    pointContainer::iterator HashedPointRegistrable::registerPoint(Point * p) {
        return registerPoint(p, containers[getKey(p)].end());
    }

    void HashedPointRegistrable::erasePoint(pointContainer::iterator it) {
        containers[getKey(it)].erase(it);
    }

    const pointContainer & HashedPointRegistrable::getContainer(std::string key) {
        return containers[key];
    }
}
