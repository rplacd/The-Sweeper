#include "palette.h"
#include "ui_palette.h"

void mapLocStr(const QString &loc, int *x, int *y)
{
    if(loc == "tl")
        *y = 0, *x = 0;
    else if(loc == "tc")
        *y = 1, *x = 0;
    else if(loc == "tr")
        *y = 2, *x = 0;
    else if(loc == "cl")
        *y = 0, *x = 1;
    else if(loc == "cr")
        *y = 2, *x = 1;
    else if(loc == "bl")
        *y = 0, *x = 2;
    else if(loc == "bc")
        *y = 1, *x = 2;
    else if(loc == "br")
        *y = 2, *x = 2;
    else
        *y = 0, *x = 0;
    return;
}

Palette::Palette(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Palette),
    settings("./sweeper.ini", QSettings::IniFormat),
    pSettings(PaletteSettings(settings))
{
    pSettings.commitSettings(settings);

    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

    win = getWindowUnderCursor();
    int newX = getCursorX() - (width()/2);
    int newY = getCursorY() - (height()/2);
    move(newX, newY);

    state = QUuid();

    QMap<QString, HoverWatchState> &bob = pSettings.cells;
    for(QMap<QString, HoverWatchState>::const_iterator i = bob.constBegin();
        i != bob.constEnd();
        ++i) {
        HoverWatch *hv = new HoverWatch(i.value());
        cells.push_front(hv);
        int x, y; mapLocStr(i.key(), &x, &y);
        ui->grid->addWidget(hv, x, y);
    }
    //and now let all the hoverwatches connect to each other and us...
    for(QVector<HoverWatch*>::iterator it = cells.begin(); it != cells.end(); ++it) {
        for(QVector<HoverWatch*>::iterator jt = cells.begin(); jt != cells.end(); ++jt) {
            connect(*it, SIGNAL(hoverActivated(QUuid)), *jt, SLOT(reactToHover(QUuid)));
            connect(*it, SIGNAL(hoverActivated(QUuid)), this, SLOT(setState(QUuid)));
        }
    }
}

void Palette::setState(QUuid control)
{
    state = control;
}

void Palette::leaveEvent(QEvent *)
{
    for(QVector<HoverWatch*>::iterator it = cells.begin(); it != cells.end(); ++it) {
        (*it)->setEnabled(false);
        (*it)->reactToExit(state, win, &pSettings);
    }
}

Palette::~Palette()
{
    //we don't delete the hoverwatches here. not yet, at least, although the difference is minimal - we don't "regenerate".
    delete ui;
}
