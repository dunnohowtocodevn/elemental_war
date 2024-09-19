#include "splashkit.h"

#include "elemental_war.h"
#include <string.h>


using namespace::std;

int read_integer(string prompt)
{
   write(prompt);
   return convert_to_integer(read_line());
}

//Draw the HUD background
void draw_hud(game_data game)
{
   load_bitmap("background", "background3.png");

   draw_bitmap("background",0, 0 );

   draw_text("PLAYER1: " + to_string(game.player1.hp), COLOR_WHITE,5 ,10,option_to_screen());
   draw_text("PLAYER2: " + to_string(game.player2.hp), COLOR_WHITE,900 ,10, option_to_screen());

}


//Set up the monsters'initial positions
void initial_set_up(player_data &player1, player_data &player2)
{   
   player1.spriteptr = player1.spridle;
   sprite_start_animation(player1.spriteptr, 0);

   sprite_set_x(player1.spridle, 50);
   sprite_set_x(player1.sprattack1, 50);
   sprite_set_x(player1.sprrun, 50);
   sprite_set_x(player1.respridle, 50);
   sprite_set_x(player1.resprattack1, 50);
   sprite_set_x(player1.resprrun, 50);
   sprite_set_x(player1.sprtakehit,50);
   sprite_set_x(player1.resprtakehit,50);
   sprite_set_x(player1.sprdeath,50);
   sprite_set_x(player1.resprdeath,50);


  
   sprite_set_y(player1.spridle, 350);
   sprite_set_y(player1.sprattack1,350);
   sprite_set_y(player1.sprrun,350);
   sprite_set_y(player1.respridle, 350);
   sprite_set_y(player1.resprattack1,350);
   sprite_set_y(player1.resprrun,350);
   sprite_set_y(player1.sprtakehit,350);
   sprite_set_y(player1.resprtakehit,350);
   sprite_set_y(player1.sprdeath,350);
   sprite_set_y(player1.resprdeath,350);
    
   player2.spriteptr = player2.respridle;
   sprite_start_animation(player2.spriteptr, 0);


   sprite_set_x(player2.spridle, 800);
   sprite_set_x(player2.sprattack1, 800);
   sprite_set_x(player2.sprrun, 800);
   sprite_set_x(player2.respridle, 800);
   sprite_set_x(player2.resprattack1, 800);
   sprite_set_x(player2.resprrun, 800);
   sprite_set_x(player2.sprtakehit,800);
   sprite_set_x(player2.resprtakehit,800);
   sprite_set_x(player2.sprdeath,800);
   sprite_set_x(player2.resprdeath,800);


  
   sprite_set_y(player2.spridle, 350);
   sprite_set_y(player2.sprattack1,350);
   sprite_set_y(player2.sprrun,350);
   sprite_set_y(player2.respridle, 350);
   sprite_set_y(player2.resprattack1,350);
   sprite_set_y(player2.resprrun,350);
   sprite_set_y(player2.sprtakehit,350);
   sprite_set_y(player2.resprtakehit,350);
   sprite_set_y(player2.sprdeath,350);
   sprite_set_y(player2.resprdeath,350);
}

//Assign the monster to the player
void assign_monster(MONSTER &choice, player_data &player)
{  
   
      if(choice == FIREMONSTER) 
      {
         player = new_fire_monster();

      }
      else if(choice == ROCKMONSTER)
      {
         player = new_rock_monster();
      } 
      
      else if(choice == ICEMONSTER){
      player =  new_ice_monster();
      } 
      else if(choice == WINDMONSTER)
      {
      player =  new_wind_monster(); 
      }
   
}

//Check if a monster hit the other one
void check_fight(player_data &player1, player_data &player2, bool &direction, bool &direction2)
{
   bool check = sprite_collision(player1.spriteptr, player2.spriteptr);
   
   
   if (key_typed (LEFT_SHIFT_KEY))
   {  
      if(check == true)
      {  
         if(direction2 == false)
         {
            player2.spriteptr = player2.sprtakehit;
            sprite_start_animation( player2.spriteptr, 0);
            player2.hp -= 10;
            
         }
          
          else
         {
            player2.spriteptr = player2.resprtakehit;
            sprite_start_animation( player2.spriteptr, 0);
            player2.hp -= 10;

         }
      

      }     
   }

   if (key_typed (SPACE_KEY))
   {  
      if(check == true)
      {
         if(direction == false)
         {
            player1.spriteptr = player1.sprtakehit;
            sprite_start_animation( player1.spriteptr, 0);
            player1.hp -= 10;
           
         }

         else
         {
            player1.spriteptr = player1.resprtakehit;
            sprite_start_animation( player1.spriteptr, 0);
            player1.hp -= 10;
            
         
         }
     
      }

   }
}

//Check if the monster is dead
void check_death(player_data &player1, player_data &player2, bool &check, bool &check2)
{  
  
  
   if(player1.hp == 0 )
   {
      if(check == false)
      {
         player1.spriteptr = player1.sprdeath;
         sprite_start_animation(player1.spriteptr, 0);
         
      }

      else if (check == true)
      {
         player1.spriteptr = player1.resprdeath;
         sprite_start_animation(player1.spriteptr, 0);
      }
   }

   if(player2.hp == 0 )
   {
      if(check2 == true)
      {
         player2.spriteptr = player2.resprdeath;
         sprite_start_animation(player2.spriteptr, 0);
      }

      else if(check2 == false)
      {
         player2.spriteptr = player2.sprdeath;
         sprite_start_animation(player2.spriteptr, 0);
      }

   }
}


// Set up the menu so that the user can choose using mouse 
void choose_monster(MONSTER &choice)
{
   point_2d coor = mouse_position();

    if(coor.x >= 50 && coor.x <= 250 && coor.y >= 300 && coor.y <= 500 && mouse_clicked(LEFT_BUTTON))
    {
        choice = FIREMONSTER;
      
        
    }

   if(coor.x >= 300 && coor.x <= 500 && coor.y >= 300 && coor.y <= 500 && mouse_clicked(LEFT_BUTTON))
    {
        choice = ROCKMONSTER;
    }

   if(coor.x >= 550 && coor.x <= 750 && coor.y >= 300 && coor.y <= 500 && mouse_clicked(LEFT_BUTTON))
    {
        choice = ICEMONSTER;
    }

   if(coor.x >= 800 && coor.x <= 1000 && coor.y >= 300 && coor.y <= 500 && mouse_clicked(LEFT_BUTTON))
    {
        choice = WINDMONSTER;
    }


}

//Update everything in the game
void update_game(player_data &player1, player_data &player2)
{
   update_sprite_animation(player1.spriteptr);
   update_sprite(player1.spriteptr);
   manage_position(player1);
   update_sprite_animation(player2.spriteptr);
   update_sprite(player2.spriteptr);
   manage_position2(player2);
}

//Create a new game
game_data new_game(MONSTER &choice1, MONSTER &choice2)
{
   game_data result;
   

   assign_monster(choice1, result.player1);
   assign_monster(choice2, result.player2);
   initial_set_up(result.player1, result.player2);

   result.check1 = is_left(result.check1);
   result.check2 = is_left2(result.check2);

   return result;
}