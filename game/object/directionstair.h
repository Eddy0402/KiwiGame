#ifndef DIRECTIONSTAIR_H
#define DIRECTIONSTAIR_H

#include "stairbase.h"

class DirectionStair : public StairBase
{
friend class DirectionStairRenderer;
public:
    DirectionStair(int dir);
    void Stand(Kiwi *kiwi);
    virtual ~DirectionStair(){}
private:
    int direction_;
};

#endif // DIRECTIONSTAIR_H
