#include <stdio.h>
#include <Windows.h>
#include "display.h"
 
void setCursorposition(int x, int y) {
	COORD coord = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void initialize_map(char map[MAP_HEIGHT][MAP_WIDTH]) {
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			map[i][j] = ' ';
		}
	}
	map[MAP_HEIGHT - 3][2] = 'B';
	map[MAP_HEIGHT - 3][3] = 'B';
	map[MAP_HEIGHT - 2][2] = 'B';
	map[MAP_HEIGHT - 2][3] = 'B';
	map[MAP_HEIGHT - 3][4] = 'P';
	map[MAP_HEIGHT - 2][4] = 'P';

	map[1][MAP_HEIGHT - 3] = 'B';
	map[1][MAP_HEIGHT - 2] = 'B';
	map[2][MAP_HEIGHT - 3] = 'B';
	map[2][MAP_HEIGHT - 2] = 'B';
	map[1][MAP_HEIGHT - 4] = 'P';
	map[2][MAP_HEIGHT - 4] = 'P';
}