#ifndef HOVERWATCH_H
#define HOVERWATCH_H

#include <QLabel>
#include <QUuid>
#include <vector>
#include "window_ops.h"

enum HoverAction {
    Minimize, ToggleMaximize, Close, Nvm, Config, Exec
};

//describes a hoverwatch.
struct HoverWatchState {
    QString title; //this tag can be randomly generated.
    HoverAction action;
    QString metadata;
};

class HoverWatch : public QLabel
{
    Q_OBJECT

    HoverWatchState state;
public:
    explicit HoverWatch(HoverWatchState newState, QWidget *parent = 0);
    void enterEvent(QEvent *event);
    const QUuid tag;
signals:
    void hoverActivated(QUuid control);

public slots:
    void showHover(bool yesp);
    void reactToHover(QUuid control);
    void reactToExit(QUuid control, OpaqueWin win);

};

//connects slots in hoverActivateds to reactToHovers - all of them.
void setupCoReaction(std::vector<HoverWatch*> &vec);

#endif // HOVERWATCH_H
