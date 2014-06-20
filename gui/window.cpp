#include "window.h"
#include<iostream>
using namespace std;

/* Public */

Window::Window(QScreen *parent)
    : QWindow(parent)
{
    QSurfaceFormat format = initFormat();
    setSurfaceType( OpenGLSurface );
    setFormat( format );
    create();

    context_ = new QOpenGLContext(this);
    context_ -> setFormat( format );
    context_ -> create();
    context_ -> makeCurrent( this );

    initializeGL();
}

Window::~Window()
{


}

void Window::update()
{
    if( !isExposed() ) return;
    paintGL();
    context_ -> swapBuffers(this);
}

/* Protected */

void Window::exposeEvent(QExposeEvent *)
{
    if( isExposed() ) update();
}

void Window::resizeEvent(QResizeEvent *)
{
    if( isExposed() ) update();
}

/* Private */

void Window::initializeGL(){
    func_ = context_ -> versionFunctions<QOpenGLFunctions_4_3_Core>();
    func_ -> initializeOpenGLFunctions();
    func_ -> glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
}

void Window::paintGL()
{
    func_ -> glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    emit render();
}

QSurfaceFormat Window::initFormat(){
    QSurfaceFormat format;
    format.setDepthBufferSize( 32 );
    format.setMajorVersion( 4 );
    format.setMinorVersion( 3 );
    format.setSamples( 4 );
    format.setProfile( QSurfaceFormat::CoreProfile );
    return format;
}
