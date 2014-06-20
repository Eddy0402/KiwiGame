#ifndef STAIRBASE_H
#define STAIRBASE_H

#include "objectbase.h"
#include "kiwi.h"

class StairBase : public ObjectBase
{
public:
    explicit StairBase(Point3D position,Velocity3D velocity,RendererBase *renderer);
    virtual ~StairBase(){}

    void Update(float tickDuration);
    virtual void Stand(Kiwi *kiwi) = 0;
    bool OutOfBound();

    static QSharedPointer<StairBase> NewStair();
};

#endif // STAIRBASE_H
