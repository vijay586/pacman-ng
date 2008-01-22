#include <GL/freeglut.h>
#include <stdlib.h>

#include "global.h"
#include "man.h"

man *newMan (float fx, float fy, float fz, boolean be)
{
	man *temp = calloc (1, sizeof (man));
	temp->fx = fx;
	temp->fy = fy;
	temp->fz = fz;
	temp->bEvil = be;
	
	return temp;
}

void renderMan (man *m)
{
	glPushMatrix ();
	if (m->bEvil)
		glColor3d (1, 0, 0);
	else
		glColor3d (1, 1, 0);
	
	glTranslatef (m->fx, m->fy + (CELL_SIZE / 2), m->fz);
	glutSolidSphere (CELL_SIZE / 2, 50, 50);
	glPopMatrix ();
}

/*
void man_move (man *m)
{
	m->fx += m->svelocity [0] * 0.05;
	m->fy += m->svelocity [1] * 0.05;
	m->fz += m->svelocity [2] * 0.05;
}
*/
