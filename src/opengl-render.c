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

#include "SDL.h"
#include "SDL_opengl.h"

void display (void)
{
	glClear (GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity (); 
	gluLookAt (pacman.pos.x, pacman.pos.y + 4.0, pacman.pos.z + 4.0, 
				pacman.pos.x, pacman.pos.y, pacman.pos.z, 
				0.0, 1.0, 0.0 );
	
	glLightfv (GL_LIGHT0, GL_POSITION, light_position);	
	glLightfv (GL_LIGHT0, GL_DIFFUSE, light_intensity);
	
	/* drawing here! */
	man_draw (&pacman);
	man_draw (&man2);
	bille_draw (&billes);
	
	glPushMatrix ();
	material_set_color (0.0, 1.0, 0.0);
	glTranslatef (0.0, -0.5, 0.0);
	glScalef (5.0, 0.5, 10.0);
	//glRotatef (20.0, 1.0, 0.0, 0.0);		//DONOT un-comment
	glutSolidCube (1);
	glPopMatrix ();
	
	wall_draw (&w1);
	wall_draw (&w2);
	
	glutSwapBuffers ();
}

/* initialize opengl */
void init_gl (void)
{
	glEnable (GL_DEPTH_TEST);
	glDisable (GL_NORMALIZE);
	glDepthFunc (GL_LESS);
	glEnable (GL_LIGHTING);
	glEnable (GL_LIGHT0);
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective ( 45.0, 1, 1.0f, 20.0f);
	
	pacman.pos.x = 0.0;
	pacman.pos.y = 0.1;
	pacman.pos.z = 1.5;
	pacman.radius = 0.1;
	pacman.evil = FALSE;
	pacman.velocity [0] = 0;
	pacman.velocity [1] = 0;
	pacman.velocity [2] = 0;

	man2.pos.x = 0.0;
	man2.pos.y = 0.1;
	man2.pos.z = -1.0;
	man2.radius = 0.1;
	man2.evil = TRUE;
	man2.velocity [0] = 0;
	man2.velocity [1] = 0;
	man2.velocity [2] = 0;
	
	billes.points.x = 0.0;
	billes.points.y = 0.1;
	billes.points.z = -2.5;
	billes.radius = 0.05;
	billes.visible = TRUE;

	//============= ANDREW'S TESTING CODE DON'T REMOVE ================
	
	w1.pos.x = 0;
	w1.pos.y = 0;
	w1.pos.z = 0;
	w1.orient = HORIZONTAL;
	w1.length = 4;
	
	w2.pos.x = 0;
	w2.pos.y = 0;
	w2.pos.z = 0;
	w2.orient = VERTICAL;
	w2.length = 2;
	
	//========== END OF ANDREW'S TESTING CODE DON'T REMOVE ============
	
	animation_running = 1;
	animate ( 1 );
}

/* called when window is resized */
void resize (int width, int height)
{
	win_w = width;
	win_h = height;
	glViewport (0, 0, win_w, win_h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective (45.0f, (GLfloat) win_w / (GLfloat) win_h, 1.0f, 20.0f);
	glutPostRedisplay ();
}
