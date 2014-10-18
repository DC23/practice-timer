#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // set up some connections that I couldn't edit via the designer
    connect(ui->cdOptionsTab, SIGNAL(countdownOptionsChanged(CountdownOptions)), ui->countdownTimerWidget, SLOT(applyOptions(CountdownOptions)));


    // force an initial countdownOptionsChanged signal, to refect our initial state
    // This is a hacky code smell
    ui->cdOptionsTab->propertyChanged();
}

MainWindow::~MainWindow()
{
    delete ui;
}
