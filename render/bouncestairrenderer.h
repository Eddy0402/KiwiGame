#ifndef BOUNCESTAIRRENDERER_H
#define BOUNCESTAIRRENDERER_H

#include "render/rendererbase.h"

class BounceStair;
class BounceStairRenderer : public RendererBase
{
public:
    BounceStairRenderer(BounceStair *toDraw);
    void Render();
private:
    BounceStair *toDraw_;
};

#endif // BOUNCESTAIRRENDERER_H
