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

#ifndef COUNTDOWNOPTIONS_H
#define COUNTDOWNOPTIONS_H
#include <QTime>

class CountdownOptions
{
public:
    CountdownOptions();

    inline QTime getPresetOne() const { return presetOne; }
    inline QTime getPresetTwo() const { return presetTwo; }
    inline QTime getPresetThree() const { return presetThree; }
    inline QTime getPresetFour() const { return presetFour; }

    inline bool getTimesUpChime() const { return playChime; }
    inline bool getTimesUpMessage() const { return showMessageBox; }
    inline bool getLoop() const { return loop; }

    inline void setTimesUpMessage(bool value) { showMessageBox = value; }
    inline void setTimesUpChime(bool value) { playChime = value; }
    inline void setLoop(bool value) { loop = value; }

private:
    QTime presetOne;
    QTime presetTwo;
    QTime presetThree;
    QTime presetFour;
    bool playChime;
    bool showMessageBox;
    bool loop;
};

#endif // COUNTDOWNOPTIONS_H
