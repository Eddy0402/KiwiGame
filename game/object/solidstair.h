#ifndef CONCRETESTAIR_H
#define CONCRETESTAIR_H

#include "stairbase.h"
#include "render/solidstairrenderer.h"

class SolidStair : public StairBase
{
friend class SolidStairRenderer;
public:
    explicit SolidStair();
    void Stand( Kiwi *kiwi );
    virtual ~SolidStair(){}
};

#endif // CONCRETESTAIR_H

