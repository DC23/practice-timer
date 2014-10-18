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
