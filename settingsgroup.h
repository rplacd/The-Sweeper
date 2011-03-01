#ifndef SETTINGSGROUP_H
#define SETTINGSGROUP_H

#include <QGroupBox>
#include "palettesettings.h"
#include <QLineEdit>
#include <QComboBox>
#include <QString>

class SettingsGroup : public QGroupBox
{
    Q_OBJECT
    HoverWatchState &state;
    QLineEdit *titleField;
    QComboBox *actionField;
    QLineEdit *metadataField;
public:
    explicit SettingsGroup(HoverWatchState &newState, QWidget *parent = 0);
    HoverWatchState &toHoverWatchState();

signals:

public slots:
    void titleChanged(QString &text);
    void actionChanged(int val);
    void metadataChanged(QString &text);

};

#endif // SETTINGSGROUP_H
