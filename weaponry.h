// -------------------- Cannon Repair Handler --------------------
void cannonHandler(void)
{
    /* If the cannon finish repair time is reached, do:
     * - set cannon status to 'alive'
     * - dump repair overlay sprite
     */

    if ((cnn1_stat==2)&&(tick_sec>=cnn1_repair_tf))
    {
        cnn1_stat=1;
        drawSprite(REPAIR, (SPRITE_CNN1_IDX-1), DUMP_X, DUMP_Y);
    }
    if ((cnn2_stat==2)&&(tick_sec>=cnn2_repair_tf))
    {
        cnn2_stat=1;
        drawSprite(REPAIR, (SPRITE_CNN2_IDX-1), DUMP_X, DUMP_Y);
    }
    if ((cnn3_stat==2)&&(tick_sec>=cnn3_repair_tf))
    {
        cnn3_stat=1;
        drawSprite(REPAIR, (SPRITE_CNN3_IDX-1), DUMP_X, DUMP_Y);
    }
    if ((cnn4_stat==2)&&(tick_sec>=cnn4_repair_tf))
    {
        cnn4_stat=1;
        drawSprite(REPAIR, (SPRITE_CNN4_IDX-1), DUMP_X, DUMP_Y);
    }
    if ((cnn5_stat==2)&&(tick_sec>=cnn5_repair_tf))
    {
        cnn5_stat=1;
        drawSprite(REPAIR, (SPRITE_CNN5_IDX-1), DUMP_X, DUMP_Y);
    }
}

// -------------------- Subfunction - Button A: Shoot Railgun --------------------
void shootRailgun(void)
{
    if(railgun_stat!=1){return;} // guard clause if railgun is 'reloading'

    drawBeam(); // draw railgun beam

    railgun_stat = 0; // set railgun status to 'reloading'
    railgun_reload_tf = tick_sec+RAILGUN_RELOAD; // set railgun reload finish time

    blowing_swarm_st = true; // activate blowSwarmHandler timer
    swarm_blow_tf = tick_cmd+BLOW_DELAY; // set finish time of blow
    explodeSwarmRow(SPRITE_SWARM_IDX); // explode swarm
}

// -------------------- Railgun Beam Draw --------------------
void drawBeam(void)
{
    // draw railgun beam from left to right
    int i = 0;
    int x = 0;
    while (i < 5) 
    {
        drawSprite(LASER_BEAM, (SPRITE_BEAM_IDX+i), x, CNN1_Y);
        x+=16;
		  i++;
	 }
}

// -------------------- Railgun Beam Dump --------------------
void resetBeam(void)
{
    // DUMP all railgun beam sprites
    int i = 0;
    int x = 0;
    while (i < 5)
    {
        drawSprite(LASER_BEAM, (SPRITE_BEAM_IDX+i), DUMP_X, DUMP_Y);
        x+=16;
		  i++;
	 }
}

// -------------------- Railgun Reload Handler --------------------
void railgunHandler(void)
{
    if ((railgun_stat==0)&&(tick_sec>=railgun_reload_tf)) // finish time check
    {
        railgun_stat=1; // set railgun stat to 'ready'
        drawSprite(0, (SPRITE_CNN1_IDX-1), DUMP_X, DUMP_Y); // DUMP cannon 1 overlay
        drawSprite(RAILGUN_A, SPRITE_CNNX_IDX, (CNN1_X-16), CNN1_Y); // railgun ready
        drawSprite(RAILGUN_B, SPRITE_CNN1_IDX, CNN1_X, CNN1_Y); // railgun ready
    }
}
