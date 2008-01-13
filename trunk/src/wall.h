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
	float length;
};
typedef struct _wall wall;




#define WALL_THICKNESS 0.3
#define WALL_HEIGHT 1

void wall_draw ( wall *w );

#endif
