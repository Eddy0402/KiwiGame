#ifndef WINDOW_H
#define WINDOW_H

#include <QWindow>

class Window : public QWindow
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = 0);

signals:

public slots:

};

#endif // WINDOW_H
