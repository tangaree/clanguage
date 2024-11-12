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
			// ��ü�� ���� ���� ����
			switch (map[i][j]) {
			case 'B':
				setColor(1);  // �Ķ��� (Atreides ����)
				break;
			case 'H':
				setColor(4);  // ������ (Harvester)
				break;
			case 'W':
				setColor(6);  // Ȳ��� (�����)
				break;
			case 'P':
				setColor(8);  // ������ (����)
				break;
			case 'R':
				setColor(7);  // ȸ�� (����)
				break;
			case ' ':
				setColor(15); // �⺻ ��� (��ĭ)
				break;
			default:
				setColor(14); // ��Ȳ�� (�����̽��� ���ڿ� ������� ��Ȳ��)
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
	printf("���� â\n");
}

void display_system_message() {
	setCursorPosition(0, MAP_HEIGHT + 3); 
	printf("�ý��� �޽��� â\n");
}

void display_command() {
	setCursorPosition(0, MAP_HEIGHT + 4); 
	printf("��� â\n");
}


void display(RESOURCE resource, char map[MAP_HEIGHT][MAP_WIDTH], CURSOR cursor) {
	display_resource(resource);
	display_map(map);
	display_status();
	display_system_message();
	display_command();
}
