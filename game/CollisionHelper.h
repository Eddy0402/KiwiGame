#ifndef COLLISIONHELPER_H
#define COLLISIONHELPER_H

#include <loki/MultiMethods.h>
#include <loki/Singleton.h>
#include "object/objectbase.h"

class StairBase;
class SolidStair;
class Kiwi;

class CollisionHelper{
public:
    CollisionHelper();
    void Collide(ObjectBase*,ObjectBase*);
private:
    Loki::FunctorDispatcher<ObjectBase, ObjectBase, void, Loki::StaticCaster, Loki::BasicDispatcher> dispatcher;

public:
    static void KiwiToStair(Kiwi &kiwi, StairBase &stair);
};

typedef Loki::SingletonHolder<CollisionHelper> sCollisionHelper;

#endif // COLLISIONHELPER_H

