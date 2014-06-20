#ifndef WINDOW2D_H
#define WINDOW2D_H

#include <QWidget>
#include <QKeyEvent>

class Window2D : public QWidget
{
    Q_OBJECT
public:
    explicit Window2D(QWidget *parent = 0);
    ~Window2D() {}
signals:
    void render();
protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *e);

};


#endif // WINDOW2D_H
