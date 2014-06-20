#include "bouncestairrenderer.h"
#include "game/object/bouncestair.h"

BounceStairRenderer::BounceStairRenderer(BounceStair *toDraw) :
    toDraw_(toDraw)
{
}

void BounceStairRenderer::Render()
{
    QPainter painter(&GameCore::Instance().GetWindow());
    painter.fillRect(toDraw_->position_.x() * Config::Width,Config::Height - toDraw_->position_.z() *Config::Height,100,10,QColor(0,100,100,255));
}
