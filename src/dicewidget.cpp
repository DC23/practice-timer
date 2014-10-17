#include <QTime>
#include "dicewidget.h"
#include "ui_dicewidget.h"

DiceWidget::DiceWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DiceWidget),
    min(1),
    max(12)
{
    qsrand(QTime::currentTime().msec());
    ui->setupUi(this);
    ui->min->setValue(min);
    ui->max->setValue(max);
    ui->min->setMaximum(max - 1);
    ui->max->setMinimum(min + 1);
    rollDice();
}

DiceWidget::~DiceWidget()
{
    delete ui;
}

void DiceWidget::rollDice()
{
    ui->result->setText(QString::number((qrand() % (max + 1 - min)) + min));
}

void DiceWidget::setMinBound(int min)
{
    this->min = min;
    ui->max->setMinimum(min + 1);
}

void DiceWidget::setMaxBound(int max)
{
    this->max = max;
    ui->min->setMaximum(max - 1);
}
