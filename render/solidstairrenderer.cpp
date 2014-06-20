#include "solidstairrenderer.h"
#include "game/object/solidstair.h"
#include <iostream>

using namespace std;

SolidStairRenderer::SolidStairRenderer(SolidStair *toDraw) :
    toDraw_(toDraw)
{
}

void SolidStairRenderer::Render()
{
    QPainter painter(&GameCore::Instance().GetWindow());
    painter.fillRect(toDraw_->position_.x() * Config::Width,Config::Height - toDraw_->position_.z() * Config::Height,100,10,QColor(100,100,100,255));
}
