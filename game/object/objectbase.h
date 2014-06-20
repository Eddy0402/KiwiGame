#ifndef OBJECTBASE_H
#define OBJECTBASE_H

#include "render/rendererbase.h"
#include "game/config.h"
#include <QSharedPointer>
#include <iostream>

using namespace std;

class Vector3D{
public:
    Vector3D() : x_(0),y_(0),z_(0){}
    Vector3D(float x,float y,float z) : x_(x),y_(y),z_(z){}
    float &x() { return x_; }
    float &y() { return y_; }
    float &z() { return z_; }
    const float &x() const { return x_; }
    const float &y() const { return y_; }
    const float &z() const { return z_; }
    Vector3D &operator+=( const Vector3D &rhs);
private:
    float x_,y_,z_;
};

typedef Vector3D Acceleration3D;
typedef Vector3D Velocity3D ;
typedef Vector3D Shift3D;
typedef Vector3D Point3D;

Point3D operator+( const Point3D& position,const Shift3D &velocity);
Shift3D operator*( const Velocity3D& velocity,float durationSecond);

class ObjectBase {
friend class CollisionHelper;
public:
    ObjectBase(Point3D position,Velocity3D velocity,RendererBase *renderer);
    virtual ~ObjectBase(){}
    virtual void Update(float tickDuration) = 0;
    void Draw() { renderer_ -> Render(); }

    const Velocity3D &getVelocity3D()  { return velocity_;     }
    const Point3D    &getPoint3D()     { return position_;     }
    const Point3D    &getLastPoint3D() { return lastPosition_; }

protected:
    Point3D position_, lastPosition_;
    Velocity3D velocity_;
    RendererBase *renderer_;
};

#endif // OBJECTBASE_H


