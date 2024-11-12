#include <stdio.h>
#include "display.h"

int main() {
	RESOURCE resource = { 0,0,0,0 };
	CUROR cursor = { 5,5 };
	char map[MAP_HEIGHT][MAP_WIDTH];

	initialize_map(map);

	display(resource, map, cursor);

	return 0;
}