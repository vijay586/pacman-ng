#include <stdlib.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include "glut-extra.h"
#include "global.h"
#include "opengl-render.h"
#include "ground.h"
#include "bille.h"
#include "wall.h"
#include "man.h"
#include "map.h"

#define WIN_W 800
#define WIN_H 600

void testBille (void);
void testPac (void);
void testWall (void);

void initGame (void);

void cbKeyboard (unsigned char ucKey, int iX, int iY);
void cbKeyboardSpecial (int iKey, int iX, int iY);
void cbDisplay (void);
void cbExit (void);

ground *pGround;
unsigned int displayList;

int main (int argc, char *argv [])
{
	atexit (cbExit);
	glutInit (&argc, argv);
	initGlutWindow (WIN_W, WIN_H);
	initGlut ();
	initOpenGL (WIN_W, WIN_H);
	initGame ();
	glutMainLoop ();
	return 0;
}

void initGame ()
{
	pGround = newGround (13, 2, 13);
	
	displayList = glGenLists (1);
	glNewList (displayList, GL_COMPILE);
	renderGround (pGround);
	testWall ();
	testBille ();
	testPac ();
	glEndList ();
}

void testBille ()
{
	bille *bille1 = newBille (4, 0, 5, TRUE);
	bille_draw (bille1);
}

void testPac ()
{
	man *pacman = newMan (4.0, 0.0, 0.0, FALSE);
	renderMan (pacman);
	
	man *evil1 = newMan (-8.0, 0.0, 0.0, TRUE);
	renderMan (evil1);
}

void testWall ()
{
	map *my_map = map_new ();
	
	wall *w1 = wall_new (5.0, 0.0, 5.0, HORIZONTAL, 1);
	map_add_wall (my_map, w1);
	
	wall *w2 = wall_new (2.0, 0.0, 5.0, HORIZONTAL, 1);
	map_add_wall (my_map, w2);
	
	wall *w3 = wall_new (-2.0, 0.0, 4.0, VERTICAL, 3);
	map_add_wall (my_map, w3);
	
	wall *w4 = wall_new (-4.5, 0.0, 5.0, HORIZONTAL, 2);
	map_add_wall (my_map, w4);
	
	wall *w5 = wall_new (3.0, 0.0, 4.0, HORIZONTAL, 1);
	map_add_wall (my_map, w5);
	
	wall *w6 = wall_new (0.0, 0.0, 2.0, VERTICAL, 5);
	map_add_wall (my_map, w6);
	
	wall *w7 = wall_new (4.0, 0.0, 3.0, HORIZONTAL, 1);
	map_add_wall (my_map, w7);
	
	wall *w8 = wall_new (2.0, 0.0, 3.0, HORIZONTAL, 1);
	map_add_wall (my_map, w8);
	
	wall *w9 = wall_new (-4.5, 0.0, 3.0, HORIZONTAL, 2);
	map_add_wall (my_map, w9);
	
	wall *w10 = wall_new (-5.0, 0.0, 2.0, HORIZONTAL, 1);
	map_add_wall (my_map, w10);
	
	wall *w11 = wall_new (4.5, 0.0, 1.0, HORIZONTAL, 2);
	map_add_wall (my_map, w11);
	
	wall *w12 = wall_new (-0.5, 0.0, 1.0, HORIZONTAL, 6);
	map_add_wall (my_map, w12);
	
	wall *w13 = wall_new (-4.0, 0.0, -0.5, VERTICAL, 2);
	map_add_wall (my_map, w13);
	
	wall *w14 = wall_new (5.0, 0.0, -1.5, VERTICAL, 2);
	map_add_wall (my_map, w14);
	
	wall *w15 = wall_new (2.5, 0.0, -1.0, HORIZONTAL, 2);
	map_add_wall (my_map, w15);
	
	wall *w16 = wall_new (-1.5, 0.0, -1.0, HORIZONTAL, 2);
	map_add_wall (my_map, w16);
	
	wall *w17 = wall_new (1.0, 0.0, -2.0, VERTICAL, 1);
	map_add_wall (my_map, w17);
	
	wall *w18 = wall_new (-2.0, 0.0, -2.0, VERTICAL, 1);
	map_add_wall (my_map, w18);
	
	wall *w19 = wall_new (2.0, 0.0, -3.0, HORIZONTAL, 3);
	map_add_wall (my_map, w19);
	
	wall *w20 = wall_new (-3.0, 0.0, -3.5, VERTICAL, 2);
	map_add_wall (my_map, w20);
	
	wall *w21 = wall_new (-5.0, 0.0, -3.0, VERTICAL, 1);
	map_add_wall (my_map, w21);
	
	wall *w22 = wall_new (3.0, 0.0, -4.0, HORIZONTAL, 3);
	map_add_wall (my_map, w22);
	
	wall *w23 = wall_new (-1.0, 0.0, -4.5, VERTICAL, 2);
	map_add_wall (my_map, w23);
	
	wall *w24 = wall_new (0.0, 0.0, -5.0, HORIZONTAL, 1);
	map_add_wall (my_map, w24);
	
	wall *w25 = wall_new (-4.0, 0.0, -5.0, HORIZONTAL, 1);
	map_add_wall (my_map, w25);
	
	
	
	
	
	map_draw (my_map);
}

void cbDisplay ()
{
	renderOpenGL (displayList);
}

void cbKeyboard (unsigned char ucKey, int iX, int iY)
{
	switch (ucKey)
	{
		case 'q':
			glutLeaveMainLoop ();
			break;
	}
}

void cbKeyboardSpecial (int iKey, int iX, int iY)
{
	switch (iKey)
	{
		case GLUT_KEY_UP:
			break;
		case GLUT_KEY_DOWN:
			break;
		case GLUT_KEY_LEFT:
			break;
		case GLUT_KEY_RIGHT:
			break;
	}
}

void initGlut ()
{
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_ACCUM | GLUT_DEPTH);	
	glutDisplayFunc (cbDisplay);
//	glutIdleFunc (renderOpenGL);
//	glutReshapeFunc (resize);
	glutKeyboardFunc (cbKeyboard);
	glutSpecialFunc (cbKeyboardSpecial);
	
}

void cbExit ()
{
	/* free your stuff here, we're exiting */
	free (pGround);
}
