#ifndef COUNTDOWNOPTIONSWIDGET_H
#define COUNTDOWNOPTIONSWIDGET_H

#include <QWidget>
#include "countdownoptions.h"


namespace Ui {
class CountdownOptionsWidget;
}

class CountdownOptionsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CountdownOptionsWidget(QWidget *parent = 0);
    ~CountdownOptionsWidget();

public slots:
    void propertyChanged();

signals:
    void countdownOptionsChanged(const CountdownOptions& options);

private:
    Ui::CountdownOptionsWidget *ui;
    CountdownOptions options;
};

#endif // COUNTDOWNOPTIONSWIDGET_H
