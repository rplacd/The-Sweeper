#ifndef PALETTE_H
#define PALETTE_H

#include <QMainWindow>
#include <QUuid>
#include <QSettings>
#include <QVector>
#include "window_ops.h"
#include "palettesettings.h"
#include "hoverwatch.h"

namespace Ui {
    class Palette;
}

class Palette : public QMainWindow
{
private:
    Q_OBJECT
    Ui::Palette *ui;
    QUuid state;
    OpaqueWin win;
    QSettings settings;
    PaletteSettings pSettings;
    QVector<HoverWatch *> cells;
public:
    explicit Palette(QWidget *parent = 0);
    ~Palette();
    void leaveEvent(QEvent *);
public slots:
    void setState(QUuid control);

};

#endif // PALETTE_H
