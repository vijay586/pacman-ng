#include "glut-extra.h"

#include <GL/freeglut.h>
#include "opengl-render.h"

void cbKeyboard (unsigned char ucKey, int iX, int iY);
void cbKeyboardSpecial (int iKey, int iX, int iY);

void initGlutWindow (int iWidth, int iHeight)
{
	glutInitWindowSize (iWidth, iHeight);
	glutInitWindowPosition ((glutGet (GLUT_SCREEN_WIDTH) - iWidth) / 2, 
							(glutGet (GLUT_SCREEN_HEIGHT) - iHeight) / 2);
	glutCreateWindow ("Pacman NG");
}

void initGlut ()
{
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_ACCUM | GLUT_DEPTH);
	glutDisplayFunc (renderOpenGL);
//	glutIdleFunc (renderOpenGL);
//	glutReshapeFunc (resize);
	glutKeyboardFunc (cbKeyboard);
	glutSpecialFunc (cbKeyboardSpecial);
	
	glutMainLoop ();
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
