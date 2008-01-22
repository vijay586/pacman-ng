#include "bille.h"

#include <GL/freeglut.h>
#include <stdlib.h>
#include "global.h"

bille *newBille (int ix, int iy, int iz, boolean bv)
{
	bille *temp = calloc (1, sizeof (bille));
	temp->ix = ix;
	temp->iy = iy;
	temp->iz = iz;
	temp->bVisible = bv;
	return temp;
}

inline void bille_draw (bille *b)
{
	if (!b->bVisible)
		return;
	
	glPushMatrix ();
	glColor3d (0, 1, 1);
	glTranslated (b->ix * CELL_SIZE, b->iy + (BILLE_RADIUS * 2), b->iz * CELL_SIZE);
	glutSolidSphere (BILLE_RADIUS, 5, 5);
	glPopMatrix ();
}

