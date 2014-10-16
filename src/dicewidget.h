#ifndef DICEWIDGET_H
#define DICEWIDGET_H

#include <QWidget>

namespace Ui {
class DiceWidget;
}

class DiceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DiceWidget(QWidget *parent = 0);
    ~DiceWidget();

public slots:
    void rollDice();
    void setMinBound(int min);
    void setMaxBound(int max);

private:
    Ui::DiceWidget *ui;
    int min;
    int max;
};

#endif // DICEWIDGET_H
