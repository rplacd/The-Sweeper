#ifndef CELLLOCATION_UTIL_H
#define CELLLOCATION_UTIL_H

#include <QString>

const int numKeyRoots = 8;
const QString keyRoots[numKeyRoots] = { QString("tl"), QString("tc"), QString("tr"),
                              QString("cl"),                QString("cr"),
                              QString("bl"), QString("bc"), QString("br") };

inline void mapLocStr(const QString &loc, int *x, int *y)
{
    if(loc == "tl")
        *y = 0, *x = 0;
    else if(loc == "tc")
        *y = 1, *x = 0;
    else if(loc == "tr")
        *y = 2, *x = 0;
    else if(loc == "cl")
        *y = 0, *x = 1;
    else if(loc == "cr")
        *y = 2, *x = 1;
    else if(loc == "bl")
        *y = 0, *x = 2;
    else if(loc == "bc")
        *y = 1, *x = 2;
    else if(loc == "br")
        *y = 2, *x = 2;
    else
        *y = 0, *x = 0;
    return;
}

#endif // CELLLOCATION_UTIL_H
