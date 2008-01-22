#include <GL/freeglut.h>
#include <stdlib.h>

#include "global.h"
#include "man.h"

man *newMan (float fRadius, float fx, float fy, float fz, boolean bevil)
{
	man *temp = calloc (1, sizeof (man));
	temp->fRadius = fRadius;
	temp->fx = fx;
	temp->fy = fy;
	temp->fz = fz;
	temp->bevil = bevil;
	return temp;

}

void man_draw (man *m)
{
	glPushMatrix ();
	if (m->bevil)
		glColor3f (1.0, 0.0, 0.0);
	else
		glColor3f (1.0, 1.0, 0.0);
	
	glTranslatef (m->fx, m->fy+m->fRadius, m->fz);
	glutSolidSphere (m->fRadius, 100, 100);
	glPopMatrix ();
}

void man_move (man *m)
{
	m->fx += m->svelocity [0] * 0.05;;
	m->fy += m->svelocity [1] * 0.05;;
	m->fz += m->svelocity [2] * 0.05;;
}
