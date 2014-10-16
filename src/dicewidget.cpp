#include "dicewidget.h"
#include "ui_dicewidget.h"

DiceWidget::DiceWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DiceWidget)
{
    ui->setupUi(this);
}

DiceWidget::~DiceWidget()
{
    delete ui;
}
