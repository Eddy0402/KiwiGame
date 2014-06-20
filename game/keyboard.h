#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QObject>
#include <QMap>
#include <QKeyEvent>

class KeyBoard : public QObject
{
    Q_OBJECT
public:
    explicit KeyBoard(QObject *parent = 0);
public slots:
    void KeyUp(int key);
    void KeyDown(int key);
public:
    bool getKeyState(int key);
private:
    QMap<int,bool> keyState_;
};

#endif // KEYBOARD_H
