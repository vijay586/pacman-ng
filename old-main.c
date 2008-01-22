man pacman, man2;
bille billes;
wall w1, w2;

void set_bille_visibility (void)
{
	if(	billes.points.z <= pacman.pos.z + pacman.radius && 
		billes.points.z >= pacman.pos.z - pacman.radius && 
		billes.points.x >= pacman.pos.x - pacman.radius &&
		billes.points.x <= pacman.pos.x + pacman.radius	)
			billes.visible = FALSE;
}

void display (void)
{
	gluLookAt (pacman.pos.x, pacman.pos.y + 4.0, pacman.pos.z + 4.0, 
				pacman.pos.x, pacman.pos.y, pacman.pos.z, 
				0.0, 1.0, 0.0 );
	
	/* drawing here! */
	man_draw (&pacman);
	man_draw (&man2);
	bille_draw(&billes);
	
	wall_draw (&w1);
	wall_draw (&w2);
}

void init (void)
{	
	pacman.pos.x = 0.0;
	pacman.pos.y = 0.1;
	pacman.pos.z = 1.5;
	pacman.radius = 0.1;
	pacman.evil = FALSE;
	pacman.velocity [0] = 0;
	pacman.velocity [1] = 0;
	pacman.velocity [2] = 0;

	man2.pos.x = 0.0;
	man2.pos.y = 0.1;
	man2.pos.z = -1.0;
	man2.radius = 0.1;
	man2.evil = TRUE;
	man2.velocity [0] = 0;
	man2.velocity [1] = 0;
	man2.velocity [2] = 0;
	
	billes.points.x = 0.0;
	billes.points.y = 0.1;
	billes.points.z = -2.5;
	billes.radius = 0.05;
	billes.visible = TRUE;

	//============= ANDREW'S TESTING CODE DON'T REMOVE ================
	
	w1.pos.x = 0;
	w1.pos.y = 0;
	w1.pos.z = 0;
	w1.orient = HORIZONTAL;
	w1.length = 4;
	
	w2.pos.x = 0;
	w2.pos.y = 0;
	w2.pos.z = 0;
	w2.orient = VERTICAL;
	w2.length = 2;
	
	//========== END OF ANDREW'S TESTING CODE DON'T REMOVE ============
}


/* called when window is resized */
void resize (int width, int height)
{
	win_w = width;
	win_h = height;
	glViewport (0, 0, win_w, win_h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective (45.0f, (GLfloat) win_w / (GLfloat) win_h, 1.0f, 20.0f);
	glutPostRedisplay ();
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
