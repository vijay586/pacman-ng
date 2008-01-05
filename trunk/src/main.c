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

void init (void);
void cb_exit (void);
void resize (int width, int height);
void keyboard (unsigned char key, int x, int y);
void keyboard_special (int key, int x, int y);
void display (void);

man pacman = {0.0, -0.5, -2.0, 0.5, FALSE};

int main (int argc, char *argv[])
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
	man_draw (&pacman);
	
	glutSwapBuffers ();
}

/* initialize opengl */
void init (void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_SMOOTH);
	glViewport (0, 0, win_w, win_h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective (45.0f, (GLfloat) win_w / (GLfloat) win_h, 1.0f, 1000.0f);
	glEnable (GL_DEPTH_TEST);
	glEnable (GL_LIGHTING);
	glEnable (GL_LIGHT0);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

/* called when window is resized */
void resize (int width, int height)
{
	win_w = width;
	win_h = height;
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
