#include "palette.h"
#include "ui_palette.h"

Palette::Palette(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Palette)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

    win = getWindowUnderCursor();
    int newX = getCursorX() - (width()/2);
    int newY = getCursorY() - (height()/2);
    move(newX, newY);

    state = QUuid();
}

void Palette::setState(QUuid control)
{
    state = control;
}

void Palette::leaveEvent(QEvent *)
{
    //exec what's been activated
}

Palette::~Palette()
{
    delete ui;
}
