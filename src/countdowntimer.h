#ifndef COUNTDOWNTIMER_H
#define COUNTDOWNTIMER_H

#include <QWidget>
#include <QTime>
#include <QTimer>
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
    void set(const QTime& time);

private slots:
    void update();

private:
    void toggleTimerState();

    Ui::CountdownTimer *ui;
    QTimer* updateTick;
    CountdownOptions options;
};

#endif // COUNTDOWNTIMER_H
