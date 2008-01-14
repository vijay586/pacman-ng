#ifndef __WALL
#define __WALL

#include "global.h"

class wall {
	public:
		enum orientation { VERTICAL = 0, HORIZONTAL = 1 };

		point pos;
		orientation orient;
		float length;
		
		wall ();
		wall (point p, orientation o, float l);
		void draw ();
	
	private:
		float thickness;
		float height;
};

#endif
