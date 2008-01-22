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

#include <GL/freeglut.h>
#include <stdlib.h>

#include "bille.h"

bille *newBille (float fRadius, float fx, float fy, float fz, int dvisible)
{
	bille *temp = calloc (1, sizeof (bille));
	temp->fRadius = fRadius;
	temp->fx = fx;
	temp->fy = fy;
	temp->fz = fz;
	temp->dvisible = dvisible;
	return temp;
}

inline void bille_draw (bille *b)
{
	if (!b->dvisible)
		return;
	glPushMatrix ();
	glColor3f(0.0, 1.0, 1.0);
	glTranslatef (b->fx, b->fy + b->fRadius, b->fz);
	glutSolidSphere (b->fRadius, 100, 100);
	glPopMatrix ();
}
