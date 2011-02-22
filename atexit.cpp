#include <cstdlib>
#include <QString>

static QString exitcmd;
void _atExit()
{
    std::system((const char *)exitcmd.toLatin1());
}

void setExitCmd(QString &cmd)
{
    exitcmd = QString(cmd);
    std::atexit(_atExit);
}


