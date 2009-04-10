/**
 **  Colditz Maps Explorer
 **
 **  
 **
 **/

/** For glut, you need the dll in the exec location or system32
 ** and to compile, you need:
 ** - glut32.lib in C:\Program Files\Microsoft SDKs\Windows\v6.0A\Lib
 ** - glut.h in C:\Program Files\Microsoft SDKs\Windows\v6.0A\Include\gl 
 **
 ** The libs and header can be had from http://www.opengl.org/resources/libraries/glut/glutdlls37beta.zip
 **/
#include <stdio.h>
#include <stdlib.h>	
#include <string.h>
#include <math.h>

#if defined(WIN32)
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
// Tell VC++ to include the GL libs
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")
#elif defined(PSP)
#include <pspdebug.h>
#include <pspctrl.h>
#include <pspgu.h>
#include <psprtc.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "psp-setup.h"
#endif

#include "getopt.h"	
#include "colditz.h"
#include "low-level.h"
#include "utilities.h"


// Global variables

// Flags
int debug_flag				= 0;
int	opt_verbose				= 0;
int	opt_debug				= 0;
int opt_ghost				= 0;
int opt_play_as_the_safe	= 0;
// Force a specific sprite ID for our guy
int opt_sid					= -1;

// File stuff
FILE* fd					= NULL;
char* fname[NB_FILES]		= FNAMES;			// file name(s)
u32   fsize[NB_FILES]		= FSIZES;
u8*   fbuffer[NB_FILES];
u8*   mbuffer				= NULL;
u8*	  rgbCells				= NULL;

// OpenGL window size
int	gl_width, gl_height;
u8	prisoner_h = 0x23, prisoner_w = 0x10;
//int prisoner_x = 20, prisoner_2y = 20;
//int prisoner_x = 900, prisoner_2y = 600;
//int prisoner_x = 1339, prisoner_2y = 895;
//int prisoner_x = 0, prisoner_2y = 0;
int last_p_x = 0, last_p_y = 0;
int dx = 0, d2y = 0;
int jdx, jd2y;
u8	p_sid_base	 = 0x00;
// prisoner_run = 0x1F
// german_walk  = 0x37 (with rifle)
// german_run   = 0x57 (with rifle)
u8  prisoner_sid = 0x07; // 0x07;

// Could use a set of flags, but more explicit this way
bool key_down[256], key_readonce[256];
static __inline bool read_key_once(u8 k)
{	
	if (key_down[k])
	{
		if (key_readonce[k])
			return false;
		key_readonce[k] = true;
		return true;
	}
	return false;
}

bool reset_animations = true;
s_animation	animations[MAX_ANIMATIONS];
u8	nb_animations = 0;
u64 last_mtime;
s_guybrush guybrush[NB_GUYBRUSHES];
u8	props[NB_NATIONS][NB_PROPS];
u8	selected_prop[NB_NATIONS];
u8	nb_room_props = 0;
u16	room_props[NB_OBSBIN];
u8	over_prop = 0, over_prop_id = 0;
u8  current_nation = 0;
u8	panel_chars[NB_PANEL_CHARS][8*8*2];

//u16  current_room_index = ROOM_OUTSIDE;
u16  nb_rooms, nb_cells, nb_objects;
u8   palette_index = 4;
s_sprite*	sprite;
s_overlay*	overlay;
u8   overlay_index;
u8   bPalette[3][16];
// remapped Amiga Palette
u16  aPalette[16];
u32  rem_bitmask = 0x8000001E;

// offsets to sprites according to joystick direction (dx,dy)
int directions[3][3] = { {3,2,4}, {0,DIRECTION_STOPPED,1}, {6,5,7} };



/**
 ** GLUT event handlers
 **/
static void glut_init()
{
	// Use Glut to create a window
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA);
	glutInitWindowSize(gl_width, gl_height);
	glutInitWindowPosition(0, 0); 
	glutCreateWindow( __FILE__ );

	GLCHK(glShadeModel(GL_SMOOTH));		// set by default

	GLCHK(glMatrixMode(GL_PROJECTION));
	GLCHK(glLoadIdentity());
	// We'll set top left corner to be (0,0) for 2D
    GLCHK(glOrtho(0, PSP_SCR_WIDTH, PSP_SCR_HEIGHT, 0, -1, 1));
	GLCHK(glMatrixMode(GL_MODELVIEW));

	// Set our default viewport
	GLCHK(glViewport(0, 0, PSP_SCR_WIDTH, PSP_SCR_HEIGHT));

	// Setup transparency
	GLCHK(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
	GLCHK(glEnable(GL_BLEND));

	// Disable depth
	GLCHK(glDisable(GL_DEPTH_TEST));
	GLCHK(glEnable(GL_TEXTURE_2D));

	// Clear both buffers (this is needed on PSP)
	GLCHK(glClear(GL_COLOR_BUFFER_BIT));
	glutSwapBuffers();
	GLCHK(glClear(GL_COLOR_BUFFER_BIT));

	// Define the scissor area, outside of which we don't want to draw
//	GLCHK(glScissor(0,32,PSP_SCR_WIDTH,PSP_SCR_HEIGHT-32));
//	GLCHK(glEnable(GL_SCISSOR_TEST));

//	eglCreatePbufferSurface( null, null, null );

}


static void glut_display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	display_room();
	display_panel();
#if !defined (PSP)
	rescale_buffer();
#endif
	glutSwapBuffers();
}

// 
static void glut_reshape (int w, int h)
{
//	u32 gl_crop_width, gl_crop_height;

	gl_width=w;
	gl_height=h;
	
//	gl_crop_width = (32.0f * gl_width/PSP_SCR_WIDTH);
//	gl_crop_height = (16.0f * gl_height/PSP_SCR_HEIGHT);

	// Don't ask me why you need to use TWO scales of coordinates 
	// in the same formula to get the right amount of cropping
//	glScissor(32,32, (gl_width-32)-gl_crop_width,(gl_height-32));
//	glScissor(0,32, gl_width,(gl_height-32));

	glut_display();
}



/*
#if defined(WIN32)
#define KEY_FRAME 12
#else
#define KEY_FRAME 10
#endif
*/

void process_motion(void)
{
	u8 index;
	bool redisplay = false;
	int new_direction;
	int exit;

	// Increment animations framecounts
	if ((mtime() - last_mtime) > ANIMATION_INTERVAL)
	{
		last_mtime += ANIMATION_INTERVAL;	// closer to ideal rate
		// but leads to catchup effect when moving window
		for (index = 0; index < nb_animations; index++)
			animations[index].framecount++;
//		if  (nb_animations)
		// no point issuing a redisplay if there are no animations
			redisplay = true;
	}
	
	if ( (prisoner_state != STATE_STOP) && (prisoner_state != STATE_MOVE) )
	{	// prevent motion for all other
		dx=0;
		d2y=0;
	}

	// Check if we're allowed to go where we want
	if ((dx != 0) || (d2y != 0))
	{
		exit = check_footprint(dx*prisoner_speed, d2y*prisoner_speed);
		if (exit != -1)
		{	// if -1, we move normally
			// in all other cases, we need to stop (even on sucessful exit)
			if (exit>0)
			{
//				printf("exit[%d], from room[%X]\n", exit-1, current_room_index);
				switch_room(exit-1, dx, d2y);
				redisplay = true;
			}
			// Change the last direction so that we use the right sid for stopping
			animations[prisoner_ani].direction = directions[d2y+1][dx+1];
			dx = 0;
			d2y = 0;
		}
	}

	// Get direction (which is used as an offset to pick the proper animation
	new_direction = directions[d2y+1][dx+1];
	// NB: if d2y=0 & dx=0, new_dir = DIRECTION_STOPPED

	if (new_direction != DIRECTION_STOPPED)
	{	// We're moving => animate sprite

		if (prisoner_state == STATE_STOP)
		// we were stopped => make sure we start with the proper ani frame
			animations[prisoner_ani].framecount = 0;

		// Update our prisoner data
		prisoner_x += prisoner_speed*dx;
		prisoner_2y += prisoner_speed*d2y;
		prisoner_state = STATE_MOVE;
		// Update the animation direction
		animations[prisoner_ani].direction = new_direction;

		// Force a redisplay
		redisplay = true;

	}
	else if (prisoner_state == STATE_MOVE)
	{	// We just stopped
		prisoner_state = STATE_STOP;
		redisplay = true;
	}


	if (redisplay) 
		glut_display();
}

// restore guybrush & animation parameters after a one shot ani
// this function expects the guybrush index as well as the previous ani_index
// to be concatenated in the lower 2 bytes of the parameter
void restore_params(u32 param)
{
	u8 brush, ani, previous_index;
	// extract the guybrush index
	brush = param & 0xFF;
	// extract the previous animation index
	previous_index = (param >> 8) & 0xFF;

	ani = guybrush[brush].ani_index;
	animations[ani].index = previous_index;
	animations[ani].framecount = 0;
	animations[ani].end_of_ani_function = NULL;
	// we always end up in stopped state after a one shot animation
	guybrush[brush].state = STATE_STOP;
}

// process motion keys
static void glut_idle(void)
{	
	u16 prop_offset;
	u8	prop_id, direction;
//	int i;

	// Reset the motion
	dx = 0; 
	d2y = 0;	

#if !defined(PSP)
	if (key_down[27])
		exit(0);

	// Hey, GLUT, where's my bleeping callback on Windows?
	// NB: The routine is not called if there's no joystick
	//     and the force fumc does not exist on PSP
	glutForceJoystickFunc();	
#endif

	// Keyboard directions
	if ((key_down['4']) || (key_down['q']))
		dx = -1;
	else if ((key_down['6']) || (key_down['o']))
		dx = +1;
	if ((key_down['8']) || (key_down['d']))
		d2y = -1;
	else if ((key_down['2']) || (key_down['x']))
		d2y = +1;

	// Display our current position
	if (read_key_once('p'))
		printf("(px, p2y) = (%d, %d), room = %x, rem = %08X\n", prisoner_x, prisoner_2y, current_room_index, rem_bitmask);

	if (read_key_once(' '))
	{
		if (prisoner_speed == 1)
		{
			prisoner_speed = 2;
			animations[prisoner_ani].index = RUN_ANI; // +GERMAN OFFSET
			animations[prisoner_ani].framecount = 0;
		}
		else
		{
			prisoner_speed = 1;
			animations[prisoner_ani].index = WALK_ANI;
			animations[prisoner_ani].framecount = 0;
		}
	}

	// The following keys are only handled if we are in a premissible state
	if ((prisoner_state == STATE_STOP) || (prisoner_state == STATE_MOVE))
	{
		if ( (read_key_once(SPECIAL_KEY_LEFT)) ||
			 (read_key_once(SPECIAL_KEY_RIGHT)) ) 
		{
			prop_id = selected_prop[current_nation];
			direction = key_down[SPECIAL_KEY_LEFT]?0x0F:1;
			do
				prop_id = (prop_id + direction) & 0x0F;
			while ( (!props[current_nation][prop_id]) && (prop_id != selected_prop[current_nation]) );
			if (props[current_nation][prop_id])
			// we found a non empty item
				selected_prop[current_nation] = prop_id;
			else
				selected_prop[current_nation] = 0;
//			printf("selected prop = %02X\n", selected_prop[current_nation]);
		}


		// Props pickup/dropdown
		if ( (read_key_once(SPECIAL_KEY_DOWN)) ||
			 (read_key_once(SPECIAL_KEY_UP)) ) 
		{
			prisoner_state = STATE_PICK;
			// enqueue our 2 u8 parameters
			animations[prisoner_ani].end_of_ani_parameter = (PRISONER & 0xFF) | 
				((animations[prisoner_ani].index << 8) & 0xFF00);
			animations[prisoner_ani].index = KNEEL_ANI;
			//animations[prisoner_ani].index = SHOT_ANI;
			// starting at -1 ensures that we'll go through frame 0
			// as we need to wait the for the ani counter to increase
			// for our first animation frame to show
			animations[prisoner_ani].framecount = -1;
			animations[prisoner_ani].end_of_ani_function = restore_params;


			if (key_down[SPECIAL_KEY_UP])
			{	// picking up
				if (over_prop)
				{
//					over_prop--;	// restore the zero based index
					prop_offset = room_props[over_prop-1];
					room_props[over_prop-1] = 0;
					// change the room index to an invalid one
					writeword(fbuffer[OBJECTS],prop_offset,ROOM_NO_PROP);
//					prop_id = readbyte(fbuffer[OBJECTS],prop_offset+7);
//					prop_id = over_prop_id;
					props[current_nation][over_prop_id]++;
					selected_prop[current_nation] = over_prop_id;
//					for (i = 0; i< 16; i++)
//						printf(" %02X", props[current_nation][i]);
//					printf("\nselected prop = %02X\n", selected_prop[current_nation]);
				}
			}
			else
			{	// dropping down
				if (selected_prop[current_nation])
				{
//					prop_offset = room_props[over_prop];
					over_prop_id = selected_prop[current_nation];
					// OK, now we'll look for an picked object space in obs.bin to store 
					// our data
					for (prop_offset=2; prop_offset<(8*nb_objects+2); prop_offset+=8)
					{
						if (readword(fbuffer[OBJECTS],prop_offset) == ROOM_NO_PROP)
						{	// There should always be at least one
							// Add the prop to our current room
							room_props[nb_room_props] = prop_offset; 
							nb_room_props++;
							// Write down the relevant value in obs.bin
							// 1. Room number
							writeword(fbuffer[OBJECTS],prop_offset,current_room_index);
							// 2. x & y pos
							writeword(fbuffer[OBJECTS],prop_offset+4, prisoner_x + 15);
							writeword(fbuffer[OBJECTS],prop_offset+2, prisoner_2y/2 + 3);
							// 3. object id
							writeword(fbuffer[OBJECTS],prop_offset+6, over_prop_id);
							break;
						}
					}

					props[current_nation][over_prop_id]--;
//					over_prop = prop_id + 1;
					if (props[current_nation][over_prop_id] == 0)
					// display the empty box if last prop
						selected_prop[current_nation] = 0;
					// don't care to much about reconstructing over_prop, as the next redisplay
					// will take care of it
					over_prop = 0;
					over_prop_id = 0;
//					printf("selected prop = %02X\n", selected_prop[current_nation]);
				}
			}
		}
	}

	// Joystick motion overrides keys
	if (jdx)
		dx = jdx;
	if (jd2y)
		d2y = jd2y;

	process_motion();

	// Can't hurt to sleep a while if we're motionless, so that
	// we don't hammer down the CPU in a loop
	if ((dx == 0) && (d2y == 0))
		msleep(ANIMATION_INTERVAL/4);
}


static void glut_joystick(uint buttonMask, int x, int y, int z)
{
	// compute x and y displacements
	if (x>JOY_DEADZONE)
		jdx = 1;
	else if (x<-JOY_DEADZONE)
		jdx = -1;
	else 
		jdx = 0;
	if (y>JOY_DEADZONE)
		jd2y = 1;
	else if (y<-JOY_DEADZONE)
		jd2y = -1;
	else jd2y = 0;
}

// Keyboard handling
static void glut_keyboard(u8 key, int x, int y)
{
//	printf("key = %X\n", key);
	key_down[key] = true;
}

static void glut_keyboard_up(u8 key, int x, int y)
{
	key_down[key] = false;
	key_readonce[key] = false;
}

static void glut_special_keys(int key, int x, int y)
{
	key_down[key + SPECIAL_KEY_OFFSET] = true;
}

static void glut_special_keys_up(int key, int x, int y)
{
	key_down[key + SPECIAL_KEY_OFFSET] = false;
	key_readonce[key + SPECIAL_KEY_OFFSET] = false;
}
/*
	// just use the second part of our key table
	switch (key) 
	{
	case GLUT_KEY_UP:
	case GLUT_KEY_DOWN:
		if (key == GLUT_KEY_UP)
		{
			if (current_room_index == ROOM_OUTSIDE)
				current_room_index = 0;
			else if (current_room_index < (nb_rooms-1))
				current_room_index++;
		}			
		if (key == GLUT_KEY_DOWN)
		{
			if (current_room_index == 0)
				current_room_index = ROOM_OUTSIDE;
			else if (current_room_index != ROOM_OUTSIDE)
				current_room_index--;
		}
		// Refresh
		glut_display();
		break;
	case GLUT_KEY_RIGHT:
	case GLUT_KEY_LEFT:
		// Change palette
		if ((key == GLUT_KEY_RIGHT) && (palette_index<6))
			palette_index++;
		if ((key == GLUT_KEY_LEFT) && (palette_index!=0))
			palette_index--;
		// Because we can't *PROPERLY* work with 4 bit indexed colours 
		// in GLUT, we have to recreate the whole cells buffer!
		to_16bit_palette(palette_index);
		cells_to_wGRAB(fbuffer[CELLS],rgbCells);
		sprites_to_wGRAB();
		// Refresh
		glut_display();
		break;
	}
}
*/

/* Here we go! */
int main (int argc, char *argv[])
{

	// Flags
	int opt_skip			= 0;	// Skip TIFF Creation
	int opt_error 			= 0;	// getopt

	// General purpose
	u32  i;
	u8	g_ani;

	/*
     * Init
     */

#if defined(PSP)
	setup_callbacks();
	gl_width = PSP_SCR_WIDTH;
	gl_height = PSP_SCR_HEIGHT;
#else
	gl_width = 2*PSP_SCR_WIDTH;
	gl_height = 2*PSP_SCR_HEIGHT;
#endif

	// Initialize our timer value
	last_mtime = mtime();

	glutInit(&argc, argv);

	// Let's clean up our buffers
	fflush(stdin);
	mbuffer    = NULL;
	for (i=0; i<NB_FILES; i++)
		fbuffer[i] = NULL;

	// Process commandline options (works for PSP too with psplink)
	while ((i = getopt (argc, argv, "vbghs:")) != -1)
		switch (i)
	{
		case 'v':		// Print verbose messages
			opt_verbose = -1;
			break;
		case 'b':       // Debug mode
			opt_debug = -1;
			break;
		case 'g':		// walk through walls
			opt_ghost = -1;
			break;
		case 's':
			sscanf(optarg, ("%x"), &opt_sid); 
			break;
		case 'h':
		default:		// Unknown option
			opt_error++;
			break;
	}

	puts ("");
	puts ("Colditz v1.0 : Escape from Colditz port");
	puts ("by Aperture Software,  May 2009");
	puts ("");

	if ( ((argc-optind) > 3) || opt_error)
	{
		puts ("usage: Colditz [-f] [-s] [-v] [device] [kernel] [general]");
		puts ("Most features are autodetected, but if you want to specify options:");
		puts ("                -f : force");
		puts ("                -s : skip TIFF image creation");
		puts ("                -v : verbose");
		puts ("");
		exit (1);
	}

	// Need to have a working GL before we proceed
	glut_init();

	// Load the data
	load_all_files();

	// fix some of the files
	fix_files();

	// Set global variables
	get_properties();

	// Define our main prisoner
	guybrush[PRISONER].ani_index = 0;
	guybrush[PRISONER].px = 940;
	guybrush[PRISONER].p2y = 630;
//	guybrush[PRISONER].px = 404;
//	guybrush[PRISONER].p2y = 707;
	guybrush[PRISONER].room = ROOM_OUTSIDE;
	guybrush[PRISONER].state = STATE_STOP;
	guybrush[PRISONER].speed = 1;
	g_ani = guybrush[0].ani_index;
	animations[g_ani].index = WALK_ANI;
	animations[g_ani].framecount = 0;
	animations[g_ani].direction = 3;
	animations[g_ani].end_of_ani_function = NULL;
	nb_animations++;

	guybrush[1].ani_index = 1;
	guybrush[1].px = 1300;
	guybrush[1].p2y = 730;
	guybrush[1].room = ROOM_OUTSIDE;
	guybrush[1].state = STATE_MOVE;
	guybrush[1].speed = 2;
	g_ani = guybrush[1].ani_index;
	animations[g_ani].index = GER_WALK_ANI;
	animations[g_ani].framecount = 0;
	animations[g_ani].direction = 0;
	animations[g_ani].end_of_ani_function = NULL;
	nb_animations++;

	// We're going to convert the cells array, from 2 pixels per byte (paletted)
	// to on RGB(A) word per pixel
	rgbCells = (u8*) aligned_malloc(fsize[CELLS]*2*RGBA_SIZE, 16);
	if (rgbCells == NULL)
	{
		perr("Could not allocate RGB Cells buffers\n");
		ERR_EXIT;
	}

	// Get a palette we can work with
	to_16bit_palette(palette_index, 0xFF, PALETTES);

	// Convert the cells to RGBA data
	cells_to_wGRAB(fbuffer[CELLS],rgbCells);

	// Do the same for overlay sprites
	init_sprites();
	sprites_to_wGRAB();

	// Don't forget to set the room props
	set_room_props();
	for (i = 0; i<NB_NATIONS; i++)
		selected_prop[i] = 0;

	// Now we can proceed with our display
	glutDisplayFunc(glut_display);
	glutReshapeFunc(glut_reshape);

	glutKeyboardFunc(glut_keyboard);
	glutKeyboardUpFunc(glut_keyboard_up);
	glutSpecialFunc(glut_special_keys);
	glutSpecialUpFunc(glut_special_keys_up);

	glutJoystickFunc(glut_joystick,30);	
	// This is what you get from using obsolete libraries
	// bloody joystick callback doesn't work on Windows,
	// so we have to stuff the movement handling in idle!!!
	glutIdleFunc(glut_idle);

	glutMainLoop();

	return 0;
}
