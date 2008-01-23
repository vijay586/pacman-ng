#include <GL/freeglut.h>
#include <stdio.h>

#include "text.h"

char scoreNum [5];

void gameOver(void)
{
	printf("game over\n");
}

void renderText(int score)
{	
	glColor3d (1, 1, 1);

	glRasterPos2i(420, 480);
	//glutBitmapString(GLUT_BITMAP_9_BY_15, "SCORE: ");
	glRasterPos2i(421, 480);
	//glutBitmapString(GLUT_BITMAP_9_BY_15, "SCORE: ");
	
	sprintf (scoreNum, "%d", score);
	glRasterPos2i(575, 480);
	//glutBitmapString(GLUT_BITMAP_9_BY_15, scoreNum);
}
