#include "window_ops.h"
#include <Windows.h>
#include <cstdio>

struct OpaqueWinImpl {
	HWND window;
};

long getCursorX()
{
    CURSORINFO cursor;
    cursor.cbSize = sizeof(CURSORINFO);
    GetCursorInfo(&cursor);
    return cursor.ptScreenPos.x;
}

long getCursorY()
{
    CURSORINFO cursor;
    cursor.cbSize = sizeof(CURSORINFO);
    GetCursorInfo(&cursor);
    return cursor.ptScreenPos.y;
}

OpaqueWin getWindowUnderCursor()
{
	POINT cursor;
	GetCursorPos(&cursor);
	HWND wnd = WindowFromPoint(cursor);
	OpaqueWinImpl *win = new OpaqueWinImpl;
	win->window = wnd;
	return win;
}

void dbgPrintWindow(OpaqueWin w)
{
	if(w->window == NULL) {
		printf("no window\n");
	} else {
                TCHAR *winText = new TCHAR[50];
                GetWindowText(w->window, (LPWSTR)winText, 50);
		delete winText;
	}
}

bool windowMaximizedP(OpaqueWin w)
{
	WINDOWPLACEMENT wplace;
	wplace.length = sizeof(WINDOWPLACEMENT);
	GetWindowPlacement(w->window, &wplace);
	return wplace.showCmd == SW_MAXIMIZE;
}

//abstraction for the set showcmd routine.
//takes in a new value for showcmd.
void modifyWindowPlacement(OpaqueWin w, UINT op)
{
	WINDOWPLACEMENT wplace;
	wplace.length = sizeof(WINDOWPLACEMENT);
	GetWindowPlacement(w->window, &wplace);
	wplace.showCmd = op;
	SetWindowPlacement(w->window, &wplace);
}

void windowMinimize(OpaqueWin w)
{
	modifyWindowPlacement(w, SW_MINIMIZE);
}

void windowToggleMaximize(OpaqueWin w)
{
	if(windowMaximizedP(w))
		modifyWindowPlacement(w, SW_RESTORE);
	else
		modifyWindowPlacement(w, SW_MAXIMIZE);
}

void windowClose(OpaqueWin w)
{
	SendMessage(w->window, WM_CLOSE, 0, 0);
}
