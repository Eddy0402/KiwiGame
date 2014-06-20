#include "kiwi.h"
#include <QKeyEvent>

Kiwi::Kiwi() :
    ObjectBase( Point3D(0.5,0.5,1.0),Velocity3D (),new KiwiRenderer(this) )
{}

void Kiwi::Update(float tickDuration)
{
    lastPosition_ = position_;
    auto tickVelocity = playerMove();
    position_ = position_ + tickVelocity * tickDuration ;

    /* Debug */
    if(position_.x() < 0){
        position_.x() += 1;
        lastPosition_.x() += 1;
    }
    if(position_.y() < 0){
        position_.y() += 1;
        lastPosition_.y() += 1;
    }
    if(position_.z() < 0){
        position_.z() += 1;
        lastPosition_.z() += 1;
    }



    velocity_.x() *= 0.8;
    velocity_.y() *= 0.8;
    velocity_.z() += -0.005;
}

void Kiwi::setPosition(const Point3D &position)
{
    position_ = position;
}

void Kiwi::setVelocity(const Velocity3D &velocity)
{
    velocity_ = velocity;
}

Velocity3D Kiwi::playerMove()
{
    Velocity3D tickVelocity = velocity_;
    bool keyLeft  = GameCore::Instance().GetKeyBoard().getKeyState( Qt::Key_A );
    bool keyRight = GameCore::Instance().GetKeyBoard().getKeyState( Qt::Key_D );
    if(keyLeft == keyRight)
        return velocity_;
    if(keyLeft)
        tickVelocity.x() += -0.35;
    if(keyRight)
        tickVelocity.x() += 0.35;
    return tickVelocity;
}

