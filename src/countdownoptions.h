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
