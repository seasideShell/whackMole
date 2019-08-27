#include "myitem.h"
#include <QCursor>
#include "addscores.h"

myItem::myItem()
{
    setPixmap(QPixmap(":/bg/image/bg.jpg"));
    setCursor(QCursor(QPixmap(":/bg/image/up.png")));
    pause = false;
}

void myItem::setPicture(QString path)
{
    setPixmap(QPixmap(path));
}

void myItem::setMole(bool mole)
{
    this->mole = mole;
}

bool myItem::isMole()
{
    return mole;
}

void myItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(QCursor(QPixmap(":/bg/image/down.png")));
    if(isStart())
    {
        if(isMole())
        {
            setPixmap(QPixmap(":/bg/image/out.jpg"));
            addScores *sig = addScores::getMember();
            sig->sendSignal();
            setMole(false);
        }
    }
}

void myItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(QCursor(QPixmap(":/bg/image/up.png")));
}

void myItem::setStart(bool start)
{
    this->start = start;
}

bool myItem::isStart()
{
    return start;
}

void myItem::setPause(bool pause)
{
    this->pause = pause;
}

bool myItem::isPause()
{
    return pause;
}
