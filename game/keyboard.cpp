#include "keyboard.h"
#include <iostream>

using namespace std;

KeyBoard::KeyBoard(QObject *parent) :
    QObject(parent)
{
}

void KeyBoard::KeyUp(int key)
{
    keyState_[key] = false;
}

void KeyBoard::KeyDown(int key)
{
    keyState_[key] = true;
}

bool KeyBoard::getKeyState(int key)
{
    return keyState_[key];
}
