#include "Vector.h"

Vector::Vector(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

// Getters and Setters
double Vector::getX() { return x; }
double Vector::getY() { return y; }
double Vector::getZ() { return z; }
void Vector::setX(double newX) { x = newX; }
void Vector::setY(double newY) { y = newY; }
void Vector::setZ(double newZ) { z = newZ; }

Vector Vector::unit() {
    double div = sqrt(getX()*getX() + getY()*getY() + getZ()*getZ());
    return Vector(getX()/div, getY()/div, getZ()/div);
}

Vector Vector::cross(Vector v) {
    double x = getY() * v.getZ() - getZ() * v.getY();
    double y = getZ() * v.getX() - getX() * v.getZ();
    double z = getX() * v.getY() - getY() * v.getX();
    return Vector(x, y, z);
}

double Vector::angle(Vector v) {
    double sinVal = (this->operator*(v)).magnitude() / (magnitude() * v.magnitude());
    return asin(sinVal);
}

double Vector::magnitude() {
    return sqrt(getX()*getX() + getY()*getY() + getZ()*getZ());
}

// Operators Overloadings

std::ostream& operator<< (std::ostream &out, Vector v) {
    out << "X : " << v.getX() << "; " << "Y : " << v.getY() << "; " << "Z : " << v.getZ() << ";";
}

Vector Vector::operator*(Vector v) {
    return Vector(getX()*v.getX(), getY()*v.getY(), getZ()*v.getZ());
}

Vector Vector::operator+(Vector v) {
    return Vector(getX()+v.getX(), getY()+v.getY(), getZ()+v.getZ());
}

Vector Vector::operator-(Vector v) {
    return Vector(getX()-v.getX(), getY()-v.getY(), getZ()-v.getZ());
}

void Vector::operator*=(Vector v) {
    setX(getX()*v.getX());
    setY(getY()*v.getY());
    setZ(getZ()*v.getZ());
}

void Vector::operator+=(Vector v) {
    setX(getX()+v.getX());
    setY(getY()+v.getY());
    setZ(getZ()+v.getZ());
}

void Vector::operator-=(Vector v) {
    setX(getX()-v.getX());
    setY(getY()-v.getY());
    setZ(getZ()-v.getZ());
}

Vector Vector::operator*(double s) {
    return Vector(getX()*s, getY()*s, getZ()*s);
}

Vector Vector::operator+(double s) {
    return Vector(getX()+s, getY()+s, getZ()+s);
}

Vector Vector::operator-(double s) {
    return Vector(getX()-s, getY()-s, getZ()-s);
}
