#ifndef OBSTACLE_H
#define OBSTACLE_H

namespace dd {

    class Point;
    class Domain;
    class SlipPlane;

    class ObstaclePoint : public Point {
    public:

        ObstaclePoint(Domain * domain, SlipPlane * sPlane, double slipPlanePosition) :
            Point(domain, sPlane, slipPlanePosition) { }
        ObstaclePoint(Domain * domain, SlipPlane * sPlane,
                      pointContainer::iterator antecedentIt, double slipPlanePosition) :
            Point(domain, sPlane, antecedentIt, slipPlanePosition) { }

        virtual bool canMove() const { return false; }

        virtual bool canSpawn() const { return false; }

        virtual bool canRemove() const { return true; }
        virtual void remove();
    };

}

#endif // OBSTACLE_H
