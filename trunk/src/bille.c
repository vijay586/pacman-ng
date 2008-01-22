#include "bille.h"

#include <GL/freeglut.h>
#include <stdlib.h>
#include "global.h"

bille *newBille (float fRadius, float fx, float fy, float fz, boolean bv)
{
	bille *temp = calloc (1, sizeof (bille));
	temp->fRadius = fRadius;
	temp->fx = fx;
	temp->fy = fy;
	temp->fz = fz;
	temp->bVisible = bv;
	return temp;
}

inline void bille_draw (bille *b)
{
	if (!b->bVisible)
		return;
	glPushMatrix ();
	glColor3f(0.0, 1.0, 1.0);
	glTranslatef (b->fx, b->fy + b->fRadius, b->fz);
	glutSolidSphere (b->fRadius, 100, 100);
	glPopMatrix ();
}
