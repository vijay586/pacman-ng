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

#ifndef __WALL
#define __WALL

#define WALL_THICKNESS 0.3
#define WALL_HEIGHT 1.0


enum _orientation
{
	VERTICAL = 0,
	HORIZONTAL = 1
};
typedef enum _orientation orientation;

struct _wall
{
	float fPosX, fPosY, fPosZ;
	orientation orient;
	float fLength;
};
typedef struct _wall wall;


wall *wall_new (float posx, float posy, float posz, orientation or, float len);
void wall_draw ( wall *w );

#endif
