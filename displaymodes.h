// -----------------------------------------------------------------------------
// DISPLAYS
// -----------------------------------------------------------------------------

// -------------------- BLANK Display --------------------
void clearDisplay(void)
{
	int i;
	for (i = 0; i < 128; i++) 
	{
		drawSprite(0,i,DUMP_X,DUMP_Y);
	}
}

// -------------------- "CLOUDHUNT" Title Display --------------------
void initialDisplay(void) 
{	
	// ROW 1 DISPLAY
	int idx = 0;
	int x = 9;
	int y = 40;
	drawSprite(CLOUD_B, idx++, (x++)*10, y);
	x += 2;
	drawSprite(CLOUD_C, idx++, (x++)*10, y);
	x += 2;
	drawSprite(CLOUD_A, idx++, (x++)*10, y);

	// ROW 2 DISPLAY
	x = 5;
	y = 70;
	drawSprite(CLOUD_B, idx++, (x++)*10, y);
	x += 2;
	drawSprite(LETTER_C, idx++, (x++)*10, y);
	drawSprite(LETTER_L, idx++, (x++)*10, y);
	drawSprite(LETTER_O, idx++, (x++)*10, y);
	drawSprite(LETTER_U, idx++, (x++)*10, y);
	drawSprite(LETTER_D, idx++, (x++)*10, y);
	drawSprite(LETTER_H, idx++, (x++)*10, y);
	drawSprite(LETTER_U, idx++, (x++)*10, y);
	drawSprite(LETTER_N, idx++, (x++)*10, y);
	drawSprite(LETTER_T, idx++, (x++)*10, y);
	x++;
	drawSprite(CLOUD_A, idx++, (x++)*10, y);	
	
	// ROW 3 DISPLAY
	x = 9;
	y = 100;
	drawSprite(CLOUD_B, idx++, (x++)*10, y);
	x += 2;
	drawSprite(CLOUD_C, idx++, (x++)*10, y);
	x += 2;
	drawSprite(CLOUD_A, idx++, (x++)*10, y);
}

// -------------------- "YOU WIN" Text Display --------------------
void winDisplay(void)
{
	int idx = SPRITE_TEXT_IDX;
	int x = 8;
	int y = 80;
	drawSprite(LETTER_Y, idx++, (x++)*10, y);
	drawSprite(LETTER_O, idx++, (x++)*10, y);
	drawSprite(LETTER_U, idx++, (x++)*10, y);
	x++;
	drawSprite(LETTER_W, idx++, (x++)*10, y);
	drawSprite(LETTER_I, idx++, (x++)*10, y);
	drawSprite(LETTER_N, idx++, (x++)*10, y);
}

// -------------------- "YOU LOSE" Text Display --------------------
void loseDisplay(void) 
{
	int idx = SPRITE_TEXT_IDX;
	int x = 8; 
	int y = 80;
	drawSprite(LETTER_Y, idx++, (x++)*10, y);
	drawSprite(LETTER_O, idx++, (x++)*10, y);
	drawSprite(LETTER_U, idx++, (x++)*10, y);
	x++;
	drawSprite(LETTER_D, idx++, (x++)*10, y);
	drawSprite(LETTER_I, idx++, (x++)*10, y);
	drawSprite(LETTER_E, idx++, (x++)*10, y);
	drawSprite(LETTER_D, idx++, (x++)*10, y);
}

// -------------------- "LEVEL 2" Text Display --------------------
void level2Display(void) 
{
	int idx = SPRITE_TEXT_IDX;
	int x = 8;
	int y = 80;
	drawSprite(LETTER_L, idx++, (x++)*10, y);
	drawSprite(LETTER_E, idx++, (x++)*10, y);
	drawSprite(LETTER_V, idx++, (x++)*10, y);
	drawSprite(LETTER_E, idx++, (x++)*10, y);
	drawSprite(LETTER_L, idx++, (x++)*10, y);
	x++;
	drawSprite(NUMBER_2, idx++, (x++)*10, y);
}

// -------------------- "LEVEL 3" Text Display --------------------
void level3Display(void) 
{
	int idx = SPRITE_TEXT_IDX;
	int x = 8;
	int y = 80;
	drawSprite(LETTER_L, idx++, (x++)*10, y);
	drawSprite(LETTER_E, idx++, (x++)*10, y);
	drawSprite(LETTER_V, idx++, (x++)*10, y);
	drawSprite(LETTER_E, idx++, (x++)*10, y);
	drawSprite(LETTER_L, idx++, (x++)*10, y);
	x++;
	drawSprite(NUMBER_3, idx++, (x++)*10, y);
}

// -------------------- Level 1 & 2 Draw --------------------
void drawStaticObjectsLvlNorm(void)
{
    drawSprite(CANNON_LEFT, SPRITE_CNN1_IDX, CNN1_X, CNN1_Y);
    drawSprite(CANNON_UP, SPRITE_CNN2_IDX, CNN2_X, CNN2_Y);
    drawSprite(CANNON_UP, SPRITE_CNN3_IDX, CNN3_X, CNN3_Y);
    drawSprite(CANNON_DOWN, SPRITE_CNN4_IDX, CNN4_X, CNN4_Y);
    drawSprite(CANNON_DOWN, SPRITE_CNN5_IDX, CNN5_X, CNN5_Y);
    makeShip(SPRITE_SHIP_IDX);
    makeCloud();
    makeFullHealth();
}

// -------------------- Level 3 Draw --------------------
void drawStaticObjectsLvlBoss(void)
{
    drawSprite(RAILGUN_A, SPRITE_CNNX_IDX, (CNN1_X-16), CNN1_Y);
    drawSprite(RAILGUN_B, SPRITE_CNN1_IDX, CNN1_X, CNN1_Y);
    drawSprite(CANNON_UP, SPRITE_CNN2_IDX, CNN2_X, CNN2_Y);
    drawSprite(CANNON_UP, SPRITE_CNN3_IDX, CNN3_X, CNN3_Y);
    drawSprite(CANNON_DOWN, SPRITE_CNN4_IDX, CNN4_X, CNN4_Y);
    drawSprite(CANNON_DOWN, SPRITE_CNN5_IDX, CNN5_X, CNN5_Y);
    makeShip(SPRITE_SHIP_IDX);
    makeFullHealth();
    makeCloud();
    makeSwarm(SPRITE_SWARM_IDX);
}

// -------------------- Ship Draw --------------------
void makeShip(int num_init) {
//    *(unsigned short *)(0x5000000) = RGB(10,22,25);
	int length = 15;
   int num_idx = 0;
   int num_spt = num_init;
	while (num_idx < 9) {
			drawSprite(RAILS_UP, num_spt, (240 - length * num_idx), 53);
			num_idx++; num_spt++;
	}
	while (num_idx < 18) {
			drawSprite(RAILS_DOWN, num_spt, (240 - length * (num_idx - 9)), 85);
			num_idx++; num_spt++;
	}
	while (num_idx < 27) {
			drawSprite(BOAT_BASE, num_spt, (240 - length * (num_idx - 18)), 69);
			num_idx++; num_spt++;
	}
	drawSprite(RAILS_UP_NARROWER, num_spt, (240 - length * (num_idx - 18)), 53);
	drawSprite(BOAT_BASE, (num_spt+1), (240 - length * (num_idx - 18)), 69);
	drawSprite(RAILS_DOWN_NARROWER, (num_spt+2), (240 - length * (num_idx - 18)), 85);
	num_idx++;
	drawSprite(RAILS_UP_NARROWEST, (num_spt+3), (240 - length * (num_idx - 18)), 53);
	drawSprite(BOAT_BASE, (num_spt+4), (240 - length * (num_idx - 18)+9), 69);
	drawSprite(RAILS_DOWN_NARROWEST, (num_spt+5), (240 - length * (num_idx - 18)), 85);
}

// -------------------- Full Health Draw --------------------
void makeFullHealth()
{
    drawSprite(LIFE, SPRITE_HEALTH_IDX, 192, 0);
    drawSprite(LIFE, SPRITE_HEALTH_IDX+1, 208, 0);
    drawSprite(LIFE, SPRITE_HEALTH_IDX+2, 224, 0);
}

// -------------------- Cloud Background Draw --------------------
void makeCloud()
{
    int idx = SPRITE_CLOUD_IDX;
    drawSprite(CLOUD_C, idx++, 22, 137);
    drawSprite(CLOUD_A, idx++, 28, 63);
    drawSprite(CLOUD_B, idx++, 47, 20);
    drawSprite(CLOUD_A, idx++, 62, 94);
    drawSprite(CLOUD_B, idx++, 102, 135);
    drawSprite(CLOUD_C, idx++, 116, 15);
    drawSprite(CLOUD_A, idx++, 157, 118);
    drawSprite(CLOUD_B, idx++, 190, 23);
    drawSprite(CLOUD_C, idx++, 218, 134);
}
