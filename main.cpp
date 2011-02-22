#include <QtGui/QApplication>
#include "palette.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Palette w;
    w.show();

    return a.exec();
}
