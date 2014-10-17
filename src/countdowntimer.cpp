#include "countdowntimer.h"
#include "ui_countdowntimer.h"

CountdownTimer::CountdownTimer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CountdownTimer),
    updateTick(new QTimer(this)),
    countdown(new QTimer(this)),
    cachedFullDuration(60000)
{
    ui->setupUi(this);

    // connect up the timer that we use for updating the display
    connect(updateTick, SIGNAL(timeout()), this, SLOT(update()));
    updateTick->setSingleShot(false);

    countdown->setSingleShot(true);

    // load the initial options
    CountdownOptions options;
    applyOptions(options);

    stop();
    presetOne();
}

CountdownTimer::~CountdownTimer()
{
    delete ui;
    delete updateTick;
    delete countdown;
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
        countdown->start(); // start from the current interval
        ui->startStop->setText("&Pause");
        updateTick->start(200);
        updateButtonStates();
    }
}

void CountdownTimer::stop()
{
    if (isRunning())
    {
        updateTick->stop();
        int remainingTime = countdown->remainingTime();
        countdown->stop();
        countdown->setInterval(remainingTime);
        ui->startStop->setText("&Start");
        updateButtonStates();
    }
}

void CountdownTimer::reset()
{
    if (isRunning())
        stop();

    countdown->setInterval(cachedFullDuration);
    update(); // force a UI update
}

void CountdownTimer::set()
{
    // launch dialog
    // get result
    // setTime
}

void CountdownTimer::set(const QTime &time)
{
    if (!isRunning())
    {
        cachedFullDuration = time.msecsSinceStartOfDay();
        countdown->setInterval(cachedFullDuration);
        update(); // force a UI update
    }
}

void CountdownTimer::presetOne()
{
    if (!isRunning())
        set(options.getPresetOne());
}

void CountdownTimer::presetTwo()
{
    if (!isRunning())
        set(options.getPresetTwo());
}

void CountdownTimer::presetThree()
{
    if (!isRunning())
        set(options.getPresetThree());
}

void CountdownTimer::presetFour()
{
    if (!isRunning())
        set(options.getPresetFour());
}

void CountdownTimer::update()
{
    QTime zero(0,0,0,0);
    QTime current;
    int remaining = isRunning() ? countdown->remainingTime() : cachedFullDuration;
    current = zero.addMSecs(remaining);
    ui->timeLabel->setText(current.toString("hh:mm:ss"));
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
