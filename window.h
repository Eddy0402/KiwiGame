#ifndef WINDOW_H
#define WINDOW_H

#include <QtGui>
#include <QOpenGLFunctions_4_3_Core>
#include "loki/Singleton.h"
#include "render/model/model.h"

class Window : public QWindow
{
    Q_OBJECT
private:
    Window(QScreen *parent = 0);
    ~Window();
public:
    static Window &Instance(){ static Window *w = new Window(); return *w; }
    QOpenGLFunctions_4_3_Core *func(){ return func_; }
    Q_DISABLE_COPY(Window)
public slots:
    void update();
signals:
    void render();
protected:
    void exposeEvent(QExposeEvent *);
    void resizeEvent(QResizeEvent *);
private:
    void initializeGL();
    void paintGL();
    QSurfaceFormat initFormat();
    QOpenGLContext *context_;
    QOpenGLFunctions_4_3_Core *func_;

template<class T> friend class Loki::CreateUsingNew;
};

typedef Loki::SingletonHolder<Window,Loki::CreateUsingNew,Loki::NoDestroy> sWindow;
#define GLfunc sWindow::Instance().func()

#endif // WINDOW_H
