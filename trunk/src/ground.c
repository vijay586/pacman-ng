#include "ground.h"

#include <GL/freeglut.h>
#include <stdlib.h>

inline void renderGround (ground *g)
{
	glPushMatrix ();
	glColor3f (0.0, 1.0, 0.0);
	glTranslatef (0.0, -((g->fHeight) / 2), 0.0);
	glScalef (g->fWidth, g->fHeight, g->fDepth);
	glutSolidCube (1);
	
	glPopMatrix ();
}

ground *newGround (float fw, float fh, float fd)
{
	ground *temp = calloc (1, sizeof (ground));
	temp->fWidth = fw;
	temp->fHeight = fh;
	temp->fDepth = fd;
	
	return temp;
}
