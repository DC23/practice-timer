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

private:
    Ui::DiceWidget *ui;
};

#endif // DICEWIDGET_H
