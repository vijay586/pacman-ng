/*
 * This file is part of pacman-ng
 * 
 * pacman-ng A 3D version of the pacman game
 * Copyright (C) 2008	Frederic-Gerald Morcos (fredmorcos)
 * 						Marleine Mounir Daoud
 * 						Andrew Botros Boktor
 * 
 * pacman-ng is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * pacman-ng is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with pacman-ng.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include "SDL.h"
#include "SDL_opengl.h"

#include "opengl-render.h"

// man pacman, man2;
// bille billes;
// wall w1, w2;
// int animation_running;
// GLfloat light_intensity [] = {1.0, 1.0, 1.0, 0.0 };
// GLfloat light_position [] = {0.0, 2.0, 9.0, 1.0};

#define WIN_W 800;
#define WIN_H 600;

int main (int argc, char *argv [])
{
	int winWidth = WIN_W;
	int winHeight = WIN_H;
	
	SDL_Surface *pSurfaceWindow = NULL;
	SDL_Event event;
	
	short isRunning = 1;
	
	/* init SDL */
	if ((SDL_Init (SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1))
	{
		printf ("Could not initialize SDL: %s.\n", SDL_GetError ());
		exit (-1);
	}
	
	SDL_WM_SetCaption ("Pacman NG", "../images/icon.gif");
	SDL_GL_SetAttribute (SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute (SDL_GL_DOUBLEBUFFER, 1);
	
    if (!(pSurfaceWindow = SDL_SetVideoMode (winWidth, winHeight, 16, 
    		SDL_HWSURFACE | SDL_HWPALETTE | SDL_RESIZABLE | SDL_OPENGL)))
    {
    	printf ("Couldn't open SDL-window: %s\n", SDL_GetError ());
    	exit (-2);
    }
    
    while (isRunning)
    {
    	SDL_PollEvent (&event);
    	switch (event.type)
    	{
    		case SDL_QUIT:
    			isRunning = 0;
    			break;
    		case SDL_KEYDOWN:
    			if (event.key.keysym.sym == SDLK_ESCAPE || event.key.keysym.sym == SDLK_q)
    				isRunning = 0;
    			else if (event.key.keysym.sym == SDLK_p)
    				printf ("You Pressed P!!!\n");
    	}
    	
    	SDL_Delay (50);
    }
    
    /* free your cairo and other stuff here, we are quitting */
    SDL_Quit ();
	return 0;
}

/*
void set_bille_visibility (void)
{
	if(	billes.points.z <= pacman.pos.z + pacman.radius && 
		billes.points.z >= pacman.pos.z - pacman.radius && 
		billes.points.x >= pacman.pos.x - pacman.radius &&
		billes.points.x <= pacman.pos.x + pacman.radius	)
			billes.visible = FALSE;
}

void keyboard (unsigned char key, int x, int y)
{
}

void keyboard_special (int key, int x, int y)
{
	if ( key == GLUT_KEY_UP )
	{
		pacman.velocity [0] = 0;
		pacman.velocity [2] = -1;
	}
	else if ( key == GLUT_KEY_DOWN )
	{
		pacman.velocity [0] = 0;
		pacman.velocity [2] = 1;
	}
	else if ( key == GLUT_KEY_LEFT )
	{
		pacman.velocity [0] = -1;
		pacman.velocity [2] = 0;
	}
	else if ( key == GLUT_KEY_RIGHT )
	{
		pacman.velocity [0] = 1;
		pacman.velocity [2] = 0;
	}
}
*/
