#include "ground.h"

#include <GL/freeglut.h>

void render_ground ()
{
	glPushMatrix ();
	glColor3f (0.0, 1.0, 0.0);
	glTranslatef (0.0, -0.5, 0.0);
	glScalef (5.0, 0.5, 10.0);
	glutSolidCube (1);
	glPopMatrix ();
}
