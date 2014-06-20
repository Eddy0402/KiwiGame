#include "game/config.h"
#include "game/object/solidstair.h"
#include "game/object/bouncestair.h"
#include "game/object/directionstair.h"

StairBase::StairBase(Point3D position,Velocity3D velocity,RendererBase *renderer) :
    ObjectBase(position,velocity,renderer)
{}

void StairBase::Update(float tickDuration)
{
    lastPosition_ = position_;
    position_ += Velocity3D(0,0,Config::StairSpeedPerSecond) * tickDuration;
}

bool StairBase::OutOfBound()
{
    return position_.z() > 1.1 ? true : false;
}

QSharedPointer<StairBase> StairBase::NewStair()
{
    enum Type{ SOLID ,BOUNCE, DIRECTION_LEFT, DIRECTION_RIGHT,TYPECOUNT };
    switch(rand() % TYPECOUNT){
    case SOLID:
        return QSharedPointer<StairBase>(new SolidStair());
    case BOUNCE:
        return QSharedPointer<StairBase>(new BounceStair());
    case DIRECTION_LEFT:
        return QSharedPointer<StairBase>(new DirectionStair(0));
    case DIRECTION_RIGHT:
        return QSharedPointer<StairBase>(new DirectionStair(1));
    }
    return QSharedPointer<StairBase>();
}
