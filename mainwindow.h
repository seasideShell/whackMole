#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myscene.h"
#include "addscores.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showScores();
    void resetScores();
    void showTime();
    void setPause();
private:
    Ui::MainWindow *ui;
    myScene *sc;
    int scores;

};

#endif // MAINWINDOW_H
