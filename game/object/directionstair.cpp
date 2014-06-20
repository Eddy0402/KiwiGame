#include "directionstair.h"
#include "render/directionstairrenderer.h"

DirectionStair::DirectionStair(int dir) :
        StairBase(Point3D(),Velocity3D(),new DirectionStairRenderer(this)),
        direction_(dir)
{
    position_.x() = (float)rand() / RAND_MAX;
    position_.y() = (float)rand() / RAND_MAX;
}

void DirectionStair::Stand(Kiwi *kiwi)
{
    const int D[][2]={ {1,0},{-1,0},{0,-1},{0,1} };
    auto topPos = kiwi->getPoint3D();
    topPos.z() = this->position_.z();
    kiwi->setPosition(topPos);
    auto velocity = this -> getVelocity3D();
    velocity = velocity + Acceleration3D(0.2 * D[direction_][0],0.2 * D[direction_][1],0);
    kiwi->setVelocity(velocity);
}
