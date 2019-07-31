#include "timer.h"
#include <QTime>

Timer::Timer() :
    QObject()
{
    seconds = 0;

}

void Timer::setTimeInSeconds(int time) {
    time = time + 1;
}
long Timer::getTimeInSeconds() {
    return seconds;
}
int Timer::getSeconds() {
    return 0;
}
int Timer::getMinutes() {
    return 0;
}
int Timer::getHours() {
    return 0;
}
void Timer::onTick()
{
    QTime currTime = QTime::currentTime();


}
