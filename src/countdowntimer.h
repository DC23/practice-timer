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

#ifndef COUNTDOWNTIMER_H
#define COUNTDOWNTIMER_H

#include <QWidget>
#include <QTime>
#include <QTimer>
#include <QSound>
#include "countdownoptions.h"

namespace Ui {
class CountdownTimer;
}

class CountdownTimer : public QWidget
{
    Q_OBJECT

public:
    explicit CountdownTimer(QWidget *parent = 0);
    ~CountdownTimer();

    bool isRunning() const;

public slots:
    void applyOptions(const CountdownOptions& options);
    void startStop();
    void start();
    void stop();
    void reset();
    void set();
    void set(const QTime& time);
    void presetOne();
    void presetTwo();
    void presetThree();
    void presetFour();
    void presetFive();
    void presetSix();
    void presetSeven();
    void presetEight();
    void addMinute();
    void subMinute();
    void addSecond();
    void subSecond();

private slots:
    void update();
    void timesUp();

private:
    void toggleTimerState();
    void updateButtonStates();

    Ui::CountdownTimer *ui;
    QTimer* updateTick;
    QTimer* countdown;
    QSound* timesUpChime;
    CountdownOptions options;
    int cachedFullDuration;
};

#endif // COUNTDOWNTIMER_H
