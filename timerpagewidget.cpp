#include "timerpagewidget.h"
#include "ui_timerpagewidget.h"
#include <QTime>
#include <QTimer>
#include <iostream>
#include <stdio.h>
#include <QTabWidget>

using namespace std;

TimerPageWidget::TimerPageWidget(QTabWidget *parent, int idx) :
    QWidget(dynamic_cast<QWidget*>(parent)),
    ui(new Ui::TimerPageWidget),
    idx(idx)
{
    ui->setupUi(this);

    startButton = ui->startButton;
    stopButton = ui->stopButton;
    timeDisplay = ui->timeDisplay;
    timeDisplay->display("00:00:00");
    hourSpinBox = ui->hourSpinBox;
    minSpinBox = ui->minSpinBox;
    secSpinBox = ui->secSpinBox;

    connect(startButton, &QPushButton::clicked, this, &TimerPageWidget::startButtonClicked);
    connect(stopButton, &QPushButton::clicked, this, &TimerPageWidget::stopTimer);

    startTime = new QTime();
    myTimer = new QTimer(this);
    connect(myTimer, &QTimer::timeout, this, &TimerPageWidget::onTick);

    connect(parent, &QTabWidget::currentChanged, this, &TimerPageWidget::stopTimer);
}

TimerPageWidget::~TimerPageWidget()
{
    delete ui;
    delete startTime;
    delete myTimer;
}

void TimerPageWidget::startButtonClicked()
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
void TimerPageWidget::stopTimer()
{
    if (!startTime->isNull()) {
        cout << "Stopping!!!" << endl;
        timeDisplay->display("00:00:00");
        myTimer->stop();
        *startTime = QTime();
    }
}

void TimerPageWidget::onTick()
{
    int secsElapsed = startTime->elapsed() / 1000;
    int secsRemaining = totalSecs - secsElapsed;
    if (secsRemaining <= 0) {
        cout << "Timer Complete!!!" << endl;
        stopTimer();
    } else {
        int secs = secsRemaining % 60;
        int mins = (secsRemaining / 60) % 60;
        int hrs = secsRemaining / 3600;
        std::cout << "On tick!! hrs: " << hrs << std::endl;
        QString timeString = QString("%1:%2:%3")
                        .arg(hrs, 2, 10, QLatin1Char('0'))
                        .arg(mins,2, 10 ,QLatin1Char('0'))
                        .arg(secs,2, 10 ,QLatin1Char('0'));
        timeDisplay->display(timeString);
        cout << "timeString: " << timeString.toStdString() << endl;
    }
}

