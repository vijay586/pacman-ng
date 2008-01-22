#include "opengl-render.h"
#include <GL/freeglut.h>

void renderOpenGL ()
{
	glClear (GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	
	gluLookAt (0.0, 4.0, -15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void initOpenGL (float fWidth, float fHeight)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glDisable (GL_DITHER);
	glDisable (GL_NORMALIZE);
	glEnable (GL_COLOR_MATERIAL);
	glEnable (GL_TEXTURE_RECTANGLE_ARB);
	glEnable (GL_LIGHTING);
	//glEnable (GL_LIGHT0);
	//glEnable (GL_LIGHT1);
	//glEnable (GL_LIGHT2);
	glEnable (GL_LIGHT3);
	glEnable (GL_DEPTH_TEST);
	glDepthFunc (GL_LESS);
//	glEnable (GL_BLEND);
//	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glViewport (0, 0, fWidth, fHeight);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();

	gluPerspective ( 45.0, fWidth / fHeight, 1.0f, 100.0f);
	
	/* set the light */
	GLfloat light_intensity0 [] = {1.0, 1.0, 1.0, 0.0 };
	GLfloat light_position0 [] = {5.0, 10.0, 5.0, 0.0};
	glLightfv (GL_LIGHT0, GL_POSITION, light_position0);	
	glLightfv (GL_LIGHT0, GL_DIFFUSE, light_intensity0);
	
	GLfloat light_intensity1 [] = {1.0, 1.0, 1.0, 0.0 };
	GLfloat light_position1 [] = {-5.0, 10.0, 5.0, 0.0};
	glLightfv (GL_LIGHT1, GL_POSITION, light_position1);	
	glLightfv (GL_LIGHT1, GL_DIFFUSE, light_intensity1);
	
	GLfloat light_intensity2 [] = {1.0, 1.0, 1.0, 0.0 };
	GLfloat light_position2 [] = {-5.0, 10.0, -5.0, 0.0};
	glLightfv (GL_LIGHT2, GL_POSITION, light_position2);	
	glLightfv (GL_LIGHT2, GL_DIFFUSE, light_intensity2);
	
	GLfloat light_intensity3 [] = {1.0, 1.0, 1.0, 0.0 };
	GLfloat light_position3 [] = {0.0, 0.0, 10.0, 0.0};
	glLightfv (GL_LIGHT3, GL_POSITION, light_position3);	
	glLightfv (GL_LIGHT3, GL_DIFFUSE, light_intensity3);
	
	/* set the material color */
	GLfloat mat_ambient [] = {1.0, 1.0, 1.0, 1.0};
	GLfloat mat_specular [] = {1.0, 1.0, 1.0, 1.0};
	GLfloat mat_shininess [] = {90.0};
	glMaterialfv (GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
	glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv (GL_FRONT, GL_SHININESS, mat_shininess);
}

