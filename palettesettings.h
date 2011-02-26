#ifndef PALETTESETTINGS_H
#define PALETTESETTINGS_H

#include <QMap>
#include <QSettings>

enum HoverAction {
    Minimize, ToggleMaximize, Close, Nvm, Config, Exec
};

//describes a hoverwatch.
struct HoverWatchState {
    QString title;
    HoverAction action;
    QString metadata;
};


class PaletteSettings {
public:
    QMap<QString, HoverWatchState> cells;
    PaletteSettings(QSettings &settings);
    void commitSettings(QSettings &settings);
};

#endif // PALETTESETTINGS_H
