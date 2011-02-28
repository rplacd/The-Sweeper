#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QMap>
#include "settingsgroup.h"
#include "palettesettings.h"

namespace Ui {
    class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT
    QMap<QString, SettingsGroup*> cells;
public:
    explicit SettingsDialog(PaletteSettings *newSettings, QWidget *parent = 0);
    ~SettingsDialog();

    void accept();
    void reject();
private:
    Ui::SettingsDialog *ui;
    PaletteSettings *settings;
};

#endif // SETTINGSDIALOG_H
