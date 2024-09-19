#ifndef PLAYER
#define PLAYER

#include "splashkit.h"

/*
* struct    player_data
* field     bitmap
* field     animation_script   
* field     animation 
* field     sprite
* field     drawing_options
* field     hp  int  
*/
struct player_data
{
    sprite spriteptr;

    bitmap bmpidle;
    bitmap rebmpidle;
    bitmap bmpattack1;
    bitmap rebmpattack1;
    bitmap bmprun;
    bitmap rebmprun;
    bitmap bmptakehit;
    bitmap rebmptakehit;
    bitmap bmpdeath;
    bitmap rebmpdeath;
   

    animation_script idlescpt;
    animation_script attackscpt;
    animation_script runscpt;
    animation_script reidlescpt;
    animation_script reattackscpt;
    animation_script rerunscpt;
    animation_script takehitscpt;
    animation_script retakehitscpt;
    animation_script deathscpt;
    animation_script redeathscpt;
    

    

    animation aniidle;
    animation reaniidle;
    animation aniattack1;
    animation reaniattack1;
    animation anirun;
    animation reanirun;
    animation anitakehit;
    animation reanitakehit;
    animation anideath;
    animation reanideath;

    sprite spridle;
    sprite respridle;
    sprite sprattack1;
    sprite resprattack1;
    sprite sprrun;
    sprite resprrun;
    sprite sprtakehit;
    sprite resprtakehit;
    sprite sprdeath;
    sprite resprdeath;

    drawing_options idleopt;
    drawing_options leftidleopt;
    drawing_options attack1opt;
    drawing_options leftattack1opt;
    drawing_options rightrunopt;
    drawing_options leftrunopt;
    drawing_options takehitopt;
    drawing_options lefttakehitopt;
    drawing_options deathopt;
    drawing_options leftdeathopt;
   


    int hp;
    

};


/*
* check whether the monster is turning right or left
*/
bool is_left(bool result);
bool is_left2(bool result);

/*
* create new player
*/
player_data new_fire_monster();
player_data new_rock_monster();
player_data new_ice_monster();
player_data new_wind_monster();

/*
* manage user's input
* @param    player_data, bool
*/
void input_player1(player_data &player1, bool &left);
void input_player2(player_data &player2, bool &left);

/*
* manage monster's position
* @param player_data, bool
*/
void manage_position(player_data &player1);
void manage_position2(player_data &player2);

#endif

