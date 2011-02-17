#ifndef PALETTESETTINGS_H
#define PALETTESETTINGS_H

#include <QMap>
#include <QSettings>
#include "hoverwatch.h"

class PaletteSettings {
public:
    QMap<QString, HoverWatchState> cells;
    PaletteSettings(QSettings &settings);
    void commitSettings(QSettings &settings);
};

#endif // PALETTESETTINGS_H
