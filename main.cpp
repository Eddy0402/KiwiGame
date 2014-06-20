#include "game/game.h"
#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameCore::Instance().Init();

    return a.exec();
}
