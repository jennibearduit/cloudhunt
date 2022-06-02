// -----------------------------------------------------------------------------
// LEVEL PROGRESSION
// -----------------------------------------------------------------------------

// -------------------- Draw Player --------------------
void movePlayer(void)
{
    if(st_mode==2) drawSprite(hero, SPRITE_PLAYER_IDX, p_x, p_y);
}

// -------------------- Health Updater --------------------
void reduceShipHealth(void)
{
    // decrement ship health
    ship_health-=1;

    // update heart health display according to ship health
    switch (ship_health)
    {
        case 0:
            drawSprite(0, SPRITE_HEALTH_IDX+2, DUMP_X, DUMP_Y); //dump heart 3
            break;
        case 1:
            drawSprite(HALF_LIFE, SPRITE_HEALTH_IDX+2, 224, 0); //half heart 3
            break;
        case 2:
            drawSprite(0, SPRITE_HEALTH_IDX+1, DUMP_X, DUMP_Y); //dump heart 2
            break;
        case 3:
            drawSprite(HALF_LIFE, SPRITE_HEALTH_IDX+1, 208, 0); //half heart 3
            break;
        case 4:
            drawSprite(0, SPRITE_HEALTH_IDX, DUMP_X, DUMP_Y); //dump heart 1
            break;
        case 5:
            drawSprite(HALF_LIFE, SPRITE_HEALTH_IDX, 192, 0); //half heart 3
            break;
    }
}

// -------------------- Page Navigation Handler --------------------
void pageNavigationHandler(void)
{
   // Frequency control to prevent multiple input
   if ((tick_cmd-button_delay)>=BUTTON_DELAY)
	{
      button_delay = tick_cmd; // udpate frequency control

    	// Displaying "CLOUDHUNT" -> start level 1
    	if (st_level == 0 && st_status == 0) 
    	{
    		clearDisplay(); // clear display
    		st_level = 1; // increment level
    		st_mode = 1; // toggle to load mode
    		st_status = 0; // defensive code
         needToUpdateLevel=true; // trigger game algorithm's state handler
    		return;
    	}

    	// Displaying "YOU WIN" -> Display "LEVEL 2"
    	if (st_level == 1 && st_status == 1) 
    	{
    		clearDisplay(); // clear display
    		level2Display(); // print "LEVEL 2"
    		st_level = 2; // increment level
    		st_status = 0; // re-set status
    		return;
    	}

    	// Displaying "LEVEL 2" -> start level 2
    	if (st_level == 2 && st_status == 0) 
    	{
         st_mode = 1; // toggle to load mode
         needToUpdateLevel=true; // update game algorithm's state
    		return;
    	}

    	// Displaying "YOU WIN" -> Display "LEVEL 3"
    	if (st_level == 2 && st_status == 1) 
    	{
    		clearDisplay(); // clear display
    		level3Display(); // print "LEVEL 3"
    		st_level = 3; // increment level
    		st_status = 0; // re-set status
    		return;
    	}

      // Displaying "LEVEL 3" -> start level 3
    	if (st_level == 3 && st_status == 0) 
    	{
         st_mode = 1; // toggle to load mode
         needToUpdateLevel=true; // update game algorithm's state
    		return;
    	}

    	// Level 3 Win Display or Lose Display -> Go To HomeScreen
    	if ((st_level == 3 && st_status == 1) || st_status == 2)
    	{
    		clearDisplay();
    		initialDisplay();
    		st_level = 0;
    		st_mode = 0;
    		st_status = 0;
    		return;
    	}
    }
}

// -------------------- Level Handler --------------------
void levelHandler()
{
    if (needToUpdateLevel==false||st_mode==0){return;} //activation check and guard clause
    
    // LEVEL 1 PROGRESS TREE
    if (st_level==1)
    {
        level1ProgressTree();
    }
    // LEVEL 2 PROGRESS TREE
    else if (st_level==2)
    {
        level2ProgressTree();
    }
    // LEVEL 3 PROGRESS TREE
    else if (st_level==3)
    {
        level3ProgressTree();
    }
}

// -------------------- Level 1 Progress Tree --------------------
void level1ProgressTree()
{
    // Case when level 1 has started
    if(st_mode==2)
    {
        // If ship health is zero, you died
        if (ship_health<=0)
        {
            clearDisplay(); //clear display
            loseDisplay(); //print "YOU DIED"
            st_mode = 0; //set mode to 'display'
            st_status = 2; //set status to 'lose'
            resetLevel(); //reset level variables to prevent further update
        }

        // If rocket count is not yet reached, shoot next rocket
        else if (proj_cnt<LVL1_RKT_CNT)
        {
            randProjectile(); //shoot next rocket
        }

        // Level has been cleared, you win
        else
        {
            clearDisplay(); //clear display
            winDisplay(); //print "YOU WIN"
            st_mode = 0; //set mode to 'display'
            st_status = 1; //set status to 'win'
            resetLevel(); //reset level variables to prevent further update
        }
        needToUpdateLevel = false; //reset flag
    }

    // Case when level 1 has not started: draw level and start
    else if(st_mode==1)
    {
        // define the form of projectiles
        proj1_form = ROCKET_RIGHT;
        proj2_form = ROCKET_DOWN;
        proj3_form = ROCKET_DOWN;
        proj4_form = ROCKET_UP;
        proj5_form = ROCKET_UP;

        // set all cannon to 'alive'
        cnn1_stat=1;
        cnn2_stat=1;
        cnn3_stat=1;
        cnn4_stat=1;
        cnn5_stat=1;

        // set rocket speed
        proj_spd = PROJ_SPEED_1;

        ship_health = MAX_HEALTH; //reset health to full
        proj_cnt = 0; //reset rocket count to zero
        st_mode=2; //set status to 'game'
        needToUpdateLevel = true; //set update flag

        clearDisplay(); //clear display
        drawStaticObjectsLvlNorm(); //draw level
    }
}

// -------------------- Level 2 Progress Tree --------------------
void level2ProgressTree()
{
    // Case when level 2 has started
    if(st_mode==2)
    {
        // If ship health is zero, you died
        if (ship_health<=0)
        {
            clearDisplay(); //clear display
            loseDisplay(); //print "YOU DIED"
            st_mode = 0; //set mode to 'display'
            st_status = 2; //set status to 'lose'
            resetLevel(); //reset level variables to prevent further update
        }

        // If rocket count is not yet reached, shoot next rocket
        else if (proj_cnt<LVL2_RKT_CNT)
        {
            randProjectile(); //shoot next rocket
        }

        // Level has been cleared, you win
        else
        {
            clearDisplay(); //clear display
            winDisplay(); //print "YOU WIN"
            st_mode = 0; //set mode to 'display'
            st_status = 1; //set status to 'win'
            resetLevel(); //reset level variables to prevent further update
        }
        needToUpdateLevel = false; // reset flag
    }

    // Case when level 2 has not started: draw level and start
    else if(st_mode==1)
    {
        // define the form of projectiles
        proj1_form = DRONE;
        proj2_form = DRONE;
        proj3_form = DRONE;
        proj4_form = DRONE;
        proj5_form = DRONE;

        // set all cannon to 'alive'
        cnn1_stat=1;
        cnn2_stat=1;
        cnn3_stat=1;
        cnn4_stat=1;
        cnn5_stat=1;

        // set rocket speed
        proj_spd = PROJ_SPEED_2;

        ship_health = MAX_HEALTH; //reset health to full
        proj_cnt = 0; //reset rocket count to zero
        st_mode=2; //set status to 'game'
        needToUpdateLevel = true;

        clearDisplay(); //clear display
        drawStaticObjectsLvlNorm(); //draw level
    }
}

// -------------------- Level 3 Progress Tree --------------------
void level3ProgressTree()
{
    // Case when level 3 has started
    if(st_mode==2)
    {
        // If ship health is zero, you died
        if (ship_health<=0)
        {
            clearDisplay(); //clear display
            loseDisplay(); //print "YOU DIED"
            st_mode = 0; //set mode to 'display'
            st_status = 2; //set status to 'lose'
            resetLevel(); //reset level variables to prevent further update
        }

        // If boss is still alive, shoot next rocket
        else if (boss_health>0)
        {
            randProjectile(); //shoot next rocket
        }

        // Level has been cleared, you win
        else
        {
            clearDisplay(); //clear display
            winDisplay(); //print "YOU WIN"
            st_mode = 0; //set mode to 'display'
            st_status = 1; //set status to 'win'
            resetLevel(); //reset level variables to prevent further update
        }
        needToUpdateLevel = false; // reset flag
    }

    // Case when level 3 has not started: draw level and start
    else if(st_mode==1)
    {
        // define the form of projectiles
        // projectile index 1 is not used due to swarm boss
        proj2_form = DRONE;
        proj3_form = DRONE;
        proj4_form = DRONE;
        proj5_form = DRONE;

        // set all cannon to 'alive'
        cnn1_stat=1;
        cnn2_stat=1;
        cnn3_stat=1;
        cnn4_stat=1;
        cnn5_stat=1;
        railgun_stat=1;

        // set rocket speed
        proj_spd = PROJ_SPEED_2;

        ship_health = MAX_HEALTH; //reset health to full
        boss_health = BOSS_MAX_HEALTH; //reset boss health to full
        proj_cnt = 0; //reset rocket count to zero
        st_mode=2; //set status to 'game'
        needToUpdateLevel = true;

        clearDisplay(); //clear display
        drawStaticObjectsLvlBoss(); //draw level
    }
}

// -------------------- Reset Level Variables --------------------
void resetLevel(void)
{
    cnn1_stat=1;
    cnn2_stat=1;
    cnn3_stat=1;
    cnn4_stat=1;
    cnn5_stat=1;
    railgun_stat=1;
    blowing_proj_st=false;
    blowing_swarm_st=false;
}
