#ifndef __WALL
#define __WALL

#include "global.h"

#define WALL_THICKNESS 0.3;
#define WALL_HEIGHT 1.0;

class wall {
	public:
		enum orientation { VERTICAL = 0, HORIZONTAL = 1 };

		point pos;
		orientation orient;
		float length;
		
		wall ();
		wall (point p, orientation o, float l);
		void draw ();
};

#endif
