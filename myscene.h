#ifndef MYSCENE_H
#define MYSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include "myitem.h"
#include <QTimer>
#include <QTime>
#include <QString>
#include <stdlib.h>

class myScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit myScene(QObject *parent = nullptr);
    ~myScene();
    void popMoles();
    void startGame();
    void pauseGame();
    void stopGame();
    void updateTime();
    QTimer *ptimer_wc;
    QTime *baseTime;
    QTime pauseTime;
    QTime startTime;
protected:

private:
    myItem *item[16];
    QTimer *ptimer;


signals:

public slots:
};

#endif // MYSCENE_H
