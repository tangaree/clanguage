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

	map[MAP_HEIGHT - 4][4] = '5';
	map[2][MAP_WIDTH - 5] = '5';
	map[MAP_HEIGHT - 4][5] = 'H';
	map[1][MAP_WIDTH - 6] = 'H';

	map[5][10] = 'W';
	map[10][25] = 'W';

	map[8][15] = 'R';
	map[10][30] = 'R';
	map[11][30] = 'R';
	map[10][31] = 'R';
	map[11][31] = 'R';


}

void display_map(char map[MAP_HEIGHT][MAP_WIDTH]) {
	setCursorPosition(0, 1);

	for (int i = 0; i < MAP_WIDTH + 2; i++) {
		printf("#");
	}
	printf("\#");

	for (int i = 0; i < MAP_HEIGHT; i++) {
		printf("#");
		for (int j = 0; j < MAP_WIDTH; j++) {
			// 개체에 따른 색상 설정
			switch (map[i][j]) {
			case 'B':
				setColor(1);  // 파란색 (Atreides 본부)
				break;
			case 'H':
				setColor(4);  // 빨간색 (Harvester)
				break;
			case 'W':
				setColor(6);  // 황토색 (샌드웜)
				break;
			case 'P':
				setColor(8);  // 검은색 (장판)
				break;
			case 'R':
				setColor(7);  // 회색 (바위)
				break;
			case ' ':
				setColor(15); // 기본 흰색 (빈칸)
				break;
			default:
				setColor(14); // 주황색 (스파이스는 숫자와 상관없이 주황색)
				break;
			}
			printf("%c", map[i][j]);
		}
		setColor(15);
		printf("#\n");
	}

	for (int i = 0; i < MAP_WIDTH + 2; i++) {
		printf("#");
	}
	printf("\n");
}

void display_resource(RESOURCE resource) {
	printf("spice = %d/%d, population = %d%d\n", resource.spice, resource.spice_max, resource.population, resource.population_max);
}

void display_status() {
	setCursorPosition(0, MAP_HEIGHT + 2);
	printf("상태 창\n");
}

void display_system_message() {
	setCursorPosition(0, MAP_HEIGHT + 3); 
	printf("시스템 메시지 창\n");
}

void display_command() {
	setCursorPosition(0, MAP_HEIGHT + 4); 
	printf("명령 창\n");
}


void display(RESOURCE resource, char map[MAP_HEIGHT][MAP_WIDTH], CURSOR cursor) {
	display_resource(resource);
	display_map(map);
	display_status();
	display_system_message();
	display_command();
}
