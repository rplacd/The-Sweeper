#ifndef PALETTE_H
#define PALETTE_H

#include <QMainWindow>
#include <QUuid>
#include "window_ops.h"

namespace Ui {
    class Palette;
}

class Palette : public QMainWindow
{
    Q_OBJECT
    QUuid state;
    OpaqueWin win;

public:
    explicit Palette(QWidget *parent = 0);
    ~Palette();
    void leaveEvent(QEvent *);
public slots:
    void setState(QUuid control);
private:
    Ui::Palette *ui;
};

#endif // PALETTE_H
