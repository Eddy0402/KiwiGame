#ifndef KIWIRENDERER_H
#define KIWIRENDERER_H

#include "render/rendererbase.h"

class Kiwi;
class KiwiRenderer : public RendererBase
{
public:
    explicit KiwiRenderer(Kiwi *toDraw);
    void Render();
private:
    Kiwi *toDraw_;
};

#endif // KIWIRENDERER_H
