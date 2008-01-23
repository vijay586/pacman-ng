#include "texture.h"

#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>
#include "global.h"

unsigned int textureFile (const char *pcFile, int iWidth, int iHeight)
{
	unsigned int uiTexture;
	
	GLubyte *data;
	FILE *file;

	file = fopen (pcFile, "rb");
	if (file == NULL) return 0;

	data = malloc (3 * iWidth * iHeight);

	fread (data, iWidth * iHeight * 3, 1, file);
	fclose (file);

	glGenTextures (1, &uiTexture);
	glBindTexture (GL_TEXTURE_2D, uiTexture);
	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D (GL_TEXTURE_2D, 0, GL_RGB, iWidth, iHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glTexEnvf (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	//gluBuild2DMipmaps (GL_TEXTURE_2D, 3, iWidth, iHeight, GL_RGB, GL_UNSIGNED_BYTE, data);
	free (data);

	return uiTexture;
}
