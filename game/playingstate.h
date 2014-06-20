#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H

#include <QList>
#include <QSharedPointer>
#include "gamestatebase.h"
#include "game/object/stairbase.h"
#include "game/object/kiwi.h"

class PlayingState : public GameStateBase
{
public:
    PlayingState();
    void Start();
    virtual ~PlayingState(){}
public slots:
    void Tick();
public:
    void Draw();
private:
    void Initialize();
    void Update(float tickDuration);
    void CollisionTest();

    Kiwi *kiwi_;
    QList<QSharedPointer<StairBase>> stairs_;
    TClock startTime_, lastTime_;
    int processedAddTime_;
};

#endif // PLAYINGSTATE_H
