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

void initGame (void);

void cbKeyboard (unsigned char ucKey, int iX, int iY);
void cbKeyboardSpecial (int iKey, int iX, int iY);
void cbDisplay (void);
void cbExit (void);

int man_posx;
man *pacman;
map *my_map;
ground mainGround = {21.0, 0.6, 21.0};

int iMainWindow, iSubWindow;
ground *pGround;


int main (int argc, char *argv [])
{
	atexit (cbExit);
	initGame ();
	glutInit (&argc, argv);
	initGlutWindow (WIN_W, WIN_H, &iMainWindow, &iSubWindow);
	initGlut ();
	initOpenGL (WIN_W, WIN_H);
	glutMainLoop ();
	return 0;
}

void initGame ()
{
	pGround = newGround (11, 2, 21);
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
	wall *w = wall_new (-10.0, 0.0, 16.0, HORIZONTAL, 20);
	wall_draw (w);
}

void cbTopView ()
{
	renderTopView ();
	renderGround (pGround);
	testWall ();
	testBille ();
	testPac ();
	glutSwapBuffers ();
}

void cbDisplay ()
{
	renderOpenGL ();
	renderGround (pGround);
	
	testWall ();
	testBille ();
	testPac ();
	

	glutSwapBuffers ();
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


void up_button ()
{
	int check = map_can_be_here (my_map, pacman->fx, pacman->fz);
	printf ("CHECK %d\n", check);
	if (check)
	{
		//man_move (pacman);
		glutPostRedisplay ();
	}
}

void cbKeyboardSpecial (int iKey, int iX, int iY)
{
	switch (iKey)
	{
		case GLUT_KEY_UP:
			up_button ();
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
	
	glutSetWindow (iSubWindow);
	glutDisplayFunc (cbTopView);
	
	glutSetWindow (iMainWindow);
	glutDisplayFunc (cbDisplay);
	
//	glutIdleFunc (renderOpenGL);
//	glutReshapeFunc (resize);
	glutKeyboardFunc (cbKeyboard);
	glutSpecialFunc (cbKeyboardSpecial);
	
	pacman = newMan(0.0, 0.0, 0.0, FALSE);
	my_map = map_new ();
	wall *w1 = wall_new (-10.0, 0.0, 0.0, VERTICAL, 21);
	map_add_wall (my_map, w1);
	wall *w2 = wall_new (10.0, 0.0, 0.0, VERTICAL, 21);
	map_add_wall (my_map, w2);
	wall *w3 = wall_new (0.0, 0.0, 10.0, HORIZONTAL, 21);
	map_add_wall (my_map, w3);
	wall *w4 = wall_new (0.0, 0.0, -10.0, HORIZONTAL, 21);
	map_add_wall (my_map, w4);
}

void cbExit ()
{
	/* free your stuff here, we're exiting */
}
