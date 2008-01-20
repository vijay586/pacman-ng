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
#include "material.h"

/* NOTE: should only be called from draw_* functions! */
void material_set_color (float r, float g, float b)
{
	GLfloat mat_ambient [] = {r, g, b, 1.0};
	GLfloat mat_specular [] = {r, g, b, 1.0};
	GLfloat mat_shininess [] = {90.0};
	
	glMaterialfv (GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
	glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv (GL_FRONT, GL_SHININESS, mat_shininess);
}
