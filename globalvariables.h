// -----------------------------------------------------------------------------
// GLOBAL VARS
// -----------------------------------------------------------------------------

//-------------------- GAME STATUS VARIABLES --------------------
int st_level = 0; 						// Level  0: start -- Level 1 - 3: game
int st_mode = 0; 							// Mode   0: display -- Mode 1: load -- Mode 2: game
int st_status = 0; 						// Status 0: pending -- Status 1 = win -- Status 2 = lose
bool needToUpdateLevel = false;		// flag | true: check and update current level progress

//-------------------- TIME KEEPING --------------------
int tick_sec = 0;							// second tick counter
int tick_cmd = 0;							// cmd tick counter
int button_delay = 0;					// 'S' button input timeholder

int proj_blow_tf = 0; 					// blown rocket finish tick
int swarm_blow_tf = 0; 					// blown swarm finish tick
int cnn1_repair_tf = 0;					// Cannon 1 repair finish tick
int cnn2_repair_tf = 0;					// Cannon 2 repair finish tick
int cnn3_repair_tf = 0;					// Cannon 3 repair finish tick
int cnn4_repair_tf = 0;					// Cannon 4 repair finish tick
int cnn5_repair_tf = 0;					// Cannon 5 repair finish tick
int railgun_reload_tf = 0;				// Railgun Reload finish tick

//-------------------- PLAYER ATTRIBUTES --------------------
int hero = HERO_FRONT;					// hero sprite type ( there are 4 orientations )
float float_p_x = INIT_PLAYER_X;		// hero pos X ( true float value )
float float_p_y = INIT_PLAYER_Y;		// hero pos Y ( true float value )
int p_x = INIT_PLAYER_X;				// hero pos X ( rounded int value )
int p_y = INIT_PLAYER_Y;				// hero pos Y ( rounded int value )

//-------------------- PROJECTILE ATTRIBUTES --------------------
int proj_actv = 0;	 					// [0]: deactivated -- [1-5]: active projectile index

int proj1_form = 0;   					// projectile 1 sprite type
int proj2_form = 0;   					// projectile 2 sprite type
int proj3_form = 0;   					// projectile 3 sprite type
int proj4_form = 0;   					// projectile 4 sprite type
int proj5_form = 0;   					// projectile 5 sprite type

float proj_x_flt = DUMP_X;				// projectile pos X ( true float value )
float proj_y_flt = DUMP_Y;				// projectile pos Y ( true float value )
int proj_x = DUMP_X;						// projectile pos X ( rounded int value )
int proj_y = DUMP_Y;						// projectile pos X ( rounded int value )

int proj_cnt = 0; 						// number of projectile shot at current level
float proj_spd = 0;						// projectile speed

int blowing_proj_id = 0;				// blowing projectile index
bool blowing_proj_st = false;			// flag | true: projectile is blown & not yet reset

//-------------------- RNG ATTRIBUTES --------------------
int rng_seed[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 		// 16 values projectile index sequence
int rng_idx = 0;														// pointer to rng_seed's current index

//-------------------- BOSS ATTRIBUTES --------------------
int boss_health = BOSS_MAX_HEALTH;	// health of swarm boss
bool blowing_swarm_st = false;		// flag | true: swarm is blown & not yet reset

//-------------------- SHIP ATTRIBUTES --------------------
int ship_health = MAX_HEALTH;			// health of ship
int shot_cnn = 0; 						// activated cannon index

int cnn1_stat = 1; 						// Cannon 1 Status 0: dead -- 1: alive -- 2: repairing
int cnn2_stat = 1; 						// Cannon 2 Status 0: dead -- 1: alive -- 2: repairing
int cnn3_stat = 1; 						// Cannon 3 Status 0: dead -- 1: alive -- 2: repairing
int cnn4_stat = 1; 						// Cannon 4 Status 0: dead -- 1: alive -- 2: repairing
int cnn5_stat = 1; 						// Cannon 5 Status 0: dead -- 1: alive -- 2: repairing
int railgun_stat = 1; 					// Railgun  Status 0: reloading -- 1: ready
