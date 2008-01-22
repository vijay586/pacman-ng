#include "wall.h"
#include "global.h"
#include "material.h"
#include <GL/glut.h>
#include <stdio.h>

void wall_draw ( wall *w )
{
	
	material_set_color ( 0.0, 0.0, 1.0 );
	float scaling_x, scaling_y, scaling_z;
	float trans_x, trans_y, trans_z;
	if ( w->orient )
	{
		trans_x = w->pos.x;
		trans_z = w->pos.z;
		scaling_x = w->length;
		scaling_z = WALL_THICKNESS;
	}
	else
	{
		trans_z = w->pos.z;
		trans_x = w->pos.x;
		scaling_z = w->length;
		scaling_x = WALL_THICKNESS;
	}
	trans_y = w->pos.y;
	scaling_y = WALL_HEIGHT;
	
	
	/*
	
	trans_x = trans_y = 0;
	trans_z = -5;
	scaling_x = w->length;
	scaling_y = WALL_HEIGHT;
	scaling_z = WALL_THICKNESS;
	*/
	
	//printf ( "Length = %f,  Orientation = %d\n", w->length, w->orient );
	//printf ( "Position %f %f %f\n", w->pos.x, w->pos.y, w->pos.z );
	//printf ( "Scaling %f %f %f\n", scaling_x, scaling_y, scaling_z );
	//printf ( "Traslating %f %f %f\n\n", trans_x, trans_y, trans_z );

	glPushMatrix ();
	glTranslated ( trans_x, trans_y, trans_z );
	glScaled ( scaling_x, scaling_y, scaling_z );
	glutSolidCube ( 0.5 );
	glPopMatrix ();
}
