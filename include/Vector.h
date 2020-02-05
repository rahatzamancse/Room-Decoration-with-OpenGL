#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>
#include <iostream>

class Vector
{
    public:
        Vector(double x=0, double y=0, double z=0);

        double getX();
        double getY();
        double getZ();

        void setX(double newX);
        void setY(double newY);
        void setZ(double newZ);

        Vector cross(Vector v);
        Vector unit();

        Vector operator*(Vector v);
        Vector operator+(Vector v);
        Vector operator-(Vector v);

        void operator*=(Vector v);
        void operator+=(Vector v);
        void operator-=(Vector v);

        Vector operator*(double s);
        Vector operator+(double s);
        Vector operator-(double s);

        friend std::ostream & operator << (std::ostream &out, Vector v);

        double angle(Vector v);
        double magnitude();

    protected:

    private:
        double x=0, y=0, z=0;
};

#endif // VECTOR_H
