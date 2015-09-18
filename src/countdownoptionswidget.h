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
