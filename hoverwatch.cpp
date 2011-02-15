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
