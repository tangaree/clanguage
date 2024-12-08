#ifndef DISPLAY_H
#define DISPLAY_H

#include<Windows.h>

#define MAP_HEIGHT 18
#define MAP_WIDTH 60
#define N_LAYER 2

typedef struct {
	int spice;
	int spice_max;
	int population;
	int population_max;
} RESOURCE;

typedef struct {
	int row;
	int col;
} POSITION;

typedef struct {
	POSITION pos;
	POSITION dest;
	char repr;
	int move_period;
	int next_move_time;
} OBJECT_SAMPLE;

typedef enum {
	k_none = 0,
	k_up,
	k_down,
	k_left,
	k_right,
	k_quit,
	k_undef,
}KEY;

void setCursorPosition(int x, int y);
void setColor(int color);
void initialize_map(char map[N_LAYER][MAP_HEIGHT][MAP_WIDTH]);
void display(char map[N_LAYER][MAP_HEIGHT][MAP_WIDTH], RESOURCE resource, CURSOR cursor);

KEY get_key();

#endif