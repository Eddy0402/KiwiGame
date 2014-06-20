#include "objectbase.h"

ObjectBase::ObjectBase(Point3D position,Velocity3D velocity,RendererBase *renderer) :
    position_(position),
    lastPosition_(position),
    velocity_(velocity),
    renderer_(renderer)
{}

Vector3D &Vector3D::operator+=(const Vector3D &rhs)
{
    return (*this) = (*this) + rhs;
}


Point3D operator+(const Point3D &position, const Velocity3D &velocity)
{
    return Point3D( position.x() + velocity.x(), position.y() + velocity.y(),position.z() + velocity.z());
}


Velocity3D operator*(const Velocity3D &velocity, float durationSecond)
{
    return Velocity3D(durationSecond*velocity.x(), durationSecond*velocity.y(), durationSecond*velocity.z());
}


