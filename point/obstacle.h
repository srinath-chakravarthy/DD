#ifndef OBSTACLE_H
#define OBSTACLE_H

namespace dd {

    class Point;
    class Domain;
    class SlipPlane;

    class ObstaclePoint : public Point {
    public:

        ObstaclePoint(Domain * domain, SlipPlane * sPlane) :
            Point(domain, sPlane) { }
        ObstaclePoint(Domain * domain, SlipPlane * sPlane, pointContainer::iterator antecedentIt) :
            Point(domain, sPlane, antecedentIt) { }

        virtual bool canMove() const { return false; }

        virtual bool canSpawn() const { return false; }

        virtual bool canRemove() const { return true; }
        virtual void remove();
    };

}

#endif // OBSTACLE_H
