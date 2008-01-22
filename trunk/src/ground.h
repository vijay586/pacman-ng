#ifndef __GROUND
#define __GROUND

struct _ground
{
	unsigned char *pucTextureBitmap;
	float fWidth, fHeight, fDepth;
};
typedef struct _ground ground;

void renderGround (ground *g);

#endif
