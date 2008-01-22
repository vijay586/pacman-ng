#include "glut-extra.h"

#include <GL/freeglut.h>
#include "opengl-render.h"

void initGlutWindow (int iWidth, int iHeight, int *pMainWindow, int *pTopViewWindow)
{
	glutInitWindowSize (iWidth, iHeight);
	glutInitWindowPosition ((glutGet (GLUT_SCREEN_WIDTH) - iWidth) / 2, 
							(glutGet (GLUT_SCREEN_HEIGHT) - iHeight) / 2);
	*pMainWindow = glutCreateWindow ("Pacman NG");
	*pTopViewWindow = glutCreateSubWindow (*pMainWindow, 0, 0, 200, 150);
}
