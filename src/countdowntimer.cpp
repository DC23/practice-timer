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
        updateButtonStates();
    }
}

void CountdownTimer::stop()
{
    if (isRunning())
    {
        //stopwatch.Stop();
        ui->startStop->setText("&Start");
        updateTick->stop();
        updateButtonStates();
    }
}

void CountdownTimer::reset()
{
    if (isRunning())
        stop();

    // reset stopwatch
    update(); // force a UI update
}

void CountdownTimer::set()
{
    // stopwatch->setTime();
}

void CountdownTimer::setTime(const QTime &time)
{

}

void CountdownTimer::presetOne()
{
    if (!isRunning())
        setTime(options.getPresetOne());
}

void CountdownTimer::presetTwo()
{
    if (!isRunning())
        setTime(options.getPresetTwo());
}

void CountdownTimer::presetThree()
{
    if (!isRunning())
        setTime(options.getPresetThree());
}

void CountdownTimer::presetFour()
{
    if (!isRunning())
        setTime(options.getPresetFour());
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

void CountdownTimer::updateButtonStates()
{
    bool enable = !isRunning();
    ui->preset1->setEnabled(enable);
    ui->preset2->setEnabled(enable);
    ui->preset3->setEnabled(enable);
    ui->preset4->setEnabled(enable);
    ui->btnSet->setEnabled(enable);
}
