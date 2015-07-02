#ifndef HASHEDPOINTREGISTRABLE_H
#define HASHEDPOINTREGISTRABLE_H

#include "pointregistrable.h"
#include <unordered_map>

namespace dd {

    class Point;

    class HashedPointRegistrable : public PointRegistrable {
    protected:
        std::unordered_map<std::string, pointContainer> containers;
        std::string getKey(const Point * p) const;
        std::string getKey(const pointContainer::iterator & it) const;
    public:

        /**
         * Register the given point before the given position.
         */
        virtual pointContainer::iterator registerPoint(Point * toRegister,
                                                       pointContainer::iterator antecedentIt);

        /**
         * Register the given point at the end of the container.
         */
        pointContainer::iterator registerPoint(Point * p);

        /**
         * Erase the registration at the given iterator. This must not
         * be called outside of PointRegistration.
         */
        virtual void erasePoint(pointContainer::iterator it);

        /**
         * Get the container of the given type.
         */
        virtual const pointContainer & getContainer(std::string key);
    };

}

#endif // HASHEDPOINTREGISTRABLE_H
