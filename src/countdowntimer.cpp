#include "countdowntimer.h"
#include "ui_countdowntimer.h"

CountdownTimer::CountdownTimer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CountdownTimer),
    updateTick(new QTimer(this))
{
    ui->setupUi(this);

    // connect up the timer that we use for updating the display
    connect(updateTick, SIGNAL(timeout()), this, SLOT(update()));

    // load the initial options
    CountdownOptions options;
    applyOptions(options);

    stop();
}

CountdownTimer::~CountdownTimer()
{
    delete ui;
    delete updateTick;
}

bool CountdownTimer::isRunning() const
{
   return false;
}

void CountdownTimer::applyOptions(const CountdownOptions& options)
{
    this->options = options;
    ui->preset1->setText(options.getPresetOne().toString());
    ui->preset2->setText(options.getPresetTwo().toString());
    ui->preset3->setText(options.getPresetThree().toString());
    ui->preset4->setText(options.getPresetFour().toString());
}

void CountdownTimer::startStop()
{
    toggleTimerState();
}

void CountdownTimer::start()
{
    updateTick->start();
    //timer.Start();
    ui->startStop->setText("&Pause");
}

void CountdownTimer::stop()
{
    //timer.Stop();
    ui->startStop->setText("&Start");
    updateTick->stop();
}

void CountdownTimer::reset()
{}

void CountdownTimer::set(const QTime& time)
{}

void CountdownTimer::update()
{

}

void CountdownTimer::toggleTimerState()
{
    if (isRunning())
        stop();
    else
        start();
}
