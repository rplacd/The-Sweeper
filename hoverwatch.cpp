#include "hoverwatch.h"

HoverWatch::HoverWatch(QWidget *parent) :
    QLabel(parent)
{
    hoverName = QString("default");
}

void HoverWatch::enterEvent(QEvent *event)
{
    emit hoverActivated(hoverName);
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

void HoverWatch::reactToHover(QString control)
{
    if(control == hoverName) {
        showHover(true);
    } else {
        showHover(false);
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
