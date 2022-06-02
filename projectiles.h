// -----------------------------------------------------------------------------
// PROJECTILE FUNCTIONS
// -----------------------------------------------------------------------------

// -------------------- Randomize Projectile --------------------
void randProjectile(void)
{
    // Get projectile index from seed
    int cur_proj_rng = rng_seed[rng_idx];

    // For boss level ONLY: force index 1 -> index 5
    if(cur_proj_rng==1&&st_level==3){cur_proj_rng = 5;}

    // Draw projectile
    drawProjectile(cur_proj_rng);

    // Increment projectile count
    proj_cnt+=1;

    // Increment rng pointer, reset to 0 if over-index
    rng_idx+=1;
    if(modulo16(rng_idx)==0) rng_idx=0;
//    if(rng_idx>15) rng_idx=0;
}

// -------------------- Set & Draw Projectile --------------------
void drawProjectile(int proj_idx)
{
    // activate projectile according the index
    proj_actv = proj_idx;

    // initialize start position of projectile
    switch(proj_actv) 
    {
        case 1:
            proj_x_flt = INIT_PROJ_W_X;
            proj_y_flt = CNN1_Y;
            break;

        case 2:
            proj_x_flt = CNN2_X;
            proj_y_flt = INIT_PROJ_N_Y;
            break;

        case 3:
            proj_x_flt = CNN3_X;
            proj_y_flt = INIT_PROJ_N_Y;
            break;

        case 4:
            proj_x_flt = CNN4_X;
            proj_y_flt = INIT_PROJ_S_Y;
            break;

        case 5:
            proj_x_flt = CNN5_X;
            proj_y_flt = INIT_PROJ_S_Y;
            break;
    }

    proj_x = (int)proj_x_flt; // update integer position X
    proj_y = (int)proj_y_flt; // update integer position Y
}

// -------------------- Move Projectile --------------------
void moveProjectile(void)
{
    switch(proj_actv)
    {
        case 1:
            //move projectile 1xPROJ_SPEED right
            drawSprite(proj1_form, SPRITE_PROJ_IDX, proj_x, proj_y);
            proj_x_flt+=proj_spd;
            proj_x = (int)proj_x_flt;
            break;

        case 2:
            //move projectile 1xPROJ_SPEED down
            drawSprite(proj2_form, (SPRITE_PROJ_IDX+1), proj_x, proj_y);
            proj_y_flt+=proj_spd;
            proj_y = (int)proj_y_flt;
            break;

        case 3:
            //move projectile 1xPROJ_SPEED down
            drawSprite(proj3_form, (SPRITE_PROJ_IDX+2), proj_x, proj_y);
            proj_y_flt+=proj_spd;
            proj_y = (int)proj_y_flt;
            break;

        case 4:
            //move projectile 1xPROJ_SPEED up
            drawSprite(proj4_form, (SPRITE_PROJ_IDX+3), proj_x, proj_y);
            proj_y_flt-=proj_spd;
            proj_y = (int)proj_y_flt;
            break;

        case 5:
            //move projectile 1xPROJ_SPEED up
            drawSprite(proj5_form, (SPRITE_PROJ_IDX+4), proj_x, proj_y);
            proj_y_flt-=proj_spd;
            proj_y = (int)proj_y_flt;
            break;
    }
}

// -------------------- Check Projectile Damage --------------------
void checkDamageProjectile(void)
{
    /* If the projectile hit the corresponsinng cannon, do:
     * - deactivate projectile
     * - dump projectile sprite
     * - reduce ship health
     * - set cannon status to 'dead'
     * - draw FIRE overlay on cannon
     */

    if (proj_actv==1&&proj_x>=(CNN1_X-16))
    {
        proj_actv = 0;
        resetProjectile(SPRITE_PROJ_IDX);
        reduceShipHealth();
        cnn1_stat = 0;
        drawSprite(FIRE, (SPRITE_CNN1_IDX-1), CNN1_X, CNN1_Y); // FIRE overlay
    }
    else if (proj_actv==2&&proj_y>=(CNN2_Y-16))
    {
        proj_actv = 0;
        resetProjectile(SPRITE_PROJ_IDX+1);
        reduceShipHealth();
        cnn2_stat = 0;
        drawSprite(FIRE, (SPRITE_CNN2_IDX-1), CNN2_X, CNN2_Y); // FIRE overlay
    }
    else if (proj_actv==3&&proj_y>=(CNN3_Y-16))
    {
        proj_actv = 0;
        resetProjectile(SPRITE_PROJ_IDX+2);
        reduceShipHealth();
        cnn3_stat = 0;
        drawSprite(FIRE, (SPRITE_CNN3_IDX-1), CNN3_X, CNN3_Y); // FIRE overlay
    }
    else if (proj_actv==4&&proj_y<=(CNN4_Y+16))
    {
        proj_actv = 0;
        resetProjectile(SPRITE_PROJ_IDX+3);
        reduceShipHealth();
        cnn4_stat = 0;
        drawSprite(FIRE, (SPRITE_CNN4_IDX-1), CNN4_X, CNN4_Y); // FIRE overlay
    }
    else if (proj_actv==5&&proj_y<=(CNN5_Y+16))
    {
        proj_actv = 0;
        resetProjectile(SPRITE_PROJ_IDX+4);
        reduceShipHealth();
        cnn5_stat = 0;
        drawSprite(FIRE, (SPRITE_CNN5_IDX-1), CNN5_X, CNN5_Y); // FIRE overlay
    }
}

// -------------------- Blow Projectile --------------------
void blowProjectile(int N)
{
    if (blowing_proj_st==true){return;} //guard clause

    drawSprite(EXPLOSION, SPRITE_EXPL_IDX, proj_x, proj_y); //draw explotion sprite overlay

    blowing_proj_st = true; // enable blowing projectile delay
    proj_blow_tf = tick_cmd+BLOW_DELAY; // set finish time of blow
    blowing_proj_id = N; // set blowing projectile index
}

// -------------------- Blowing Projectile Handler --------------------
void blowProjectileHandler(void)
{
    if (blowing_proj_st==false){return;} //activation check

    if (tick_cmd>=proj_blow_tf) //finish time check
    {
        resetProjectile(blowing_proj_id); // dump projectile
        drawSprite(0, SPRITE_EXPL_IDX, DUMP_X, DUMP_Y); // dump explotion sprite

        blowing_proj_st = false; // reset flag
    }
}

// -------------------- Reset Projectile --------------------
void resetProjectile(int N)
{
    proj_x_flt = DUMP_X; // set projectile position vars to DUMP
    proj_y_flt = DUMP_Y;
    proj_x = DUMP_X;
    proj_y = DUMP_Y;

    drawSprite(0, N, proj_x, proj_y); // dump projectile sprite
    needToUpdateLevel = true; // set flag = true to progress level
}
