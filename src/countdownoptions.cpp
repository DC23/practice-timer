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

#include "countdownoptions.h"

CountdownOptions::CountdownOptions() :
    presetOne(0,1,20),
    presetTwo(0,2,0),
    presetThree(0,5,0),
    presetFour(0,10,0),
    presetFive(0,15,0),
    presetSix(0,20,0),
    presetSeven(0,25,0),
    presetEight(0,30,0),
    playChime(false),
    showMessageBox(false),
    loop(false)
{
}
