#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLCDNumber>
#include <QSpinBox>

#include "timer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void startButtonClicked();
    void stopButtonClicked();
    void onTick();

private:
    Ui::MainWindow *ui;
    Timer timer;
    QPushButton *startButton;
    QPushButton *stopButton;
    QLCDNumber *display;
    QSpinBox *hourSpinBox;
    QSpinBox *minSpinBox;
    QSpinBox *secSpinBox;
};

#endif // MAINWINDOW_H
