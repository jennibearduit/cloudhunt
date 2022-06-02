// -----------------------------------------------------------------------------
// BUTTON INPUTS
// -----------------------------------------------------------------------------

#define INPUT                      (KEY_MASK & (~REG_KEYS))

// -------------------- Button Interrupt [Gift Function] --------------------
void checkbutton()
{
    u16 buttons = INPUT;
    if (st_mode==2)
    {
        if ((buttons & KEY_A) == KEY_A)
        {
            buttonA();
        }
        if ((buttons & KEY_B) == KEY_B)
        {
            buttonB();
        }
        if ((buttons & KEY_RIGHT) == KEY_RIGHT)
        {
            buttonR();
        }
        if ((buttons & KEY_LEFT) == KEY_LEFT)
        {
            buttonL();
        }
        if ((buttons & KEY_UP) == KEY_UP)
        {
            buttonU();
        }
        if ((buttons & KEY_DOWN) == KEY_DOWN)
        {
            buttonD();
        }
    }
    else if (st_mode==0)
    {
        if ((buttons & KEY_START) == KEY_START)
        {
            buttonS();
        }
    }
}

// -------------------- Button A: Shoot Cannon --------------------
void buttonA(void)
{
    if (canInteract(p_x,p_y,(CNN1_X+16),CNN1_Y)==1)
    {
        // for level 1 and 2 cannon
        if ((st_level!=3)&&((proj_actv==1)&&(cnn1_stat==1)))
        {
            proj_actv = 0;
            blowProjectile(SPRITE_PROJ_IDX);
        }

        // for level 3 railgun
        else if (st_level==3&&railgun_stat==1)
        {
            shootRailgun();
        }
    }
    else if (((proj_actv==2)&&(cnn2_stat==1))&&(canInteract(p_x,p_y,(CNN2_X),CNN2_Y+5)==1))
    {
        proj_actv = 0;
        blowProjectile(SPRITE_PROJ_IDX+1);
    }
    else if (((proj_actv==3)&&(cnn3_stat==1))&&(canInteract(p_x,p_y,(CNN3_X),CNN3_Y+5)==1))
    {
        proj_actv = 0;
        blowProjectile(SPRITE_PROJ_IDX+2);
    }
    else if (((proj_actv==4)&&(cnn4_stat==1))&&(canInteract(p_x,p_y,(CNN4_X),CNN4_Y-12)==1))
    {
        proj_actv = 0;
        blowProjectile(SPRITE_PROJ_IDX+3);
    }
    else if (((proj_actv==5)&&(cnn5_stat==1))&&(canInteract(p_x,p_y,(CNN5_X),CNN5_Y-12)==1))
    {
        proj_actv = 0;
        blowProjectile(SPRITE_PROJ_IDX+4);
    }
}

// -------------------- Button B: Repair Cannon --------------------
void buttonB(void)
{
    if ((cnn1_stat==0)&&(canInteract(p_x,p_y,(CNN1_X+13),CNN1_Y)==1))
    {
        cnn1_repair_tf = tick_sec+CNN_REPAIR; // set repair finish time
        drawSprite(REPAIR, (SPRITE_CNN1_IDX-1), CNN1_X, CNN1_Y); // REPAIR overlay
        cnn1_stat = 2; // set status to 'repairing'
    }
    else if ((cnn2_stat==0)&&(canInteract(p_x,p_y,(CNN2_X),CNN2_Y+5)==1))
    {
        cnn2_repair_tf = tick_sec+CNN_REPAIR; //set repair finish time
        drawSprite(REPAIR, (SPRITE_CNN2_IDX-1), CNN2_X, CNN2_Y); // REPAIR overlay
        cnn2_stat = 2; // set status to 'repairing'
    }
    else if ((cnn3_stat==0)&&(canInteract(p_x,p_y,(CNN3_X),CNN3_Y+5)==1))
    {
        cnn3_repair_tf = tick_sec+CNN_REPAIR; //set repair finish time
        drawSprite(REPAIR, (SPRITE_CNN3_IDX-1), CNN3_X, CNN3_Y); // REPAIR overlay
        cnn3_stat = 2; // set status to 'repairing'
    }
    else if ((cnn4_stat==0)&&(canInteract(p_x,p_y,(CNN4_X),CNN4_Y-12)==1))
    {
        cnn4_repair_tf = tick_sec+CNN_REPAIR; //set repair finish time
        drawSprite(REPAIR, (SPRITE_CNN4_IDX-1), CNN4_X, CNN4_Y); // REPAIR overlay
        cnn4_stat = 2; // set status to 'repairing'
    }
    else if ((cnn5_stat==0)&&(canInteract(p_x,p_y,(CNN5_X),CNN5_Y-12)==1))
    {
        cnn5_repair_tf = tick_sec+CNN_REPAIR; //set repair finish time
        drawSprite(REPAIR, (SPRITE_CNN5_IDX-1), CNN5_X, CNN5_Y); // REPAIR overlay
        cnn5_stat = 2; // set status to 'repairing'
    }
}

// -------------------- Button S: Page Navigation --------------------
void buttonS()
{
	if (st_mode != 0) return; // Guard clause

   pageNavigationHandler(); // call function to navigate page
}

// -------------------- Button R: Move Hero Right --------------------
void buttonR(void)
{
    if(p_x<SHIP_UPPER_X)
    {
        hero=HERO_RIGHT;
        float_p_x+=WALK_SPEED;
        p_x=(int)float_p_x;
    }
}

// -------------------- Button L: Move Hero left --------------------
void buttonL(void)
{
    if(p_x>SHIP_LOWER_X)
   {
      hero=HERO_LEFT;
      float_p_x-=WALK_SPEED;
      p_x=(int)float_p_x;
   }
}

// -------------------- Button U: Move Hero Up --------------------
void buttonU(void)
{
   if(p_y>SHIP_LOWER_Y)
   {
      hero=HERO_BACK;
      float_p_y-=WALK_SPEED;
      p_y=(int)float_p_y;
   }
}

// -------------------- Button D: Move Hero Down --------------------
void buttonD(void)
{
   if(p_y<SHIP_UPPER_Y)
   {
      hero=HERO_FRONT;
      float_p_y+=WALK_SPEED;
      p_y=(int)float_p_y;
   }
}
