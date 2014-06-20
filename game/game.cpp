#include "game.h"
#include "game/config.h"
#include "game/playingstate.h"

Game::Game(QObject *parent) :
    QObject(parent)
{}

void Game::Init()
{
    Config::Init();
    keyboard_ = new KeyBoard(this);
    window_ = new Window2D(); // TODO, memory
    window_ -> resize(Config::Width,Config::Height);
    window_ -> show();

    state_ = new PlayingState();

}

