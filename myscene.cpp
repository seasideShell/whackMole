#include "myscene.h"
#include "addscores.h"


myScene::myScene(QObject *parent) : QGraphicsScene(parent)
{
    for(int i=0;i<16;i++)
    {
        item[i] = new myItem;
        item[i]->setPos(item[i]->boundingRect().width()*(i/4),item[i]->boundingRect().height()*(i%4));
        addItem(item[i]);
    }
    ptimer = new QTimer;
    connect(ptimer,&QTimer::timeout,this,&myScene::popMoles);
    ptimer_wc = new QTimer;
    connect(ptimer_wc,&QTimer::timeout,this,&myScene::updateTime);
    baseTime = new QTime;
}

void myScene::popMoles()
{
    int popNumber;
    popNumber = rand()%3 + 1;
    for(int i=0;i<16;i++)
    {
        item[i]->setPicture(":/bg/image/bg.jpg");
        item[i]->setMole(false);
    }
    for(int i=0;i<popNumber;i++)
    {
        int pop = rand()%16;
        item[pop]->setPicture(":/bg/image/beat.jpg");
        item[pop]->setMole(true);
    }
}

void myScene::startGame()
{
    ptimer_wc->start(1000);
    for(int i=0;i<16;i++)
        item[i]->setStart(true);
    ptimer->start(900);

    if(!item[0]->isPause())
        *baseTime = QTime::currentTime();

}

void myScene::stopGame()
{
    ptimer->stop();
    ptimer_wc->stop();
    for(int i=0;i<16;i++)
        item[i]->setPicture(":/bg/image/bg.jpg");
    for(int i=0;i<16;i++)
        item[i]->setStart(false);
    item[0]->setPause(false);
    addScores* res = addScores::getMember();
    res->sendSignal_reset();
}

void myScene::pauseGame()
{
    ptimer->stop();
    ptimer_wc->stop();
    pauseTime = QTime::currentTime();
    addScores *sig = addScores::getMember();
    sig->sendSignal_pause();
    for(int i=0;i<16;i++)
        item[i]->setStart(false);
    item[0]->setPause(true);
}

void myScene::updateTime()
{
    QTime currentTime = QTime::currentTime();
    QTime startTime_up(0,0,0);
    int interval = baseTime->secsTo(currentTime);
    startTime_up = startTime_up.addSecs(interval);
    startTime = startTime_up;
    addScores *sig = addScores::getMember();
    sig->sendSignal_start();
}



myScene::~myScene()
{
    for(int i=0;i<16;i++)
        delete item[i];
    delete ptimer;
    delete ptimer_wc;
    delete baseTime;
}
