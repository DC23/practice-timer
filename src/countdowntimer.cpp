/*
    Practice Timer - Used for timing of blocked practice sessions, with some support for randomisation.
    Copyright (C) 2015, Daniel Collins

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "countdowntimer.h"
#include "ui_countdowntimer.h"
#include "settimechooser.h"
#include <QMessageBox>

CountdownTimer::CountdownTimer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CountdownTimer),
    updateTick(new QTimer(this)),
    countdown(new QTimer(this)),
    timesUpChime(new QSound(":/audio/TimesUp.wav", this)),
    options(),
    cachedFullDuration(60000)
{
    ui->setupUi(this);

    connect(updateTick, SIGNAL(timeout()), this, SLOT(update()));
    updateTick->setSingleShot(false);

    connect(countdown, SIGNAL(timeout()), this, SLOT(timesUp()));
    countdown->setSingleShot(true);

    // load the initial options
    applyOptions(options);

    // set up the times up chime
    timesUpChime->setLoops(1);

    stop();
    presetOne();
}

CountdownTimer::~CountdownTimer()
{
    delete ui;
    delete updateTick;
    delete countdown;
    delete timesUpChime;
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
    ui->preset5->setText(options.getPresetFive().toString());
    ui->preset6->setText(options.getPresetSix().toString());
    ui->preset7->setText(options.getPresetSeven().toString());
    ui->preset8->setText(options.getPresetEight().toString());
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
    SetTimeChooser timeChooser;
    timeChooser.setTime(QTime(0,0,0).addMSecs(cachedFullDuration));
    if (timeChooser.exec() == QDialog::Accepted)
    {
        set(timeChooser.getTime());
    }
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

void CountdownTimer::presetFive()
{
    if (!isRunning())
        set(options.getPresetFive());
}

void CountdownTimer::presetSix()
{
    if (!isRunning())
        set(options.getPresetSix());
}

void CountdownTimer::presetSeven()
{
    if (!isRunning())
        set(options.getPresetSeven());
}

void CountdownTimer::presetEight()
{
    if (!isRunning())
        set(options.getPresetEight());
}

void CountdownTimer::update()
{
    QTime zero(0,0,0,0);
    QTime current;
    int remaining = isRunning() ? countdown->remainingTime() : cachedFullDuration;
    current = zero.addMSecs(remaining);
    ui->timeLabel->setText(current.toString("hh:mm:ss"));
}

void CountdownTimer::timesUp()
{
    reset();

    if (options.getTimesUpChime())
        timesUpChime->play();

    if (options.getTimesUpMessage())
    {
        QMessageBox mb;
        mb.setText("Time's Up");
        mb.setWindowTitle("Countdown Timer");
        mb.setStandardButtons(QMessageBox::Ok);
        mb.setDefaultButton(QMessageBox::Ok);
        mb.exec();
    }

    if (options.getLoop())
        startStop();
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
    ui->preset5->setEnabled(enable);
    ui->preset6->setEnabled(enable);
    ui->preset7->setEnabled(enable);
    ui->preset8->setEnabled(enable);
    ui->btnSet->setEnabled(enable);
}
