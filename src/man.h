#ifndef __MAN
#define __MAN

#include "global.h"

struct _man
{
	float fRadius, fx, fy, fz;
	boolean bevil;
	short svelocity [3];
};

typedef struct _man man;

man *newMan (float fRadius, float fx, float fy, float fz, boolean bevil);

inline void man_draw (man *m);
void man_move (man *m);

#endif
