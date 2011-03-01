#include "settingsgroup.h"
#include <QVBoxLayout>
#include <QString>

SettingsGroup::SettingsGroup(HoverWatchState &newState, QWidget *parent) :
    QGroupBox(parent), state(newState)
{
    QVBoxLayout *lay = new QVBoxLayout;
    this->setLayout(lay);

    titleField = new QLineEdit(state.title);
    connect(titleField, SIGNAL(textChanged(const QString&)), this, SLOT(titleChanged(QString&)));
    lay->addWidget(titleField);

    actionField = new QComboBox();
    //oh, dear, keeping the strings here isn't very good form...
    for(QMap<HoverAction, QString>::const_iterator it = ActionDescriptions()->constBegin();
        it != ActionDescriptions()->constEnd();
        ++it) {
        actionField->insertItem(it.key(), it.value(), QVariant(it.key()));
    }
    actionField->setCurrentIndex(state.action);
    connect(actionField, SIGNAL(currentIndexChanged(int)), this, SLOT(actionChanged(int)));
    lay->addWidget(actionField);

    metadataField = new QLineEdit;
    if(newState.action == Exec) {
        metadataField->setEnabled(true);
        metadataField->setText(newState.metadata);
    } else {
        metadataField->setEnabled(false);
        metadataField->setText("Command string");
    }
    connect(metadataField, SIGNAL(textChanged(const QString&)), this, SLOT(metadataChanged(QString&)));
    lay->addWidget(metadataField);
}

HoverWatchState &SettingsGroup::toHoverWatchState()
{
    return state;
}

void SettingsGroup::titleChanged(QString &text)
{
   state.title = text;
}

void SettingsGroup::actionChanged(int val)
{
    state.action = (HoverAction)val;
    if(state.action == Exec) {
        metadataField->setEnabled(true);
        metadataField->setText(state.metadata);
    } else {
        metadataField->setEnabled(false);
        metadataField->setText("Command string");
    }
}

void SettingsGroup::metadataChanged(QString &text)
{
    state.metadata = text;
}
