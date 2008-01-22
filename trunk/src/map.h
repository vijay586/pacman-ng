#ifndef __MAP
#define __MAP

#include "wall.h"

#define MAP_WIDTH 20
#define MAP_HEIGHT 20
#define MAP_CELL_SIZE 0.3

struct _map
{
	wall *walls;
};
typedef struct _map map;

#endif
