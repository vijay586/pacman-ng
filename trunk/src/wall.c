#include "wall.h"
#include "global.h"
#include <GL/glut.h>
#include <stdio.h>

void wall_draw ( wall *w )
{
	glColor3f ( 0.5, 0.5, 0.5 );
	float scaling_x, scaling_y, scaling_z;
	float trans_x, trans_y, trans_z;
	if ( w->orient )
	{
		trans_x = w->pos.x ;//+ (0.5*w->length);
		trans_z = w->pos.z ;//+ (0.5*WALL_THICKNESS);
		scaling_x = w->length;
		scaling_z = WALL_THICKNESS;
	}
	else
	{
		trans_z = w->pos.z ;//+ 0.5*(w->length);
		trans_x = w->pos.x ;//+ 0.5*(WALL_THICKNESS);
		scaling_z = w->length;
		scaling_x = WALL_THICKNESS;
	}
	trans_y = w->pos.y ;//+ 0.5*(WALL_HEIGHT);
	scaling_y = WALL_HEIGHT;
	
	printf ( "Length = %d,  Orientation = %d\n", w->length, w->orient );
	printf ( "Position %f %f %f\n", w->pos.x, w->pos.y, w->pos.z );
	printf ( "Scaling %f %f %f\n", scaling_x, scaling_y, scaling_z );
	printf ( "Traslating %f %f %f\n\n", trans_x, trans_y, trans_z );
	
	glPushMatrix ();
	glTranslated ( trans_x, trans_y, trans_z );
	glScaled ( scaling_x, scaling_y, scaling_z );
	glutSolidCube ( 0.5 );
	glPopMatrix ();
}
