#include "bouncestair.h"

BounceStair::BounceStair() :
    StairBase(Point3D(),Velocity3D(),new BounceStairRenderer(this))
{
    position_.x() = (float)rand() / RAND_MAX;
    position_.y() = (float)rand() / RAND_MAX;
}

void BounceStair::Stand(Kiwi *kiwi)
{
    auto velocity = velocity_;
    if(kiwi->getVelocity3D().z() < 0)
        velocity.z() = velocity.z() - kiwi->getVelocity3D().z() * 1.0 / 1.414 + 0.2;
    else
        velocity.z() = kiwi->getVelocity3D().z();
    kiwi->setVelocity( velocity );
}
