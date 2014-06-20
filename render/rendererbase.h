#ifndef RENDERERBASE_H
#define RENDERERBASE_H

#include <QPainter>
#include "game/config.h"
#include "game/game.h"

class RendererBase
{
public:
    explicit RendererBase() {}
    virtual void Render() = 0;
};

#endif // RENDERERBASE_H
