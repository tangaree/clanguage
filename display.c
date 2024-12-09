#include <stdio.h>
#include <Windows.h>
#include<conio.h>
#include "display.h"
 
void setCursorPosition(int x, int y) {
	COORD coord = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void display_command_box(char map[N_LAYER][MAP_HEIGHT][MAP_WIDTH], POSITION cursor) {
	setCursorPosition(0, MAP_HEIGHT + 3); 
	printf("Command Box: Cursor at (%d, %d)\n", cursor.row, cursor.col);
}

void clear_command_box() {
	setCursorPosition(0, MAP_HEIGHT + 3);
	for (int i = 0; i < 80; i++) { 
		printf(" ");
	}
	setCursorPosition(0, MAP_HEIGHT + 3);
}

void display_system_message(const char* message) {
	static char log[5][50] = { 0 }; 
	for (int i = 4; i > 0; i--) {
		strcpy_s(log[i], sizeof(log[i]), log[i - 1]);
	}
	strcpy_s(log[0], sizeof(log[0]), message);

	
	for (int i = 0; i < 5; i++) {
		setCursorPosition(0, MAP_HEIGHT + 5 + i);
		printf("%s\n", log[i]);
	}
}


void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void initialize_map(char map[N_LAYER][MAP_HEIGHT][MAP_WIDTH]) {
	for (int layer = 0; layer < N_LAYER; layer++) {
		for(int i = 0;i<MAP_HEIGHT; i++){
			for (int j = 0; j < MAP_WIDTH; j++) {
				map[layer][i][j] = ' ';
			}
		}
	}
	//지형 초기화
	map[0][MAP_HEIGHT - 3][2] = 'B'; //base
	map[0][MAP_HEIGHT - 3][3] = 'B';
	map[0][MAP_HEIGHT - 2][2] = 'B';
	map[0][MAP_HEIGHT - 2][3] = 'B';
	map[0][5][10] = 'R';//rock
	map[0][10][25] = 'R';
	map[0][MAP_HEIGHT - 4][4] = 'P'; //plate
	map[0][MAP_HEIGHT - 2][4] = 'P';
	map[0][MAP_HEIGHT - 4][5] = '5';//spice

	//유닛 초기화
	map[1][MAP_HEIGHT - 4][5] = 'H';//harvester
	map[1][10][25] = 'W';//sandworm
	
}
	/*char map[N_LAYER][MAP_HEIGHT][MAP_WIDTH] = { {{0}} };
	char back_buffer[N_LAYER][MAP_HEIGHT][MAP_WIDTH] = { {{0}} };
	setCursorPosition(0, 0);*/

void display(char map[N_LAYER][MAP_HEIGHT][MAP_WIDTH], RESOURCE resource, POSITION cursor) {
	setCursorPosition(0, 0);

	for (int i = 0; i < MAP_WIDTH + 2; i++) {
		printf("#");
	}
	printf("\n");

	for (int i = 0; i < MAP_HEIGHT; i++) {
		printf("#");
		for (int j = 0; j < MAP_WIDTH; j++) {
			// 유닛,지형 구분
			char obj = map[1][i][j] != ' ' ? map[1][i][j] : map[0][i][j];

			if (cursor.row == i && cursor.col == j) {
				setColor(2);
			}
			else {
				switch (obj) {
				case'B': setColor(1); break;
				case'H': setColor(4); break;
				case'W': setColor(6); break;
				case'p': setColor(8); break;
				case'R': setColor(7); break;
				case'5': setColor(14); break;
				default: setColor(15); break;
				}
			}
			printf("%c", obj);
		}
		setColor(15);
		printf("#\n");
	}

	for (int i = 0; i < MAP_WIDTH + 2; i++) {
		printf("#");
	}
	printf("\n");
	printf("Spice: %d/%d, Population: %d/%d\n", resource.spice, resource.spice_max, resource.population, resource.population_max);
	setCursorPosition(0, MAP_HEIGHT + 2);
	printf("상태창: 커서 위치 (%d, %d)\n", cursor.row, cursor.col);
	setCursorPosition(0, MAP_HEIGHT + 4);
	printf("#시스템 메시지 창 #\n");
	printf("#   명   령    창 #\n");
}

KEY get_key() {
	if (!_kbhit()) {
		return k_none;
	}
	int byte = _getch();
	switch (byte) {
	case 'q': return k_quit;
	case 224:
		byte = _getch();
		switch (byte) {
		case 72: return k_up;
		case 75: return k_left;
		case 77: return k_right;
		case 80: return k_down;
		}
	}
	return k_undef;
}

