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
#include "game.h"

#define WIN_W 800
#define WIN_H 600

void initGame (void);

void cbKeyboard (unsigned char ucKey, int iX, int iY);
void cbKeyboardSpecial (int iKey, int iX, int iY);
void cbDisplay (void);
void cbExit (void);

ground *pGround;
man *pPacman;
map *pMap;
bille *pBilles [85];
unsigned int displayList;

int main (int argc, char *argv [])
{
	atexit (cbExit);
	glutInit (&argc, argv);
	initGlutWindow (WIN_W, WIN_H);
	initGlut (cbDisplay, cbKeyboard, cbKeyboardSpecial);
	initOpenGL (WIN_W, WIN_H);
	initGame ();
	glutMainLoop ();
	return 0;
}

void initGame ()
{
	pGround = newGround (13, 2, 13);
	pPacman = newMan (3, 0, 5, FALSE);
	pMap = newMap ();
	initMap (pMap);
	initBilles (pMap, pBilles);
	displayList = glGenLists (1);
	glNewList (displayList, GL_COMPILE);
	//renderGround (pGround);
	//renderMap (pMap);
	//renderMan (pPacman);
	glEndList ();
}

void cbDisplay ()
{
	renderOpenGL (displayList, pPacman->ix * CELL_SIZE, pPacman->iz * CELL_SIZE);
	renderGround (pGround);
	renderMap (pMap);
	renderMan (pPacman);
	renderBilles (pBilles);
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

void cbKeyboardSpecial (int iKey, int iX, int iY)
{
	switch (iKey)
	{
		case GLUT_KEY_UP:
			if (map_can_be_here (pMap, pPacman->ix, pPacman->iz - 1))
				pPacman->iz--;
			break;
		case GLUT_KEY_DOWN:
			if (map_can_be_here (pMap, pPacman->ix, pPacman->iz + 1))
				pPacman->iz++;
			break;
		case GLUT_KEY_LEFT:
			if (map_can_be_here (pMap, pPacman->ix - 1, pPacman->iz))
				pPacman->ix--;
			break;
		case GLUT_KEY_RIGHT:
			if (map_can_be_here (pMap, pPacman->ix + 1, pPacman->iz))
				pPacman->ix++;
			break;
	}
	glutPostRedisplay ();
}

void cbExit ()
{
	/* free your stuff here, we're exiting */
	glDeleteTextures (1, &(pGround->uiTextureId));
	free (pGround);
	free (pPacman);
	free (pMap);
}
