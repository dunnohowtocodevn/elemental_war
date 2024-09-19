#include "splashkit.h"
#include "setup.h"

//Load the game resources
void load_resources()
{    
    load_resource_bundle("firebundle", "firebundle.txt");
    load_resource_bundle("icebundle", "icebundle.txt");
    load_resource_bundle("rockbundle", "rockbundle.txt");
    load_resource_bundle("windbundle", "windbundle.txt");

    load_sound_effect("war", "war.mp3");
    
}



int main()
{   process_events();
    load_resources();

    MONSTER choice1;
    MONSTER choice2;
    
    set_up(choice1, choice2);

    game_data game;
    game = new_game(choice1, choice2);
    
    play_sound_effect("war");
    open_window("Elemental War", 1000,600);
    clear_screen(COLOR_BLACK);
    while(not quit_requested())
    {   
        
        process_events();
       
        draw_hud(game);
        game.check1 = is_left(game.check1);
        game.check2 = is_left2(game.check2);
        input_player1(game.player1, game.check1);
        input_player2(game.player2,game.check2);
       
        update_game(game.player1, game.player2);
        check_fight(game.player1, game.player2, game.check1, game.check2);
        check_death(game.player1, game.player2, game.check1, game.check2);
        

        refresh_screen(60);

        
        
        if(key_typed (ESCAPE_KEY))
        {
            exit(0);
        }
    }


    
    return 0;
}