#include <stdio.h>
#include <Windows.h>
#include "display.h"
 
void setCursorposition(int x, int y) {
	COORD coord = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
