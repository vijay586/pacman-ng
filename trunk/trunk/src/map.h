#ifndef __MAP
#define __MAP

#define MAP_WIDTH 20
#define MAP_HEIGHT 20

#define MAP_CELL_SIZE 0.3

struct _map
{
	int squares[MAP_WIDTH][MAP_HEIGHT];
};
typedef struct _map map;


int map_cell_empty ( map* m, int posx, int posz );

#endif
