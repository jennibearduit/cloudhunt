// -----------------------------------------------------------------------------
// LIBRARIES LOADER & INITIALIZATION FUNCTIONS
// -----------------------------------------------------------------------------

// ===================== Load all custom header files =====================
#include "gba.h" 							// GBA memory addresses library
#include "sprites.h"						// Color palettes and sprites
#include "globalvariables.h"			// Global use variables
#include "button.h"						// Button inputs
#include "projectiles.h"				// Projectile functions
#include "swarms.h"						// Swarm boss functions
#include "weaponry.h"					// Cannon and railgun functions
#include "levels.h"						// Level progresson and status
#include "displaymodes.h"				// Static displays
#include "math.h"							// Geometric functions
// ========================================================================


// -------------------- Fill RNG Seed (Initializer) --------------------
void fillRNG(void)
{
    int i;
	 // Fill the RNG array for projectiles
    for (i = 0; i < 16; i++)
        rng_seed[i]=(rand() % (5)) + 1;
}

// -------------------- Fill Color Palette (Initializer) --------------------
void fillPalette(void)
{
    int     i;

	// Fill the palette in GBA memory
    for (i = 0; i < NCOLS; i++)
        spritePal[i] = palette[i];
}

// -------------------- Draw All Sprite (Initializer) --------------------
void fillSprites(void)
{
    int     i;

	// Load all sprites in GBA memory
    for (i = 0; i < 128*16*16; i++)
        spriteData[i] = (sprites[i*2+1] << 8) + sprites[i*2];

	// draw all sprites on screen, but all of them outside of the screen (starting at position (240,160) the bottom right corner of the GBA screen)
    for(i = 0; i < 128; i++)
        drawSprite(0, i, DUMP_X,DUMP_Y);
}

// -------------------- Draw Sprite --------------------
void drawSprite(int numb, int N, int x, int y)
{
	// Same as CA2, make specific sprite (based on its name/numb) appear on screen, as slide number N (each sprite needs a different, arbitrary, N >= 0)
    *(unsigned short *)(0x7000000 + 8*N) = y | 0x2000;
    *(unsigned short *)(0x7000002 + 8*N) = x | 0x4000;
    *(unsigned short *)(0x7000004 + 8*N) = numb*8;
}

