#include "solidstair.h"
#include "game/config.h"

SolidStair::SolidStair() :
    StairBase(Point3D(),Velocity3D(),new SolidStairRenderer(this))
{
    position_.x() = (float)rand() / RAND_MAX;
    position_.y() = (float)rand() / RAND_MAX;
}

void SolidStair::Stand(Kiwi *kiwi)
{
    auto topPos = kiwi->getPoint3D();
    topPos.z() = this->position_.z();
    kiwi->setPosition(topPos);
    kiwi->setVelocity(this->getVelocity3D());
}
