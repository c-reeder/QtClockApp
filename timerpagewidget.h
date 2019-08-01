#ifndef TIMERPAGEWIDGET_H
#define TIMERPAGEWIDGET_H

#include <QWidget>
#include "timer.h"
#include <QPushButton>
#include <QLCDNumber>
#include <QSpinBox>
#include <QTabWidget>

namespace Ui {
class TimerPageWidget;
}

class TimerPageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TimerPageWidget(QTabWidget *parent = nullptr, int idx = 0);
    ~TimerPageWidget();

public slots:
    void startButtonClicked();
    void stopTimer();
    void onTick();

private:
    Ui::TimerPageWidget *ui;
    Timer timer;
    QPushButton *startButton;
    QPushButton *stopButton;
    QLCDNumber *timeDisplay;
    QSpinBox *hourSpinBox;
    QSpinBox *minSpinBox;
    QSpinBox *secSpinBox;
    QTime *startTime;
    QTimer *myTimer;
    int totalSecs;
    int idx;
};

#endif // TIMERPAGEWIDGET_H
