#include "kiwirenderer.h"
#include "game/object/kiwi.h"

KiwiRenderer::KiwiRenderer(Kiwi *toDraw) :
    toDraw_(toDraw)
{}

void KiwiRenderer::Render()
{
    QPainter painter(&GameCore::Instance().GetWindow());
    painter.fillRect( toDraw_->getPoint3D().x() * Config::Width,
                      Config::Height - toDraw_->getPoint3D().z() *Config::Height,
                      30,30,
                      QColor(100,100,100,255));
}
