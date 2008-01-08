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

#include <stdlib.h>
#include <GL/glut.h>

#include "man.h"
#include "global.h"
#include "material.h"
#include "wall.h"

void init (void);
void cb_exit (void);
void resize (int width, int height);
void keyboard (unsigned char key, int x, int y);
void keyboard_special (int key, int x, int y);
void display (void);

man pacman = {0.0, -0.8, -2.5, 0.05, FALSE};

int main (int argc, char *argv [])
{
	win_w = 800;
	win_h = 600;
		
	atexit (cb_exit);
	
	/* initialize glut */
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (win_w, win_h);
	glutInitWindowPosition (200, 20);
	glutCreateWindow ("Pacman");
	glutDisplayFunc (display);
	glutIdleFunc (display);
	glutReshapeFunc (resize);
	glutKeyboardFunc (keyboard);
	glutSpecialFunc (keyboard_special);
	init ();
	glutMainLoop ();

	return 0;
}

/* the display callback */
void display (void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity (); 
	
	/* drawing here! */
	//man_draw (&pacman);
	
	/* draw the ground here */
	
	//============= ANDREW'S TESTING CODE DON'T REMOVE ================
	
	point pos1;
	pos1.x = 0;
	pos1.y = 0.5;
	pos1.z = -2;
	wall w1 = { pos1, HORIZONTAL, 3 };
	wall_draw ( &w1 );
	
	//========== END OF ANDREW'S TESTING CODE DON'T REMOVE ============
	/*
	material_set_color (0.0, 1.0, 0.0);
	glPushMatrix ();
	glTranslatef (0.0, -1.8, -9.5);
	glScalef (2.0, 1.0, 5.0);
	glRotatef (20.0, 1.0, 0.0, 0.0);
	glutSolidCube (2);
	glPopMatrix ();
	*/
	glutSwapBuffers ();
}

/* initialize opengl */
void init (void)
{
	glEnable (GL_DEPTH_TEST);
	glEnable (GL_LIGHTING);
	glEnable (GL_LIGHT0);
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glViewport (0, 0, win_w, win_h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective (45.0f, (GLfloat) win_w / (GLfloat) win_h, 1.0f, 1000.0f);
			
	material_set_color (0.5, 0.5, 0.5);
}

/* called when window is resized */
void resize (int width, int height)
{
	win_w = width;
	win_h = height;
	glViewport (0, 0, win_w, win_h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective (45.0f, (GLfloat) win_w / (GLfloat) win_h, 1.0f, 1000.0f);
	glutPostRedisplay ();
}

void keyboard (unsigned char key, int x, int y)
{
}

void keyboard_special (int key, int x, int y)
{
}

void cb_exit (void)
{
	/* free everything here */
}
