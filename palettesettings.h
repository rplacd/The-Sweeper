#ifndef PALETTESETTINGS_H
#define PALETTESETTINGS_H

#include <QMap>
#include <QSettings>

enum HoverAction {
    Minimize, ToggleMaximize, Close, Nvm, Config, Exec
};

QMap<HoverAction, QString>*ActionDescriptions();

//describes a hoverwatch.
struct HoverWatchState {
    QString title;
    HoverAction action;
    QString metadata;

    HoverWatchState()
    {
        title = QString("");
        action = Nvm;
        metadata = QString("");
    }
};


class PaletteSettings {
private:
    QSettings &settings;
public:
    QMap<QString, HoverWatchState> cells;
    PaletteSettings(QSettings &_settings);
    void commitSettings();
};

#endif // PALETTESETTINGS_H
