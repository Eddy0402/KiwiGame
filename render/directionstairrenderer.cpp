#include "directionstairrenderer.h"
#include "game/object/directionstair.h"

DirectionStairRenderer::DirectionStairRenderer(DirectionStair *toDraw):
    toDraw_(toDraw)
{}

void DirectionStairRenderer::Render()
{
    QPainter painter(&GameCore::Instance().GetWindow());
    painter.fillRect(toDraw_->position_.x() * Config::Width,
                     Config::Height - toDraw_->position_.z() *Config::Height,
                     100,10,
                     QColor(0,0,toDraw_->direction_ * 50,255));
}
