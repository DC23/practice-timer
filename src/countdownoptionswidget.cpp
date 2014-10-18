#include "countdownoptionswidget.h"
#include "ui_countdownoptionswidget.h"

CountdownOptionsWidget::CountdownOptionsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CountdownOptionsWidget),
    options()
{
    ui->setupUi(this);

}

CountdownOptionsWidget::~CountdownOptionsWidget()
{
    delete ui;
}

void CountdownOptionsWidget::propertyChanged()
{
    options.setTimesUpMessage(ui->cbShowMessageBox->isChecked());
    options.setTimesUpChime(ui->cbPlayChime->isChecked());
    options.setLoop(ui->cbLoop->isChecked());

    emit countdownOptionsChanged(options);
}
