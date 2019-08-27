#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsPixmapItem>
#include <QString>
#include <QGraphicsSceneMouseEvent>


class myItem : public QGraphicsPixmapItem
{
public:
    myItem();
    void setPicture(QString path);
    bool isMole();
    void setMole(bool mole);
    bool isStart();
    void setStart(bool start);
    bool isPause();
    void setPause(bool pause);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

signals:

public slots:
private:
    bool mole;
    bool start;
    bool pause;
};

#endif // MYITEM_H
