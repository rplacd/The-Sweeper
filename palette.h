#ifndef PALETTE_H
#define PALETTE_H

#include <QMainWindow>
#include "window_ops.h"

namespace Ui {
    class Palette;
}

class Palette : public QMainWindow
{
    Q_OBJECT
    QString state;
    OpaqueWin win;

public:
    explicit Palette(QWidget *parent = 0);
    ~Palette();
    void leaveEvent(QEvent *);
public slots:
    void setState(QString str);
private:
    Ui::Palette *ui;
};

#endif // PALETTE_H
