#include "glut-extra.h"

#include <GL/freeglut.h>
#include "opengl-render.h"

void initGlutWindow (int iWidth, int iHeight)
{
	glutInitWindowSize (iWidth, iHeight);
	glutInitWindowPosition ((glutGet (GLUT_SCREEN_WIDTH) - iWidth) / 2, 
							(glutGet (GLUT_SCREEN_HEIGHT) - iHeight) / 2);
	glutCreateWindow ("Pacman NG");
}
