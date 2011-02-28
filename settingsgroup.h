#ifndef SETTINGSGROUP_H
#define SETTINGSGROUP_H

#include <QGroupBox>
#include "palettesettings.h"

class SettingsGroup : public QGroupBox
{
    Q_OBJECT
    HoverWatchState &state;
public:
    explicit SettingsGroup(HoverWatchState &newState, QWidget *parent = 0);

signals:

public slots:

};

#endif // SETTINGSGROUP_H
