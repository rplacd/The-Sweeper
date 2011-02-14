#ifndef PALETTE_H
#define PALETTE_H

#include <QMainWindow>

namespace Ui {
    class Palette;
}

class Palette : public QMainWindow
{
    Q_OBJECT
    QString state;
public:
    explicit Palette(QWidget *parent = 0);
    ~Palette();
public slots:
    void setState(QString str);
private:
    Ui::Palette *ui;
};

#endif // PALETTE_H
