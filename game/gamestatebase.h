#ifndef GAMESTATEBASE_H
#define GAMESTATEBASE_H

#include<QObject>

class GameStateBase : public QObject
{
    Q_OBJECT
public:
    explicit GameStateBase();
    virtual void Tick() = 0;
    virtual ~GameStateBase(){}
};

#endif // GAMESTATEBASE_H
