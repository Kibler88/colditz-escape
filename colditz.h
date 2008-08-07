#ifndef _COLDITZ_H
#define _COLDITZ 1

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef _WIN32
// Disable the _CRT_SECURE_DEPRECATE warnings
#pragma warning(disable:4996)
#endif

// Define our msleep function
#ifdef _WIN32
//#include <Windows.h>
#define msleep(msecs) Sleep(msecs)
#else
#include <unistd.h>
#define	msleep(msecs) usleep(1000*msecs)
#endif

#if __APPLE__
#include <inttypes.h>
#define u8  uint8_t
#define u16 uint16_t
#define u32 uint32_t
#else // ! __APPLE__
#ifndef u8
#define u8 unsigned char
#endif
#ifndef u16
#define u16 unsigned short
#endif
#ifndef u32
#define u32 unsigned long
#endif
#endif // __APPLE__

// Some fixes for windows
#if (_WIN32 || __MSDOS__)
#define NULL_FD fopen("NUL", "w")
#else
#define NULL_FD fopen("/dev/null", "w")
#endif

// Handy macro for exiting. xbuffer or fd = NULL is no problemo 
// (except for lousy Visual C++, that will CRASH on fd = NULL!!!!)
#define FREE_BUFFERS	{int _buf; for (_buf=0;_buf<NB_FILES;_buf++) free(fbuffer[_buf]); free(mbuffer);}
#define ERR_EXIT		{FREE_BUFFERS; if (fd != NULL) fclose(fd); fflush(stdin); exit(1);}
// The infamous Linux/DOS stdin fix
#define FLUSHER			{while(getchar() != 0x0A);}


// # files we'll be dealing with
#define NB_FILES			7
// Some handy identifier to make code reader friendly
#define ROOMS				0
#define CELLS				1
#define PALETTES			2
#define LOADER				3
#define COMPRESSED_MAP      4
#define SPRITES             5
#define OBJECTS				6
#define RED                 0
#define GREEN               1
#define BLUE                2
// Never be short on filename sizes
#define NAME_SIZE			256			
#define FNAMES				{ "COLDITZ_ROOM_MAPS", "COLDITZ_CELLS", "PALS.BIN", "COLDITZ-LOADER",\
							  "COMPRESSED_MAP", "SPRITES.SPR", "OBS.BIN" }
#define FSIZES				{ 58828, 135944, 232, 56080, \
							  33508, 71056, 2056 }
#define ALT_LOADER          "SKR_COLD"
#define ALT_LOADER_SIZE		28820
#define OFFSETS_START		0x2684
#define ROOMS_START			0x2FE4
#define CM_TILES_START      0x5E80
// tiles that need overlay, from LOADER
#define SPECIAL_TILES_START 0x3EBA
#define NB_SPECIAL_TILES	0x16
#define OBS_TO_SPRITE_START	0x5D02
#define NB_OBS_TO_SPRITE	15
#define LOADER_DATA_START	0x10C
#define FFs_TO_IGNORE		7
#define MAX_OVERLAY         0x80

// Define a structure to hold the RGBA sprites
typedef struct
{
    u16 w;
	u16 h;
	GLenum type;
	u8* data;
} s_sprite;

typedef struct
{
	int x;
	int y;
	u8 sid;
} s_overlay;


// Global variables
extern int	opt_verbose;
extern int	opt_debug;
extern int	stat;
extern int  debug_flag;
extern u8   *mbuffer;
extern u8   *fbuffer[NB_FILES];
extern FILE *fd;
extern u8   *rgbCells;


// Data specific global variables
extern u16  nb_rooms, nb_sprites, nb_objects;

extern char* fname[NB_FILES];
extern u32   fsize[NB_FILES];
extern int	gl_off_x, gl_off_y;
extern int	gl_width, gl_height;

extern u16  current_room_index;
extern s_sprite		*sprite;
extern s_overlay	*overlay; 
extern u8   overlay_index;

// Having  a global palette will save us a lot of hassle
extern u8 bPalette[3][16];


#ifdef	__cplusplus
}
#endif


#endif /* _COLDITZ */