#include <stdlib.h>
#include <GL/glut.h>

void init (void);
void cb_exit (void);
void resize (int width, int height);
void keyboard (unsigned char key, int x, int y);
void keyboard_special (int key, int x, int y);
void display (void);

int win_w = 800, win_h = 600;

int main (int argc, char *argv[])
{
	atexit (cb_exit);
	
	/* initialize glut */
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (win_w, win_h);
	glutInitWindowPosition (200, 20);
	glutCreateWindow ("Pacman");
	glutDisplayFunc (display);
	glutIdleFunc (display);
	glutReshapeFunc (resize);
	glutKeyboardFunc (keyboard);
	glutSpecialFunc (keyboard_special);
	init ();
	glutMainLoop ();

	return 0;
}

/* the display callback */
void display (void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	
	GLfloat mat_ambient [] = {0.7f, 0.7f, 0.7, 1.0f};
	GLfloat mat_diffuse [] = {0.6f, 0.6f, 0.6, 1.0f};
	GLfloat mat_specular [] = {1.0f, 1.0f, 1.0, 1.0f};
	GLfloat mat_shininess [] = {50};
	
	glMaterialfv (GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
	glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv (GL_FRONT, GL_SHININESS, mat_shininess);
	
	GLfloat lightIntensity [] = {0.7f, 0.7f, 1.0f, 1.0f};
	GLfloat light_position [] = {-0.0f, 6.0f, 3.0f, 0.0f};
	glLightfv (GL_LIGHT0, GL_POSITION, light_position);
	glLightfv (GL_LIGHT0, GL_DIFFUSE, lightIntensity);
	
	/* drawing */
	glColor3f (1.0, 1.0, 1.0);
	glPushMatrix ();
	glTranslatef (0.0, -1.0, -2.0);
	glutSolidSphere (0.5, 20, 20);
	glPopMatrix ();
	
	glutSwapBuffers ();
}

/* initialize opengl */
void init (void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_SMOOTH);
	glViewport (0, 0, win_w, win_h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective (45.0f, (GLfloat) win_w / (GLfloat) win_h, 1.0f, 1000.0f);
	glEnable (GL_DEPTH_TEST);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
}

/* called when window is resized */
void resize (int width, int height)
{
	win_w = width;
	win_h = height;
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport (0, 0, win_w, win_h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective (45.0f, (GLfloat) win_w / (GLfloat) win_h, 1.0f, 1000.0f);
	glutPostRedisplay ();
}

void keyboard (unsigned char key, int x, int y)
{
}

void keyboard_special (int key, int x, int y)
{
}

void cb_exit (void)
{
	/* free everything here */
}
