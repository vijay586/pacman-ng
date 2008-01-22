#include <stdlib.h>
#include <GL/freeglut.h>
#include "opengl-render.h"
#include "glut-extra.h"

#define WIN_W 800
#define WIN_H 600

void cbExit (void);
void initPacman (void);
void initEvils (void);
void initMap (void);

int main (int argc, char *argv [])
{
	atexit (cbExit);
	glutInit (&argc, argv);
	initGlutWindow (WIN_W, WIN_H);
	initGlut ();
	return 0;
}

void initPacman ()
{
}

void initEvils ()
{
}

void initMap ()
{
}

void cbExit ()
{
	/* free your stuff here, we're exiting */
}
