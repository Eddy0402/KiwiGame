#ifndef DIRECTIONSTAIRRENDERER_H
#define DIRECTIONSTAIRRENDERER_H

#include "rendererbase.h"

class DirectionStair;
class DirectionStairRenderer : public RendererBase {
public:
    DirectionStairRenderer(DirectionStair *toDraw);
    void Render();
private:
    DirectionStair *toDraw_;
};

#endif // DIRECTIONSTAIRRENDERER_H
