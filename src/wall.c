#include "wall.h"
#include "global.h"
#include <GL/glut.h>

void wall_draw ( wall *w )
{
	glColor3f ( 0.5, 0.5, 0.5 );
	glPushMatrix ();
	glTranslated ( w->start.x, w->start.y + 0.5*WALL_THICKNESS, w->start.z );
	glScaled ( 0.5, 0.5, 0.5 );
	glutSolidCube ( 0.5 );
	glPopMatrix ();
}
