#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include <QApplication>
#include "celllocation_util.h"

SettingsDialog::SettingsDialog(PaletteSettings *newSettings, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    settings = newSettings;
    ui->setupUi(this);

    for(QMap<QString, HoverWatchState>::const_iterator it = newSettings->cells.constBegin();
        it != newSettings->cells.constEnd();
        ++it) {
        SettingsGroup *grp = new SettingsGroup(const_cast<HoverWatchState&>(it.value())); //who wants to piss away some memory!!!
        cells.insert(it.key(), grp);

        int x = 0; int y = 0;
        mapLocStr(it.key(), &x, &y);
        ui->grid->addWidget(grp, x, y);
    }
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void closingBplate(SettingsDialog *self)
{
    qApp->quit();
}

void SettingsDialog::accept()
{
    for(QMap<QString, SettingsGroup*>::const_iterator it = cells.constBegin();
        it != cells.constEnd();
        ++it) {
        settings->cells.insert(it.key(), it.value()->toHoverWatchState());
    }
    settings->commitSettings();
    closingBplate(this);
}

void SettingsDialog::reject()
{
    closingBplate(this);
}
