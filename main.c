#include <stdio.h>
#include "display.h"

int main() {
	RESOURCE resource = { 10,50,5,20 };
	char front_buffer[N_LAYER][MAP_HEIGHT][MAP_WIDTH] = {{{0}}};
	char back_buffer[N_LAYER][MAP_HEIGHT][MAP_WIDTH] = {{{0}}};
	POSITION cursor = { MAP_HEIGHT / 2, MAP_WIDTH / 2 };

	initialize_map(front_buffer);

	while (1) {
		display (front_buffer, resource, cursor);
		display_command_box(front_buffer, cursor);
		display_system_message("Game started...");

		KEY key = get_key();
		switch (key) {
		case k_up: if (cursor.row > 0) cursor.row--; break; // 위쪽 이동
		case k_down: if (cursor.row < MAP_HEIGHT - 1) cursor.row++; break; // 아래쪽 이동
		case k_left: if (cursor.col > 0) cursor.col--; break; // 왼쪽 이동
		case k_right: if (cursor.col < MAP_WIDTH - 1) cursor.col++; break; // 오른쪽 이동
		case k_quit: printf("Exiting...\n"); return 0; // 종료S
		default: break; // 나머지 키 무시
		}
	}

	return 0;
}