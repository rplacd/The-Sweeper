#include "hoverwatch.h"
#include "atexit.cpp"
#include "settingsdialog.h"
#include <QApplication>

HoverWatch::HoverWatch(HoverWatchState newState, QWidget *parent) :
    QLabel(parent), tag(QUuid::createUuid())
{
    setText(newState.title);
    state = newState;
}

void HoverWatch::enterEvent(QEvent *event)
{
    emit hoverActivated(tag);
}

void HoverWatch::showHover(bool yesp)
{
    QFont fontStatus = font();
    if(yesp) {
        fontStatus.setBold(true);
    } else {
        fontStatus.setBold(false);
    }
    setFont(fontStatus);
}

void HoverWatch::reactToHover(QUuid control)
{
    if(control == tag) {
        showHover(true);
    } else {
        showHover(false);
    }
}

void HoverWatch::reactToExit(QUuid control, OpaqueWin win, PaletteSettings *settings)
{
    if(control == tag)
        reactToExit(win, settings);
}

static HoverWatch *last = NULL;
void HoverWatch::reactToExit(OpaqueWin win, PaletteSettings *settings)
{
    if(this == last)
        return;
    else
        last = this;

    switch(state.action) {
    case Nvm:
        break;
    case Exec:
        setExitCmd(state.metadata);
        break;
    case Config: {
        SettingsDialog dlg(settings);
        dlg.exec();
    }
    case Minimize:
        windowMinimize(win);
        break;
    case ToggleMaximize:
        windowToggleMaximize(win);
        break;
    case Close:
        windowClose(win);
        break;
    }
}

void setupCoReaction(std::vector<HoverWatch*> &vec) {
    typedef std::vector<HoverWatch*>::iterator itr;
    for(itr sender = vec.begin(); sender < vec.end(); ++sender) {
        for(itr recv = vec.begin(); recv < vec.end(); ++recv) {
                QObject::connect(*sender, SIGNAL(hoverActivated(QString)), *recv, SLOT(reactToHover(QString)));
        }
    }
}
