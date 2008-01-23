#include <GL/freeglut.h>
#include <stdio.h>

#include "text.h"

void renderText (char *x)
{
	glColor3d (1, 1, 1);
	glRasterPos3d(0, 0, 100);
	// glutBitmapString(GLUT_BITMAP_9_BY_15, x);
	//glutBitmapCharacter (GLUT_BITMAP_9_BY_15, x);
}
