#include "settimechooser.h"
#include "ui_settimechooser.h"

SetTimeChooser::SetTimeChooser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetTimeChooser)
{
    ui->setupUi(this);
}

SetTimeChooser::~SetTimeChooser()
{
    delete ui;
}

QTime SetTimeChooser::getTime() const
{
    return QTime(ui->spinHours->value(), ui->spinMinutes->value(), ui->spinSeconds->value());
}

void SetTimeChooser::setTime(QTime time)
{
    ui->spinHours->setValue(time.hour());
    ui->spinMinutes->setValue(time.minute());
    ui->spinSeconds->setValue(time.second());
}
