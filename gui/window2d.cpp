#include "window2d.h"
#include "game/game.h"

Window2D::Window2D(QWidget *parent) :
    QWidget(parent)
{
}

void Window2D::paintEvent(QPaintEvent *)
{
    emit render();
}

void Window2D::keyPressEvent(QKeyEvent *e)
{
    GameCore::Instance().GetKeyBoard().KeyDown(e->key());
}

void Window2D::keyReleaseEvent(QKeyEvent *e)
{
    GameCore::Instance().GetKeyBoard().KeyUp(e->key());
}
