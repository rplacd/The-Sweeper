#include "palettesettings.h"

const int numKeyRoots = 8;
const QString keyRoots[numKeyRoots] = { QString("tl"), QString("tc"), QString("tr"),
                              QString("cl"),                QString("cr"),
                              QString("bl"), QString("bc"), QString("br") };


//we're pissing memory here. don't worry, we're all using value semantics anyway
PaletteSettings::PaletteSettings(QSettings &settings)
{
    cells = QMap<QString, HoverWatchState>();
    bool incompletep = false;

    for(int i = 0; i < numKeyRoots; ++i) {
        HoverWatchState ret;

        QVariant val;
        //urgh. unfortunately templates can't dispatch on qvariant unboxing.
        QString mdKey = keyRoots[i] + "/title";
        if(val = settings.value(mdKey), val.type() != QVariant::Invalid)
            ret.title = val.toString();
        else
            incompletep = true;

        mdKey = keyRoots[i] + "/metadata";
        if(val = settings.value(mdKey), val.type() != QVariant::Invalid)
            ret.metadata = val.toString();
        else
            incompletep = true;

        mdKey = keyRoots[i] + "/action";
        if(val = settings.value(mdKey), val.type() != QVariant::Invalid)
            ret.metadata = val.toInt();
        else
            incompletep = true;

        cells[keyRoots[i]] = ret;
    }

    //setup a default layout if persistence seems incomplete.
    if(incompletep) {
        HoverWatchState minimize;
        minimize.title = QString("Minimize");
        minimize.action = Minimize;
        minimize.metadata = QString();
        cells[QString("bc")] = minimize;

        HoverWatchState maximize;
        maximize.title = QString("Maximize");
        maximize.action = ToggleMaximize;
        maximize.metadata = QString();
        cells[QString("tc")] = maximize;

        HoverWatchState close;
        close.title = QString("Close");
        close.action = Close;
        close.metadata = QString();
        cells[QString("cl")] = close;

        HoverWatchState config;
        config.title = QString("Config");
        config.action = Config;
        config.metadata = QString();
        cells[QString("br")] = config;
    }
}

void PaletteSettings::commitSettings(QSettings &settings)
{
    for(int i = 0; i < numKeyRoots; ++i) {
        HoverWatchState that = cells[keyRoots[i]];
        settings.value(keyRoots[i] + "/title", QVariant(that.title));
        settings.value(keyRoots[i] + "/metadata", QVariant(that.metadata));
        settings.value(keyRoots[i] + "/action", QVariant(that.action));
    }
    settings.sync();
}
