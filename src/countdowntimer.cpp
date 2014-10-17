#include "countdowntimer.h"
#include "ui_countdowntimer.h"

CountdownTimer::CountdownTimer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CountdownTimer)
{
    ui->setupUi(this);

    // load the initial options
    CountdownOptions options;
    applyOptions(options);
}

CountdownTimer::~CountdownTimer()
{
    delete ui;
}

void CountdownTimer::applyOptions(const CountdownOptions& options)
{
    this->options = options;
    ui->preset1->setText(options.getPresetOne().toString());
    ui->preset2->setText(options.getPresetTwo().toString());
    ui->preset3->setText(options.getPresetThree().toString());
    ui->preset4->setText(options.getPresetFour().toString());
}

void CountdownTimer::start()
{}

void CountdownTimer::stop()
{}

void CountdownTimer::reset()
{}

void CountdownTimer::set(const QTime& time)
{}
