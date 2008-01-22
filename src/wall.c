/*
 * This file is part of pacman-ng
 * 
 * pacman-ng A 3D version of the pacman game
 * Copyright (C) 2008	Frederic-Gerald Morcos (fredmorcos)
 * 						Marleine Mounir Daoud
 * 						Andrew Botros Boktor
 * 
 * pacman-ng is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * pacman-ng is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with pacman-ng.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

#include "wall.h"

wall *wall_new (float posx, float posy, float posz, orientation or, float len)
{
	wall *new_wall = calloc (1, sizeof (wall));
	new_wall->fPosX = posx;
	new_wall->fPosY = posy;
	new_wall->fPosZ = posz;
	new_wall->orient = or;
	new_wall->fLength = len;
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
	
	printf ( "Length = %f,  Orientation = %d\n", w->fLength, w->orient );
	printf ( "Position %f %f %f\n", w->fPosX, w->fPosY, w->fPosZ );
	printf ( "Scaling %f %f %f\n", scaling_x, scaling_y, scaling_z );
	printf ( "Traslating %f %f %f\n\n", trans_x, trans_y, trans_z );


	glPushMatrix ();
	glTranslated ( trans_x, trans_y, trans_z );
	glScaled ( scaling_x, scaling_y, scaling_z );
	glutSolidCube ( 1 );
	glPopMatrix ();
}

