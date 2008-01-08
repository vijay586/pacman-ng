#ifndef __WALL
#define __WALL

#include "global.h"

enum _orientation
{
	VERTICAL = 0,
	HORIZONTAL = 1
};
typedef enum _orientation orientation;

struct _wall
{
	point pos;
	orientation orient;
	int length;
};
typedef struct _wall wall;




#define WALL_THICKNESS 1
#define WALL_HEIGHT 1

void wall_draw ( wall *w );

#endif
