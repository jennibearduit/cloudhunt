//  ========================================================================  //
//                                                                            // 
//           ###  #     ###   #   #  ###   #  #  #   #  #  #  #####           //
//          #     #    #   #  #   #  #  #  ####  #   #  ## #    #             //
//          #     #    #   #  #   #  #  #  #  #  #   #  # ##    #             //
//           ###  ###   ###    ###   ###   #  #   ###   #  #    #             //
//                                                                            //
//                                                                            //
//                                                                            //
//         ***                                                 ***            //
//      ***   *                    Credits:                  **   **          //
//     *       *                                            *       *         //
//      *******                    Jennifer                  *******          //
//                                 Josianne                                   //
//                                  Andrew                                    //
//                                                                            //
//  ========================================================================  //


// -----------------------------------------------------------------------------
// C-Skeleton to be used with HAM Library from www.ngine.de
// -----------------------------------------------------------------------------
#include <stdbool.h>
#include "constants.h"
#include "mygbalib.h"

// -----------------------------------------------------------------------------
// Assembly Functions
// -----------------------------------------------------------------------------
//extern int getNextRocket(u32 curr_rkt, u32 seed);
extern int isLessThan(u32 num1, u32 num2);
extern int modulo16(u32 num);

// -----------------------------------------------------------------------------
// Exeption Handler
// -----------------------------------------------------------------------------
void Handler(void)
{
    REG_IME = 0x00; // Stop all other interrupt handling, while we handle this current one

    if ((REG_IF & INT_TIMER2) == INT_TIMER2)	// Do every 15.6 ms :
    {
        checkbutton();									// Check button input
        movePlayer();									// Move player
        moveProjectile();								// Move projectiles
    }

    if ((REG_IF & INT_TIMER1) == INT_TIMER1)	// Do every 0.25 s :
    {
        tick_cmd++;										// Increment cmd tick counter
        checkDamageProjectile();						// Check if any projectile has damaged the ship
    }

    if ((REG_IF & INT_TIMER0) == INT_TIMER0)	// Do every 1.00 s :
    {
        tick_sec++;										// Increment sec tick counter
        levelHandler();									// Handle level-relate update
        cannonHandler();								// Handle cannon-related update
        railgunHandler();								// Handle railgun-related update
        blowProjectileHandler();						// Handle blown projectile-related update
        blowSwarmHandler();							// Handle blown swarm-related update
    }

    REG_IF = REG_IF; // Update interrupt table, to confirm we have handled this iterrupt
    
    REG_IME = 0x01;  // Re-enable interrupt handling
}


// -----------------------------------------------------------------------------
// MAIN 
// -----------------------------------------------------------------------------
int main(void)
{
    // Set Mode 2
    *(unsigned short *) 0x4000000 = 0x40 | 0x2 | 0x1000;
    
    // Set Background Color (Sky Blue)
    *(unsigned short *)(0x5000000) = RGB(16,22,25);

    // Fill Palette & Sprite
    fillPalette();
    fillSprites();

    // Fill RNG Seed for Projectile Use
    fillRNG();

    // Initialize with home display "CLOUDHUNT"
    initialDisplay();

    // Set Handler Function for interrupts and enable selected interrupts
    REG_INT = (int)&Handler;
    // Choose which interrupts to enable
    REG_IE |= INT_TIMER0 | INT_TIMER1 | INT_TIMER2 | INT_BUTTON; 

    // Set Timer Modes
    // 1s Timer (Handler Refresh Rate's Period)
    REG_TM0D = -0x4000;																		// Set timer initial value
    REG_TM0CNT = TIMER_INTERRUPTS | TIMER_FREQUENCY_1024 | TIMER_ENABLE;	// Set timer frequency and enable timer
    // 0.25s Timer (Low-priority Process Refresh Rate's Period)
    REG_TM1D = -0x4000;																		// Set timer initial value
    REG_TM1CNT = TIMER_INTERRUPTS | TIMER_FREQUENCY_256 | TIMER_ENABLE;	   // Set timer frequency and enable timer
    // 15.6ms Timer (High-priority Process Refresh Rate's Period)
    REG_TM2D = -0x4000;																		// Set timer initial value
    REG_TM2CNT = TIMER_INTERRUPTS | TIMER_FREQUENCY | TIMER_ENABLE;      	// Set timer frequency and enable timer

    REG_IME = 0x1;

    while(1);

	 return 0;
}

