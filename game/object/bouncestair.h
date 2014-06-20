#ifndef BOUNCESTAIR_H
#define BOUNCESTAIR_H

#include "stairbase.h"
#include "render/bouncestairrenderer.h"

class BounceStair : public StairBase
{
friend class BounceStairRenderer;
public:
    BounceStair();
    void Stand( Kiwi *kiwi );
    virtual ~BounceStair(){}
};

#endif // BOUNCESTAIR_H
