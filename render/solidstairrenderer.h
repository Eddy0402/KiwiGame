#ifndef SOLIDSTAIRRENDERER_H
#define SOLIDSTAIRRENDERER_H

#include"rendererbase.h"

class SolidStair;
class SolidStairRenderer : public RendererBase
{
public:
    explicit SolidStairRenderer(SolidStair *toDraw);
    void Render();
private:
    SolidStair *toDraw_;
};

#endif // SOLIDSTAIRRENDERER_H
