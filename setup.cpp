#include "splashkit.h"
#include "setup.h"

//The menu to choose monster
void menu()
{
   
    
    player_data monster1;
    player_data monster2;
    player_data monster3;
    player_data monster4;

    monster1 = new_fire_monster();
    monster2 = new_rock_monster();
    monster3 = new_ice_monster();
    monster4 = new_wind_monster();

    sprite_set_x(monster1.spridle,50);
    sprite_set_x(monster2.spridle,300);
    sprite_set_x(monster3.spridle,550);
    sprite_set_x(monster4.spridle,800);

    sprite_set_y(monster1.spridle,300);
    sprite_set_y(monster2.spridle,300);
    sprite_set_y(monster3.spridle,300);
    sprite_set_y(monster4.spridle,300);
    
    sprite_start_animation(monster1.spridle,0);
    sprite_start_animation(monster2.spridle,0);
    sprite_start_animation(monster3.spridle,0);
    sprite_start_animation(monster4.spridle,0);

    
    
    update_sprite(monster1.spridle);
    update_sprite(monster2.spridle);
    update_sprite(monster3.spridle);
    update_sprite(monster4.spridle);
        
    update_sprite_animation(monster1.spridle);
    update_sprite_animation(monster2.spridle);
    update_sprite_animation(monster3.spridle);
    update_sprite_animation(monster4.spridle);


    draw_sprite(monster1.spridle);
    draw_sprite(monster2.spridle);
    draw_sprite(monster3.spridle);
    draw_sprite(monster4.spridle);


   
    refresh_screen(60);
    
      

}


//showing windows for two players
void set_up(MONSTER &choice1,MONSTER &choice2)
{
    open_window("PLAYER 1", 1000,600);
    clear_screen(COLOR_BLACK);
    
    while(not mouse_clicked(LEFT_BUTTON))
    {  process_events();
       menu();
       
       choose_monster(choice1);
    }
    
    close_current_window();
    

    open_window("PLAYER 2", 1000,600);
    clear_screen(COLOR_BLACK);
    
    do
    {  
       process_events();
       menu();
       
       choose_monster(choice2); 
       
    }
    while(not mouse_clicked(LEFT_BUTTON));
    close_current_window();
}


