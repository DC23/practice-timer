#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QTimer>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void updateStatus();

private:
    Ui::MainWindow *ui;
    QTimer* statusUpdateTimer;
    QLabel* uptimeLabel;
    QDateTime startTime;
};

#endif // MAINWINDOW_H
