#include "palette.h"
#include "ui_palette.h"

Palette::Palette(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Palette)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

    state = QString("None");
    connect(ui->Maximize, SIGNAL(hoverActivated(QString)), this, SLOT(setState(QString)));
    connect(ui->Minimize, SIGNAL(hoverActivated(QString)), this, SLOT(setState(QString)));
    connect(ui->Close1, SIGNAL(hoverActivated(QString)), this, SLOT(setState(QString)));
    connect(ui->NVM, SIGNAL(hoverActivated(QString)), this, SLOT(setState(QString)));

    HoverWatch* arr[] = { ui->Maximize, ui->Minimize, ui->Close1, ui->NVM };
    std::vector<HoverWatch*> arrp(arr, arr+4);
    setupCoReaction(arrp);

    win = getWindowUnderCursor();
    int newX = getCursorX() - (width()/2);
    int newY = getCursorY() - (height()/2);
    move(newX, newY);
}

void Palette::setState(QString str)
{
    state = str;
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
