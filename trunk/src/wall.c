#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

#include "wall.h"

wall *wall_new (float fposx, float fposy, float fposz, orientation orient, float flen)
{
	wall *new_wall = calloc (1, sizeof (wall));
	new_wall->fPosX = fposx;
	new_wall->fPosY = fposy;
	new_wall->fPosZ = fposz;
	new_wall->orient = orient;
	new_wall->fLength = flen;
	return new_wall;
}

void wall_draw (wall *w)
{
	glColor3f (1.0, 0.0, 1.0);
	float scaling_x, scaling_y, scaling_z;
	float trans_x, trans_y, trans_z;
	if ( w->orient )
	{
		trans_x = w->fPosX;
		trans_z = w->fPosZ;
		scaling_x = w->fLength;
		scaling_z = WALL_THICKNESS;
	}
	else
	{
		trans_z = w->fPosZ;
		trans_x = w->fPosX;
		scaling_z = w->fLength;
		scaling_x = WALL_THICKNESS;
	}
	trans_y = w->fPosY + WALL_HEIGHT/2;
	scaling_y = WALL_HEIGHT;
	
	/*
	trans_x = trans_y = 0;
	trans_z = -5;
	scaling_x = w->length;
	scaling_y = WALL_HEIGHT;
	scaling_z = WALL_THICKNESS;
	*/
	
//	printf ( "Length = %f,  Orientation = %d\n", w->fLength, w->orient );
//	printf ( "Position %f %f %f\n", w->fPosX, w->fPosY, w->fPosZ );
//	printf ( "Scaling %f %f %f\n", scaling_x, scaling_y, scaling_z );
//	printf ( "Traslating %f %f %f\n\n", trans_x, trans_y, trans_z );

	glPushMatrix ();
	glTranslated ( trans_x, trans_y, trans_z );
	glScaled ( scaling_x, scaling_y, scaling_z );
	glutSolidCube ( 1 );
	glPopMatrix ();
}

