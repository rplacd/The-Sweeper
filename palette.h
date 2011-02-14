#ifndef PALETTE_H
#define PALETTE_H

#include <QMainWindow>

namespace Ui {
    class Palette;
}

class Palette : public QMainWindow
{
    Q_OBJECT

public:
    explicit Palette(QWidget *parent = 0);
    ~Palette();

private:
    Ui::Palette *ui;
};

#endif // PALETTE_H
