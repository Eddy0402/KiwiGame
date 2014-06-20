#include "gui/window2d.h"
#include "game/game.h"
#include "game/config.h"
#include "game/playingstate.h"
#include "game/CollisionHelper.h"
#include <QWindow>
#include <QTimer>
#include <iostream>
using namespace std;

PlayingState::PlayingState() :
    startTime_( Clock::now() ),
    lastTime_( Clock::now() ),
    processedAddTime_( 0 )
{ Start(); }

void PlayingState::Start()
{
    Initialize();

    QTimer *timer = new QTimer(this);
    QObject::connect(timer,&QTimer::timeout,this,&PlayingState::Tick);
    timer -> start(1000.0/60);
    QObject::connect(&GameCore::Instance().GetWindow(),&Window2D::render,this,&PlayingState::Draw);
}

void PlayingState::Tick()
{
    const TClock now = Clock::now();
    const TDurationNanoSecond tickDuration = now - lastTime_;

    int addTime = (now - startTime_).count() / Config::AddStairTestTime.count();
    int addTest = addTime - processedAddTime_;
    for(int add = 0;add < addTest;++add){
        if(rand() % Config::AddStairChance == 0){
            stairs_.push_back(StairBase::NewStair());
        }
    }
    processedAddTime_ = addTime;

    Update(tickDuration.count() / 1000000000.0);
    CollisionTest();
    GameCore::Instance().GetWindow().repaint(); // Inform Window to repaint

    lastTime_ = now;
}

void PlayingState::Draw()
{
    for( auto stair : stairs_ ){
        stair -> Draw();
    }
    kiwi_ -> Draw();
}

void PlayingState::Initialize()
{
    kiwi_ = new Kiwi();
}

void PlayingState::Update(float tickDuration)
{
    for( auto stair : stairs_ ){
        stair -> Update( tickDuration );
    }
    stairs_.erase(
        std::remove_if( stairs_.begin(),stairs_.end(),[](QSharedPointer<StairBase> &a){ return a -> OutOfBound(); } ),
        stairs_.end()
    );
    kiwi_ -> Update( tickDuration );
    //clog << "Current stair : " << stairs_.size() << endl;
}

void PlayingState::CollisionTest()
{
    CollisionHelper &helper = sCollisionHelper::Instance();
    for(auto stair : stairs_)
        helper.Collide( kiwi_ , stair.data() );
}
