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
    connect(ui->Close2, SIGNAL(hoverActivated(QString)), this, SLOT(setState(QString)));
}

void Palette::setState(QString str)
{
    state = str;
}

Palette::~Palette()
{
    delete ui;
}
