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
    updateTick->setSingleShot(false);

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
   return updateTick->isActive();
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
    if (!isRunning())
    {
        updateTick->start(200);
        //stopwatch.Start();
        ui->startStop->setText("&Pause");
    }
}

void CountdownTimer::stop()
{
    if (isRunning())
    {
        //stopwatch.Stop();
        ui->startStop->setText("&Start");
        updateTick->stop();
    }
}

void CountdownTimer::reset()
{
    // reset stopwatch
    update(); // force a UI update
}

void CountdownTimer::set(const QTime& time)
{
    // stopwatch->setTime(time);
}

void CountdownTimer::update()
{
    // check stopwatch for elapsed time
    // update UI
}

void CountdownTimer::toggleTimerState()
{
    if (isRunning())
        stop();
    else
        start();
}
