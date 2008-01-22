#ifndef __MAN
#define __MAN

#include "global.h"

struct _man
{
	float fx, fy, fz;
	boolean bEvil;
};
typedef struct _man man;

man *newMan (float fx, float fy, float fz, boolean be);

inline void renderMan (man *m);
// void man_move (man *m);

#endif
