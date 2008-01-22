#ifndef __GROUND
#define __GROUND

struct _ground
{
	unsigned char *pucTextureBitmap;
	float fWidth, fHeight, fDepth;
};
typedef struct _ground ground;

ground *newGround (float fW, fH, fD);
void renderGround (ground *g);

#endif
