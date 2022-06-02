// -----------------------------------------------------------------------------
// DRONE BOSS SWARM
// -----------------------------------------------------------------------------

// -------------------- Blowing Swarm Time Handler --------------------
void blowSwarmHandler(void)
{
    if (blowing_swarm_st==false){return;} // activation check

    if (tick_cmd>=swarm_blow_tf) // finish time check
    {
        dumpSwarm(SPRITE_SWARM_IDX); // remove one health from swarm
        reformSwarm(SPRITE_SWARM_IDX); // reduce swarm size

        drawSprite(RELOAD, (SPRITE_CNN1_IDX-1), CNN1_X, CNN1_Y); // railgun RELOAD overlay
        drawSprite(RAILGUN_A_RLD, SPRITE_CNNX_IDX, (CNN1_X-16), CNN1_Y); // railgun Reloading
        drawSprite(RAILGUN_B_RLD, SPRITE_CNN1_IDX, CNN1_X, CNN1_Y); // railgun Reloading
        resetBeam(); // remove beam

        blowing_swarm_st = false; // reset flag
    }
}

// -------------------- Draw Swarm --------------------
int makeSwarm(int num_drone_fleet) {
	int row_counter = 0;
	int drone_space_x = 18;
	int middle_row = 66;
	int drone_space_y = middle_row;
	
	int i = 0;
	for (i; i < boss_health; i++) { //make first half of fleet, start making from the middle row
		
		while (row_counter != (boss_health - i)){
			drawSprite(13, num_drone_fleet, row_counter * drone_space_x, drone_space_y);
			row_counter++;
			num_drone_fleet++;
		}
		row_counter = 0;
		drone_space_y = drone_space_y - 22;
	}

	drone_space_y = middle_row;
	i = i - 1;
	for (i; i > 0; i--) { //make second half of fleet
		drone_space_y = drone_space_y + 22;
		while (row_counter != i){
			drawSprite(DRONE, num_drone_fleet, row_counter * drone_space_x, drone_space_y);
			row_counter++;
			num_drone_fleet++;
		}
		row_counter = 0;
	}
	return num_drone_fleet;
}

// -------------------- Explode Swarm --------------------
int explodeSwarmRow(int num_drone_fleet) {
	int rows = 7;
	int drone_space_x = 18;
	int middle_row = 66;

	int i = 0;
	int j = 0;
	int k = 0;
	for (i; i < boss_health; i++) { //triangle sequence generator
		j += 1;
		k += j;
	}
	
	k = k - 1;
	i = 0;
	for (i; i < boss_health; i++) { //gets the proper index of the middle row
		drawSprite(EXPLOSION,  num_drone_fleet, i * drone_space_x, middle_row);
		num_drone_fleet = num_drone_fleet + 1;
	}
}

// -------------------- Dump Swarm --------------------
void dumpSwarm(int num_drone_fleet) {
	int total_drones = boss_health * boss_health; //square function

	int i = 0;
	for (i; i < total_drones; i++) {
		drawSprite(0, num_drone_fleet + i, 240, 160);
	}
}

// -------------------- Reform Swarm --------------------
void reformSwarm(int num_drone_fleet) {
	boss_health = boss_health - 1;
	makeSwarm(num_drone_fleet);
}

