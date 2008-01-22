#ifndef __GROUND
#define __GROUND

struct _ground
{
	float fWidth, fHeight, fDepth;
};
typedef struct _ground ground;

ground *newGround (float fw, float fh, float fd);
inline void renderGround (ground *g);

#endif
