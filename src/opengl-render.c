#include "opengl-render.h"
#include <GL/freeglut.h>

void renderOpenGL ()
{
	glClear (GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity (); 
	glutSwapBuffers ();
}

void initOpenGL ()
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
//	glDisable (GL_DITHER);
	glDisable (GL_NORMALIZE);
	glEnable (GL_COLOR_MATERIAL);
	glEnable (GL_TEXTURE_RECTANGLE_ARB);
	glEnable (GL_LIGHTING);
	glEnable (GL_LIGHT0);
	glEnable (GL_DEPTH_TEST);
	glDepthFunc (GL_LESS);
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	glViewport (0, 0, win_w, win_h);
//	glMatrixMode (GL_PROJECTION);
//	glLoadIdentity ();
	gluPerspective ( 45.0, 1.0, 1.0f, 20.0f);
//	gluLookAt ( 0.0, 2.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 ); 
	
	/* set the light */
	GLfloat light_intensity [] = {1.0, 1.0, 1.0, 0.0 };
	GLfloat light_position [] = {0.0, 2.0, 9.0, 1.0};
	glLightfv (GL_LIGHT0, GL_POSITION, light_position);	
	glLightfv (GL_LIGHT0, GL_DIFFUSE, light_intensity);
	
	/* set the material color */
	GLfloat mat_ambient [] = {1.0, 1.0, 1.0, 1.0};
	GLfloat mat_specular [] = {1.0, 1.0, 1.0, 1.0};
	GLfloat mat_shininess [] = {90.0};
	glMaterialfv (GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
	glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv (GL_FRONT, GL_SHININESS, mat_shininess);
}

