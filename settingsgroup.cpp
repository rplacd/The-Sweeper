#include "settingsgroup.h"

SettingsGroup::SettingsGroup(HoverWatchState &newState, QWidget *parent) :
    QGroupBox(parent), state(newState)
{

}
