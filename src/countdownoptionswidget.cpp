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

#include "countdownoptionswidget.h"
#include "ui_countdownoptionswidget.h"

CountdownOptionsWidget::CountdownOptionsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CountdownOptionsWidget),
    options()
{
    ui->setupUi(this);

}

CountdownOptionsWidget::~CountdownOptionsWidget()
{
    delete ui;
}

void CountdownOptionsWidget::propertyChanged()
{
    options.setTimesUpMessage(ui->cbShowMessageBox->isChecked());
    options.setTimesUpChime(ui->cbPlayChime->isChecked());
    options.setLoop(ui->cbLoop->isChecked());

    emit countdownOptionsChanged(options);
}
