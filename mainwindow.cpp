#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QTime>
#include <QTimer>
#include <stdio.h>
#include <string>

static QTime *startTime = nullptr;
static QTimer *myTimer = nullptr;
static int totalSecs = 0;

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startButton = ui->pushButton_start;
    stopButton = ui->pushButton_stop;
    display = ui->lcdNumber;
    display->display("00:00:00");
    hourSpinBox = ui->spinBox_hours;
    minSpinBox = ui->spinBox_minutes;
    secSpinBox = ui->spinBox_seconds;


    connect(startButton, &QPushButton::clicked, this, &MainWindow::startButtonClicked);
    connect(stopButton, &QPushButton::clicked, this, &MainWindow::stopButtonClicked);

    startTime = new QTime();
    myTimer = new QTimer(this);
    connect(myTimer, &QTimer::timeout, this, &MainWindow::onTick);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete startTime;
    delete myTimer;
}

void MainWindow::startButtonClicked()
{

    if (startTime->isNull()) {
        std::cout << "Starting!!!" << std::endl;
        *startTime = QTime::currentTime();
        startTime->start();
        myTimer->start(1000);
        totalSecs = 360 * hourSpinBox->value() + 60 * minSpinBox->value() + secSpinBox->value();
    } else {
        std::cout << "Already Running!!!...." << (startTime->elapsed() / 1000) << std::endl;
    }

}
void MainWindow::stopButtonClicked()
{
    std::cout << "Stopping!!!" << std::endl;
    *startTime = QTime();
    myTimer->stop();
}

void MainWindow::onTick()
{
    int secsElapsed = startTime->elapsed() / 1000;
    int secsRemaining = totalSecs - secsElapsed;
    if (secsRemaining <= 0) {
       display->display("00:00:00");
       myTimer->stop();
       *startTime = QTime();
       cout << "Timer Complete!!!" << endl;
    } else {
        int secs = secsRemaining % 60;
        int mins = (secsRemaining / 60) % 60;
        int hrs = secsRemaining / 3600;
        std::cout << "On tick!! hrs: " << hrs << std::endl;
        QString timeString = QString("%1:%2:%3")
                        .arg(hrs, 2, 10, QLatin1Char('0'))
                        .arg(mins,2, 10 ,QLatin1Char('0'))
                        .arg(secs,2, 10 ,QLatin1Char('0'));
        display->display(timeString);
        cout << "timeString: " << timeString.toStdString() << endl;
    }
}
