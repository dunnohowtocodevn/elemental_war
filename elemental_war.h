#include "splashkit.h"
#include "player.h"

/*
* contain all the data about the game
* struct game_data
* field player_data
* field bool
*/
struct game_data
{   player_data player1;
    player_data player2;

    bool check1;
    bool check2;

};

/*
* Check whether the monsters hit each other
* @param    player_data
* @param    bool
*/
enum MONSTER
{   FIREMONSTER,
    ROCKMONSTER,
    ICEMONSTER,
    WINDMONSTER
};

/*
* Create new game
*/
game_data new_game(MONSTER &choice1,MONSTER &choice2);

/*
* Check whether the monsters hit each other
* @param    player_data
* @param    bool
*/
void check_fight(player_data &player1, player_data &player2, bool &direction, bool &direction2);

/*
* Check if the monster has died
* @param    player_data
* @param    bool
*/
void check_death(player_data &player1, player_data &player2, bool &check, bool &check2);

/*
* draw the background
*/
void draw_hud(game_data game);

/*
* Choose a monster among the four
*/
void choose_monster(MONSTER &choice);

/*
* Assign the chosen monster to appropriate player
* @param MONSTER
* @param player_data
*/
void assign_monster(MONSTER &choice, player_data &player);


/*
* Show the menu for the player to choose
* @param player_data
*/
void initial_set_up(player_data &player1, player_data &player2);

/*
* Update all the sprites and the animations
*/
void update_game(player_data &player1, player_data &player2);

