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
#include "text.h"
#include "texture.h"

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
int score;
unsigned int texture;

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
	pPacman = newMan (-1, 0, 5, FALSE);
	pMap = newMap ();
	initMap (pMap);
	initBilles (pMap, pBilles, pPacman);
	score=0;
	displayList = glGenLists (1);
	glNewList (displayList, GL_COMPILE);
	//renderGround (pGround);
	//renderMap (pMap);
	//renderMan (pPacman);
	glEndList ();
	
	texture = LoadTextureRAW( "texture.raw", TRUE );
}



void testTexture ()
{
	glEnable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, texture );

	glPushMatrix();
	glColor3f (1.0, 1.0, 1.0);
	glScaled (60.0, 60.0, 60.0);
	glBegin( GL_QUADS );
	glTexCoord2d(0.0,0.0); glVertex3d(-1.0, 0.0, +1.0);
	glTexCoord2d(1.0,0.0); glVertex3d(+1.0, 0.0, +1.0);
	glTexCoord2d(1.0,1.0); glVertex3d(+1.0, 0.0, -1.0);
	glTexCoord2d(0.0,1.0); glVertex3d(-1.0, 0.0, -1.0);
	glEnd();
	glPopMatrix();
}

void cbDisplay ()
{
	renderOpenGL (displayList, pPacman->ix * CELL_SIZE, pPacman->iz * CELL_SIZE);
	testTexture ();
	renderGround (pGround);
	renderMap (pMap);
	renderMan (pPacman);
	renderBilles (pBilles);
	renderText (score);
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
			{
				pPacman->iz--;
				set_bille_visibility (pBilles, pPacman->ix, pPacman->iz, score);
			}
			break;
		case GLUT_KEY_DOWN:
			if (map_can_be_here (pMap, pPacman->ix, pPacman->iz + 1))
			{
				pPacman->iz++;
				set_bille_visibility (pBilles, pPacman->ix, pPacman->iz, score);
			}
			break;
		case GLUT_KEY_LEFT:
			if (map_can_be_here (pMap, pPacman->ix - 1, pPacman->iz))
			{
				pPacman->ix--;
				set_bille_visibility (pBilles, pPacman->ix, pPacman->iz, score);
			}
			break;
		case GLUT_KEY_RIGHT:
			if (map_can_be_here (pMap, pPacman->ix + 1, pPacman->iz))
			{
				pPacman->ix++;
				set_bille_visibility (pBilles, pPacman->ix, pPacman->iz, score);
			}
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
