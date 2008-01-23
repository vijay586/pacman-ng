#include "ground.h"

#include <GL/freeglut.h>
#include <stdlib.h>
#include "global.h"

inline void renderGround (ground *g)
{
	glEnable (GL_TEXTURE_2D);
	glPushMatrix ();
	glColor3d (0, 1, 0);
	glTranslated (0, -(g->iHeight), 0);
	glScaled (g->iWidth * CELL_SIZE, g->iHeight, g->iDepth * CELL_SIZE);
	glutSolidCube (1);
	glBindTexture (GL_TEXTURE_2D, g->uiTextureId);
	glBegin (GL_QUADS);
	glTexCoord3i (-1, 1, -1);	glVertex3i (-1, 1, -1);
	glTexCoord3i (1, 1, -1);	glVertex3i (1, 1, -1);
	glTexCoord3i (1, 1, 1);		glVertex3i (1, 1, 1);
	glTexCoord3i (-1, 1, 1);	glVertex3i (-1, 1, 1);
	glEnd ();
	glPopMatrix ();
	glDisable (GL_TEXTURE_2D);
}

ground *newGround (int iw, int ih, int id)
{
	ground *temp = calloc (1, sizeof (ground));
	temp->iWidth = iw;
	temp->iHeight = ih;
	temp->iDepth = id;
	
	temp->uiTextureId = textureFile ("images/floor.raw", 128, 128);
	
	return temp;
}
