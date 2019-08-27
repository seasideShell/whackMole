#ifndef ADDSCORES_H
#define ADDSCORES_H

#include <QObject>

class addScores : public QObject
{
    Q_OBJECT
private:
    explicit addScores(QObject *parent = nullptr);
    static addScores *adds;
signals:
    void add();
    void reset();
    void startTime();
    void sig_pauseTime();
public:
    static addScores * getMember();
    void sendSignal();
    void sendSignal_reset();
    void sendSignal_start();
    void sendSignal_pause();
public slots:
};

#endif // ADDSCORES_H
