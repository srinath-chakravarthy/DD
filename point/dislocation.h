#ifndef DISLOCATION_H
#define DISLOCATION_H

namespace dd {

    class Point;
    class Domain;
    class SlipPlane;

    class DislocationPoint : public Point {
#define DISLOCATIONPOINT_NAME "DislocationPoint"
    private:
        double burgersMagnitude;
    public:

        DislocationPoint(Domain * domain, SlipPlane * sPlane, double slipPlanePosition) :
            Point(domain, sPlane, slipPlanePosition) { }
        DislocationPoint(Domain * domain, SlipPlane * sPlane,
                         typename list<Point *>::iterator antecedentIt, double slipPlanePosition) :
            Point(domain, sPlane, antecedentIt, slipPlanePosition)  { }

        virtual bool canMove() const { return true; }
        virtual void move();

        virtual bool canSpawn() const { return true; }
        virtual void spawn();

        virtual bool canRemove() const { return true; }
        virtual void remove();

        virtual string typeName() const { return DISLOCATIONPOINT_NAME; }
        static string staticTypeName() { return DISLOCATIONPOINT_NAME; }
    };

}

#endif // DISLOCATION_H
