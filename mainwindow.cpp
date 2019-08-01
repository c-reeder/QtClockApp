#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "timerpagewidget.h"


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tabWidget = ui->tabWidget;
    timerTabPage = new TimerPageWidget(tabWidget);
    clockTabPage = new QWidget(this);
    stopwatchTabPage = new QWidget(this);
    alarmTabPage = new QWidget(this);

    tabWidget->addTab(timerTabPage,"Timer");
    tabWidget->addTab(clockTabPage,"Clock");
    tabWidget->addTab(stopwatchTabPage,"Stopwatch");
    tabWidget->addTab(alarmTabPage,"Alarm");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timerTabPage;
    delete clockTabPage;
    delete stopwatchTabPage;
    delete alarmTabPage;
}

