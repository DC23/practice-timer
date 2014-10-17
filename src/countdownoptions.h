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

private:
    QTime presetOne;
    QTime presetTwo;
    QTime presetThree;
    QTime presetFour;
};

#endif // COUNTDOWNOPTIONS_H
