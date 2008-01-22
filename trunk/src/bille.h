#ifndef __BILLE
#define __BILLE

#include "global.h"

struct _bille
{
	float fRadius, fx, fy, fz;
	boolean bVisible;
};

typedef struct _bille bille;

bille *newBille (float fRadius, float fx, float fy, float fz, boolean bv);
inline void bille_draw (bille *b);

#endif
