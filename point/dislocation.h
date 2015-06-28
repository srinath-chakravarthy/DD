#ifndef DISLOCATION_H
#define DISLOCATION_H

namespace dd {

    class Point;
    class Domain;
    class SlipPlane;

    class DislocationPoint : public Point {
    private:
        double burgersMagnitude;
    public:

        DislocationPoint(Domain * domain, SlipPlane * sPlane, double slipPlanePosition) :
            Point(domain, sPlane, slipPlanePosition) { }
        DislocationPoint(Domain * domain, SlipPlane * sPlane,
                         pointContainer::iterator antecedentIt, double slipPlanePosition) :
            Point(domain, sPlane, antecedentIt, slipPlanePosition)  { }

        virtual bool canMove() const { return true; }
        virtual void move();

        virtual bool canSpawn() const { return true; }
        virtual void spawn();

        virtual bool canRemove() const { return true; }
        virtual void remove();

    };

}

#endif // DISLOCATION_H
