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
