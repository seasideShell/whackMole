#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sc = new myScene;
    ui->graphicsView->setScene(sc);
    connect(ui->pb_start,&QPushButton::clicked,sc,&myScene::startGame);
    connect(ui->pb_pause,&QPushButton::clicked,sc,&myScene::pauseGame);
    connect(ui->pb_stop,&QPushButton::clicked,sc,&myScene::stopGame);
    scores = 0;
    addScores *sig = addScores::getMember();
    connect(sig,&addScores::add,this,&MainWindow::showScores);
    connect(sig,&addScores::reset,this,&MainWindow::resetScores);
    connect(sig,&addScores::startTime,this,&MainWindow::showTime);
    connect(sig,&addScores::sig_pauseTime,this,&MainWindow::setPause);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sc;
}

void MainWindow::showTime()
{
    if(ui->pb_pause->text() == "暂 停")
    {
        QTime currentTime = QTime::currentTime();
        QTime pt = sc->pauseTime;
        int temp = pt.secsTo(currentTime);
        *(sc->baseTime) = sc->baseTime->addSecs(temp);
        ui->pb_pause->setText("暂停");
        sc->ptimer_wc->start(1000);
    }
    else
    {
        QTime st = sc->startTime;
        QString str = st.toString("hh:mm:ss");
        ui->lcdNumber_watch->display(str);
    }

}

void MainWindow::showScores()
{
    scores += 10;
    ui->lcdNumber->display(scores);
}

void MainWindow::resetScores()
{
    int restart = 0;
    ui->lcdNumber->display(restart);
    QString stopTimeStr = "00:00";
    ui->lcdNumber_watch->display(stopTimeStr);
    ui->pb_pause->setText("暂停");
}

void MainWindow::setPause()
{
    ui->pb_pause->setText("暂 停");
}
