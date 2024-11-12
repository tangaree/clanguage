#ifndef DISPLAY_H
#define DISPLAY_H

#define MAP_HEIGHT 18
#define MAP_WIDTH 60

typedef struct {
	int spice;
	int spice_max;
	int population;
	int population_max;
} RESOURCE;

typedef struct {
	int row;
	int colum;
} CURSOR;

void setCursorPosition(int x, int y);
void setColor(int color);
void initialize_map(char map[MAP_HEIGHT][MAP_WIDTH]);
void display(RESOURCE resource, char map[MAP_HEIGHT][MAP_WIDTH], CURSOR cursor);
void display_map(char map[MAP_HEIGHT][MAP_WIDTH]);
void display_resource(RESOURCE resource);
void display_status();
void display_system_message();
void display_command();

#endif