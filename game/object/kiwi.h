#ifndef KIWI_H
#define KIWI_H

#include "game/object/objectbase.h"
#include "render/kiwirenderer.h"

class Kiwi : public ObjectBase
{
friend class KiwiRenderer;
public:
    Kiwi();
    virtual ~Kiwi(){}
    void Update(float tickDuration);
    void setPosition(const Point3D &position );
    void setVelocity( const Velocity3D &velocity );
private:
    Velocity3D playerMove();
};

#endif // KIWI_H
