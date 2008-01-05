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

#include "man.h"
#include <GL/glut.h>

void man_draw (man *m)
{
	if (m->evil)
		glColor3f (1.0, 0.0, 0.0);		/* FIXME: doesn't draw in red :S */
	else
		glColor3f (0.5, 0.5, 0.5);
	
	glPushMatrix ();
	glTranslatef (m->x, m->y, m->z);
	glutSolidSphere (m->radius, 100, 100);
	glPopMatrix ();
}
