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
#include <stdlib.h>
#include "map.h"

map *map_new ( int **sq )
{
	map *new_map = malloc ( sizeof ( map ) );
	new_map->squares = sq;
	
	return new_map;
}


void map_wall_draw ( int posx, int posz )
{
	glPushMatrix ();
	glColor3f ( 0.0, 0.0, 1.0 );
	glTranslated ( posx*MAP_CELL_SIZE, 0.5*MAP_CELL_SIZE, posz*MAP_CELL_SIZE );
	glScaled ( MAP_CELL_SIZE, 1, MAP_CELL_SIZE );
	glutSolidCube ( 1 );
	glPopMatrix ();
}

void map_draw (map *m)
{
	
}

int map_cell_empty ( map* m, int posx, int posz )
{
	return !m->squares[posx][posz];
}

