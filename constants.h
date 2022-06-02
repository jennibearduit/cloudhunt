// -----------------------------------------------------------------------------
// CONSTANTS
// -----------------------------------------------------------------------------

//-------------------- Movement Speeds --------------------
#define WALK_SPEED 	0.031 //(pixel/15.6ms) player walking speed
#define PROJ_SPEED_1 0.009 //(pixel/15.6ms) projectile speed 1
#define PROJ_SPEED_2 0.018 //(pixel/15.6ms) projectile speed 2

//-------------------- Positioning & Borders --------------------
#define INIT_PLAYER_X 112 	//player initial pos X
#define INIT_PLAYER_Y 75   //player initial pos Y

#define INIT_PROJ_N_Y 0    //projectile starting Y at north
#define INIT_PROJ_S_Y 144	//projectile starting Y at sount
#define INIT_PROJ_W_X 0		//projectile starting X at west

#define CNN1_X 96		//cannon 1 pos X
#define CNN1_Y 68		//cannon 1 pos Y
#define CNN2_X 130	//cannon 2 pos X
#define CNN2_Y 48		//cannon 2 pos Y
#define CNN3_X 175	//cannon 3 pos X
#define CNN3_Y 48		//cannon 3 pos Y
#define CNN4_X 130	//cannon 4 pos X
#define CNN4_Y 90		//cannon 4 pos Y
#define CNN5_X 175	//cannon 5 pos X
#define CNN5_Y 90		//cannon 5 pos Y
#define CNN0_X 133 	//railgun pos X
#define CNN0_Y 72 	//railgun pos Y

#define SHIP_UPPER_X 185	//player movement limit at east
#define SHIP_LOWER_X 111	//player movement limit at west
#define SHIP_UPPER_Y 78		//player movement limit at south
#define SHIP_LOWER_Y 53		//player movement limit at north

#define DUMP_X 240 	//dump position for all inactive sprites
#define DUMP_Y 160 	//dump position for all inactive sprites

//-------------------- Time control delays --------------------
#define CNN_REPAIR 4 		//(x 1s) cannon repair time
#define RAILGUN_RELOAD 7 	//(x 1s) railgun reload time
#define BUTTON_DELAY 2 		//(x 0.25s) delay to prevent multiple same 'S' button input
#define BLOW_DELAY 3 		//(x 0.25s) projectile blow time before reset

//-------------------- Level Configurations --------------------
#define MAX_HEALTH 60 		//maximum health of the ship
#define LVL1_RKT_CNT 8 		//number of rockets to be fired in level 1
#define LVL2_RKT_CNT 12 	//number of rockets to be fired in level 2
#define BOSS_MAX_HEALTH 4 	//total health of swarm (level 3 boss)

//-------------------- Sprite Number Allocation --------------------
// reserve 0 for debug purposes
// For Display Mode
#define SPRITE_TEXT_IDX 	1 		//1-128 for text & clouds
// For Game Mode
#define SPRITE_CNN5_IDX 	2 		//2 for Cannon 2 | 1 for overlay
#define SPRITE_CNN4_IDX 	4 		//4 for Cannon 4 | 3 for overlay
#define SPRITE_PLAYER_IDX 	5 		//5 for player
#define SPRITE_CNN3_IDX 	7 		//7 for Cannon 3 | 6 for overlay
#define SPRITE_CNN2_IDX 	9 		//9 for Cannon 2 | 8 for overlay
#define SPRITE_CNN1_IDX 	11 	//11 for Cannon 1 | 10 for overlay
#define SPRITE_CNNX_IDX 	12 	//12 for Railgun
#define SPRITE_EXPL_IDX 	13 	//13 for EXPLOSION
#define SPRITE_PROJ_IDX 	14 	//14-19 for projectiles
#define SPRITE_HEALTH_IDX 	19  	//19-21 for health
#define SPRITE_SWARM_IDX 	22 	//22-51 for boss swarm
#define SPRITE_SHIP_IDX 	52 	//52-84 for ship
#define SPRITE_BEAM_IDX 	85 	//85-89 for railgun beam
#define SPRITE_CLOUD_IDX	90		//90-128 for cloud background

//-------------------- Other Constants --------------------
#define INTERACT_DISTANCE 3 //interact distance between player and object
#define P 19 		//for capital letter sprites
#define A 23 		//for cloud sprites
#define B 24 		//for cloud sprites
#define C 25 		//for cloud sprites
#define D 19 		//for cloud sprites
