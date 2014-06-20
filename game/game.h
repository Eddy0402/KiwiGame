#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <loki/Singleton.h>
#include "game/gamestatebase.h"
#include "game/keyboard.h"
#include "gui/window2d.h"

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = 0);
    void Init();
    Window2D      &GetWindow()  { return *window_;   }
    KeyBoard      &GetKeyBoard(){ return *keyboard_; }
    GameStateBase &GetState()   { return *state_;    }
private:
    Window2D *window_;
    KeyBoard *keyboard_;
    GameStateBase *state_;
};

typedef Loki::SingletonHolder<Game,Loki::CreateUsingNew,Loki::NoDestroy> GameCore;

#endif // GAME_H
