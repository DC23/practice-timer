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

#include "time_delta.h"

#include <QDateTime>

namespace {

const qint64 kMillisecondsPerSecond = 1000;
const qint64 kMicrosecondsPerMillisecond = 1000;
const qint64 kMicrosecondsPerSecond = kMicrosecondsPerMillisecond *
                                            kMillisecondsPerSecond;
const qint64 kMicrosecondsPerMinute = kMicrosecondsPerSecond * 60;
const qint64 kMicrosecondsPerHour = kMicrosecondsPerMinute * 60;
const qint64 kMicrosecondsPerDay = kMicrosecondsPerHour * 24;
const qint64 kMicrosecondsPerWeek = kMicrosecondsPerDay * 7;
const qint64 kNanosecondsPerMicrosecond = 1000;
const qint64 kNanosecondsPerSecond = kNanosecondsPerMicrosecond *
                                           kMicrosecondsPerSecond;
}  // namespace

TimeDelta::TimeDelta()
  : delta_(0)
{}

TimeDelta::TimeDelta(const TimeDelta& other)
  : delta_(other.delta_)
{}

TimeDelta TimeDelta::FromDays(qint64 days)
{
  return TimeDelta(days * kMicrosecondsPerDay);
}

TimeDelta TimeDelta::FromHours(qint64 hours)
{
  return TimeDelta(hours * kMicrosecondsPerHour);
}

TimeDelta TimeDelta::FromMinutes(qint64 minutes)
{
  return TimeDelta(minutes * kMicrosecondsPerMinute);
}

TimeDelta TimeDelta::FromSeconds(qint64 secs)
{
  return TimeDelta(secs * kMicrosecondsPerSecond);
}

TimeDelta TimeDelta::FromMilliseconds(qint64 ms)
{
  return TimeDelta(ms * kMicrosecondsPerMillisecond);
}

TimeDelta TimeDelta::FromMicroseconds(qint64 us)
{
  return TimeDelta(us);
}

int TimeDelta::InDays() const {
  return static_cast<int>(delta_ / kMicrosecondsPerDay);
}

int TimeDelta::InHours() const {
  return static_cast<int>(delta_ / kMicrosecondsPerHour);
}

int TimeDelta::InMinutes() const {
  return static_cast<int>(delta_ / kMicrosecondsPerMinute);
}

double TimeDelta::InSecondsF() const {
  return static_cast<double>(delta_) / kMicrosecondsPerSecond;
}

qint64 TimeDelta::InSeconds() const {
  return delta_ / kMicrosecondsPerSecond;
}

double TimeDelta::InMillisecondsF() const {
  return static_cast<double>(delta_) / kMicrosecondsPerMillisecond;
}

qint64 TimeDelta::InMilliseconds() const {
  return delta_ / kMicrosecondsPerMillisecond;
}

qint64 TimeDelta::InMillisecondsRoundedUp() const {
  return (delta_ + kMicrosecondsPerMillisecond - 1) /
      kMicrosecondsPerMillisecond;
}

qint64 TimeDelta::InMicroseconds() const {
  return delta_;
}

TimeDelta TimeDelta::FromInternalValue(qint64 delta) {
  return TimeDelta(delta);
}

qint64 TimeDelta::ToInternalValue() const {
  return delta_;
}

TimeDelta& TimeDelta::operator = (const TimeDelta &other) {
  delta_ = other.delta_;
  return *this;
}

TimeDelta TimeDelta::operator + (const TimeDelta &other) const {
  return TimeDelta(delta_ + other.delta_);
}

bool TimeDelta::operator == (const TimeDelta &other) const {
  return delta_ == other.delta_;
}

bool TimeDelta::operator != (const TimeDelta& other) const {
  return delta_ != other.delta_;
}

bool TimeDelta::operator < (const TimeDelta& other) const {
  return delta_ < other.delta_;
}

bool TimeDelta::operator <= (const TimeDelta& other) const {
  return delta_ <= other.delta_;
}

bool TimeDelta::operator > (const TimeDelta& other) const {
  return delta_ > other.delta_;
}

bool TimeDelta::operator >= (const TimeDelta& other) const {
  return delta_ >= other.delta_;
}

TimeDelta& TimeDelta::operator += (const TimeDelta& other) {
  delta_ += other.delta_;
  return *this;
}

TimeDelta &TimeDelta::operator -=(const TimeDelta& other) {
  delta_ -= other.delta_;
  return *this;
}

TimeDelta TimeDelta::operator - () const {
  return TimeDelta(-delta_);
}

TimeDelta TimeDelta::operator * (qint64 a) const {
  return TimeDelta(delta_ * a);
}

TimeDelta& TimeDelta::operator *= (qint64 a) {
  delta_ *= a;
  return *this;
}

TimeDelta& TimeDelta::operator /= (qint64 a) {
  delta_ /= a;
  return *this;
}

qint64 TimeDelta::operator / (const TimeDelta& a) const {
  return delta_ / a.delta_;
}

TimeDelta TimeDelta::operator / (qint64 a) const {
  return TimeDelta(delta_ / a);
}

TimeDelta TimeDelta::operator - (const TimeDelta& other) const {
  return TimeDelta(delta_ - other.delta_);
}

TimeDelta::TimeDelta(qint64 delta_us)
  : delta_(delta_us)
{}

TimeDelta operator * (qint64 a, TimeDelta delta)
{
  return delta * a;
}

QDateTime operator + (const QDateTime& dt, const TimeDelta &delta)
{
  return dt.addMSecs(delta.InMilliseconds());
}

QDateTime operator + (const QDate& d, const TimeDelta &delta)
{
  return QDateTime(d) + delta;
}

QDateTime operator + (const TimeDelta& delta, const QDateTime& dt)
{
  return dt.addMSecs(delta.InMilliseconds());
}

QDateTime operator + (const TimeDelta& delta, const QDate& d)
{
  return QDateTime(d) + delta;
}

QDateTime operator - (const QDateTime& dt, const TimeDelta& delta)
{
  return dt.addMSecs(-1 * delta.InMilliseconds());
}

QDateTime operator - (const QDate& d, const TimeDelta& delta)
{
  return QDateTime(d) - delta;
}

QDateTime& operator += (QDateTime& dt, const TimeDelta& delta)
{
  return (dt = dt + delta);
}

QDateTime& operator -= (QDateTime& dt, const TimeDelta& delta)
{
  return (dt = dt - delta);
}

TimeDelta operator - (const QDateTime& dt_left, const QDateTime& dt_right)
{
  return TimeDelta::FromMilliseconds(dt_right.msecsTo(dt_left));
}

TimeDelta operator - (const QDateTime& dt_left, const QDate& d_right)
{
  return dt_left - QDateTime(d_right);
}

TimeDelta operator - (const QDate& d_left, const QDateTime& dt_right)
{
  return QDateTime(d_left) - dt_right;
}

TimeDelta operator - (const QDate& d_left, const QDate& d_right)
{
  return TimeDelta::FromDays(d_right.daysTo(d_left));
}

TimeDelta operator - (const QTime& t_left, const QTime& t_right)
{
  return TimeDelta::FromMilliseconds(t_right.msecsTo(t_left));
}
