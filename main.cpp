#include "window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Game game;
    Window &w = Window::Instance();
    w.resize(640,480);
    w.show();

    Model *m_ = new Model("Test.dae");
    QObject::connect(&w,&Window::render, [=](){m_->Render(0);} );

    return a.exec();
}
