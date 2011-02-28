#-------------------------------------------------
#
# Project created by QtCreator 2011-02-14T16:26:22
#
#-------------------------------------------------

QT       += core gui
INCLUDEPATH += C:/MinGW/include
LIBS += -mwindows

TARGET = Sweeper
TEMPLATE = app


SOURCES += main.cpp\
    window_ops_win.cpp \
    palette.cpp \
    hoverwatch.cpp \
    palettesettings.cpp \
    atexit.cpp \
    settingsdialog.cpp \
    settingsgroup.cpp

HEADERS  += \
    window_ops.h \
    palette.h \
    hoverwatch.h \
    palettesettings.h \
    settingsdialog.h \
    celllocation_util.h \
    settingsgroup.h

FORMS    += \
    palette.ui \
    settingsdialog.ui

RESOURCES += \
    resources.qrc
