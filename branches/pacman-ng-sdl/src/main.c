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

/* this is the sdl branch */

#include <stdlib.h>
#include <GL/glut.h>

#include "man.h"
#include "global.h"
#include "material.h"
#include "wall.h"
#include "bille.h"

void init (void);
void cb_exit (void);
void resize (int width, int height);
void keyboard (unsigned char key, int x, int y);
void keyboard_special (int key, int x, int y);
void display (void);

man pacman, man2;
bille billes;
wall w1, w2;
int animation_running;
GLfloat light_intensity [] = {1.0, 1.0, 1.0, 0.0 };
GLfloat light_position [] = {0.0, 2.0, 9.0, 1.0};

void set_bille_visibility (void)
{
	if(	billes.points.z <= pacman.pos.z + pacman.radius && 
		billes.points.z >= pacman.pos.z - pacman.radius && 
		billes.points.x >= pacman.pos.x - pacman.radius &&
		billes.points.x <= pacman.pos.x + pacman.radius	)
			billes.visible = FALSE;
}

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
	bille_draw(&billes);
	
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

void animate ( int val )
{
	man_move (&pacman);
	set_bille_visibility();
	if ( animation_running )
		glutTimerFunc ( 5, animate, 1 );
}

/* initialize opengl */
void init (void)
{
	// glDisable (GL_DITHER);
	glEnable (GL_DEPTH_TEST);
	glDisable (GL_NORMALIZE);
	glDepthFunc (GL_LESS);
	glEnable (GL_LIGHTING);
	glEnable (GL_LIGHT0);
	glClearColor (0.0, 0.0, 0.0, 0.0);
	//glViewport (0, 0, win_w, win_h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	//gluPerspective (45.0f, (GLfloat) win_w / (GLfloat) win_h, 1.0f, 1000.0f);
	gluPerspective ( 45.0, 1, 1.0f, 20.0f);
	//gluLookAt ( 0.0, 2.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 ); 
	//material_set_color (0.5, 0.5, 0.5);
	
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

void keyboard (unsigned char key, int x, int y)
{
}

void keyboard_special (int key, int x, int y)
{
	if ( key == GLUT_KEY_UP )
	{
		// pacman.z -= 0.05;
		pacman.velocity [0] = 0;
		pacman.velocity [2] = -1;
	}
	else if ( key == GLUT_KEY_DOWN )
	{
		// pacman.z += 0.05;
		pacman.velocity [0] = 0;
		pacman.velocity [2] = 1;
	}
	else if ( key == GLUT_KEY_LEFT )
	{
		// pacman.x -= 0.05;
		pacman.velocity [0] = -1;
		pacman.velocity [2] = 0;
	}
	else if ( key == GLUT_KEY_RIGHT )
	{
		// pacman.x += 0.05;
		pacman.velocity [0] = 1;
		pacman.velocity [2] = 0;
	}
	// glutPostRedisplay ();
}

void cb_exit (void)
{
	/* free everything here */
}
