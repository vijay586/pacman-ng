#ifndef __GROUND
#define __GROUND

struct _ground
{
	int iWidth, iHeight, iDepth;
};
typedef struct _ground ground;

ground *newGround (int iw, int ih, int id);
inline void renderGround (ground *g);

#endif
