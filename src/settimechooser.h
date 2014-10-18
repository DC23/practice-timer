#ifndef SETTIMECHOOSER_H
#define SETTIMECHOOSER_H

#include <QDialog>
#include <QTime>

namespace Ui {
class SetTimeChooser;
}

class SetTimeChooser : public QDialog
{
    Q_OBJECT

public:
    explicit SetTimeChooser(QWidget *parent = 0);
    ~SetTimeChooser();

    QTime getTime() const;
    void setTime(QTime time);

private:
    Ui::SetTimeChooser *ui;
};

#endif // SETTIMECHOOSER_H
