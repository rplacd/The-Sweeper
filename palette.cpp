#include "palette.h"
#include "ui_palette.h"

Palette::Palette(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Palette)
{
    ui->setupUi(this);
    state = QString("None");
    connect(ui->Maximize, SIGNAL(hoverActivated(QString)), this, SLOT(setState(QString)));
    connect(ui->Minimize, SIGNAL(hoverActivated(QString)), this, SLOT(setState(QString)));
    connect(ui->Close1, SIGNAL(hoverActivated(QString)), this, SLOT(setState(QString)));
    connect(ui->NVM, SIGNAL(hoverActivated(QString)), this, SLOT(setState(QString)));

    win = getWindowUnderCursor();
    int newX = getCursorX() - (width()/2);
    int newY = getCursorY() - (height()/2);
    move(newX, newY);
}

//shouldHighlightWidget.
inline void t_shWidget(HoverWatch *widget, QString str)
{
    if(str == widget->getHoverName()) {
        widget->showHover(true);
    } else {
        widget->showHover(false);
    }
}

void Palette::setState(QString str)
{
    state = str;
    t_shWidget(ui->Maximize, str);
    t_shWidget(ui->Minimize, str);
    t_shWidget(ui->Close1, str);
    t_shWidget(ui->NVM, str);
}

void Palette::leaveEvent(QEvent *)
{
    if(state == "Maximize") {
        windowToggleMaximize(win);
    } else if(state == "Minimize") {
        windowMinimize(win);
    } else if(state == "Close") {
        windowClose(win);
    } else if(state == "NVM") {
       //noop
    }
    close();
}

Palette::~Palette()
{
    delete ui;
}
