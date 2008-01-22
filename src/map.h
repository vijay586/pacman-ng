#ifndef __MAP
#define __MAP

#include "wall.h"

#define MAP_WIDTH 20
#define MAP_HEIGHT 20
#define MAP_CELL_SIZE 0.3

struct _map
{
	wall *walls;
	int walls_len;
};
typedef struct _map map;


map *map_new ();
void map_add_wall (map *m, wall *w);
void map_draw (map *m);
int map_can_be_here (map *m, int x, int z);

#endif
