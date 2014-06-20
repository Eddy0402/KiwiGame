#include "game/CollisionHelper.h"
#include "game/object/kiwi.h"
#include "game/object/bouncestair.h"
#include "game/object/solidstair.h"
#include "game/object/directionstair.h"
#include <iostream>

using namespace std;

CollisionHelper::CollisionHelper()
{
    dispatcher.Add<Kiwi,SolidStair,true>( &CollisionHelper::KiwiToStair );
    dispatcher.Add<Kiwi,BounceStair,true>( &CollisionHelper::KiwiToStair );
    dispatcher.Add<Kiwi,DirectionStair,true>( &CollisionHelper::KiwiToStair );
}

void CollisionHelper::Collide(ObjectBase *lhs, ObjectBase *rhs)
{
    try{
        dispatcher.Go(*lhs,*rhs);
    }catch(std::runtime_error &error){
        cerr << error.what() << endl;
    }
}

void CollisionHelper::KiwiToStair(Kiwi &kiwi, StairBase &stair)
{
    if(kiwi.getPoint3D().x() > stair.getPoint3D().x() && kiwi.getPoint3D().x() < stair.getPoint3D().x() + 0.1  ){
        if( max(kiwi.getPoint3D().z(),kiwi.getLastPoint3D().z()) < min(stair.getPoint3D().z(),stair.getLastPoint3D().z()) ||
            min(kiwi.getPoint3D().z(),kiwi.getLastPoint3D().z()) > max(stair.getPoint3D().z(),stair.getLastPoint3D().z()) ){
            // Do nothing
        }else{
            stair.Stand(&kiwi);
        }
    }
}

