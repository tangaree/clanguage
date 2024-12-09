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
		case k_up: if (cursor.row > 0) cursor.row--; break; // ���� �̵�
		case k_down: if (cursor.row < MAP_HEIGHT - 1) cursor.row++; break; // �Ʒ��� �̵�
		case k_left: if (cursor.col > 0) cursor.col--; break; // ���� �̵�
		case k_right: if (cursor.col < MAP_WIDTH - 1) cursor.col++; break; // ������ �̵�
		case k_quit: printf("Exiting...\n"); return 0; // ����S
		default: break; // ������ Ű ����
		}
	}

	return 0;
}