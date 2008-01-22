#include "ground.h"

#include <GL/freeglut.h>
#include <stdlib.h>

void renderGround (ground *g)
{
	glPushMatrix ();
	glColor3f (0.0, 1.0, 0.0);
	glTranslatef (0.0, -((g->fHeight) / 2), 0.0);
	glScalef (g->fWidth, g->fHeight, g->fDepth);
	glutSolidCube (1);
	glPopMatrix ();
}

ground *newGround (float fW, fH, fD)
{
	ground *temp = calloc (1, sizeof (ground));
	temp->fWidth = fW;
	temp->fHeight = fH;
	temp->fDepth = fD;
	return temp;
}
