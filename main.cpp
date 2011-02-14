#include <QtGui/QApplication>
#include "palette.h"

//fuck your exceptions, but I can't build Qt from scratch either.
void *__gxx_personality_v0 = 0;
void *_Unwind_Resume = 0;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Palette w;
    w.show();

    return a.exec();
}
