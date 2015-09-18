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

#include <QTime>
#include "dicewidget.h"
#include "ui_dicewidget.h"

DiceWidget::DiceWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DiceWidget),
    min(1),
    max(12)
{
    qsrand(QTime::currentTime().msec());
    ui->setupUi(this);
    ui->min->setValue(min);
    ui->max->setValue(max);
    ui->min->setMaximum(max - 1);
    ui->max->setMinimum(min + 1);
    rollDice();
}

DiceWidget::~DiceWidget()
{
    delete ui;
}

void DiceWidget::rollDice()
{
    ui->result->setText(QString::number((qrand() % (max + 1 - min)) + min));
}

void DiceWidget::setMinBound(int min)
{
    this->min = min;
    ui->max->setMinimum(min + 1);
}

void DiceWidget::setMaxBound(int max)
{
    this->max = max;
    ui->min->setMaximum(max - 1);
}
