#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "time_delta.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    statusUpdateTimer(new QTimer(this)),
    uptimeLabel(new QLabel(this)),
    startTime(QDateTime::currentDateTime())
{
    ui->setupUi(this);

    // set up some connections that I couldn't edit via the designer
    connect(ui->cdOptionsTab, SIGNAL(countdownOptionsChanged(CountdownOptions)), ui->countdownTimerWidget, SLOT(applyOptions(CountdownOptions)));

    // force an initial countdownOptionsChanged signal, to refect our initial state
    // This is a hacky code smell
    ui->cdOptionsTab->propertyChanged();

    // set up the status bar
    ui->statusBar->addPermanentWidget(uptimeLabel);
    updateStatus();
    statusUpdateTimer->setInterval(30000);
    connect(statusUpdateTimer, SIGNAL(timeout()), this, SLOT(updateStatus()));
    statusUpdateTimer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete statusUpdateTimer;
    delete uptimeLabel;
}

void MainWindow::updateStatus()
{
    TimeDelta duptime = QDateTime::currentDateTime() - startTime;
    QTime uptime = QTime(0,0,0).addMSecs(duptime.InMilliseconds());
    uptimeLabel->setText(QString("Total time: %1").arg(uptime.toString("hh:mm")));
}
