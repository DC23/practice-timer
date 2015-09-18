/*
    Practice Timer - Used for timing of blocked practice sessions, with some support for randomisation.
    Copyright (C) 2015, Daniel Collins

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
