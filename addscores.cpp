#include "addscores.h"

addScores* addScores::adds = new addScores;

addScores::addScores(QObject *parent) : QObject(parent)
{

}

addScores* addScores::getMember()
{
    return adds;
}

void addScores::sendSignal()
{
    emit add();
}

void addScores::sendSignal_reset()
{
    emit reset();
}

void addScores::sendSignal_start()
{
    emit startTime();
}

void addScores::sendSignal_pause()
{
    emit sig_pauseTime();
}
