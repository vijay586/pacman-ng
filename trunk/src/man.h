#ifndef __MAN
#define __MAN

/* 
 * the pacman is either a sphere or a fat circle,
 * it has a color, a radius, a place and a rotation
 */
struct _man
{
	int x, y, z;
	int radius;
	float x_r, x_y, z_r;
	float r, g, b;
};

typedef struct _man man;

#endif
