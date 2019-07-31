#ifndef TIMER_H
#define TIMER_H

#include <QObject>



class Timer : public QObject
{
    Q_OBJECT
public:
    Timer();
    void setTimeInSeconds(int time);
    long getTimeInSeconds();
    int getSeconds();
    int getMinutes();
    int getHours();

public slots:
    void onTick();
private:
    long seconds;

};

#endif // TIMER_H
