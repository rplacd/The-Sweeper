#ifndef WINDOW_OPS_H
#define WINDOW_OPS_H

typedef struct OpaqueWinImpl *OpaqueWin;
long getCursorX();
long getCursorY();
OpaqueWin getWindowUnderCursor();
void dbgPrintWindow(OpaqueWin w);
bool windowMaximizedP(OpaqueWin w);
void windowMinimize(OpaqueWin w);
void windowToggleMaximize(OpaqueWin w);
void windowClose(OpaqueWin w);
#endif
