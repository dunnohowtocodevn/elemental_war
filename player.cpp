#include "splashkit.h"
#include "player.h"



//Check if the monster is turning to the left
bool is_left(bool result)
{
    
    if(key_typed(A_KEY))
    {
        result = true;
    }
    if(key_typed(D_KEY))
    {
        result = false;
    }

    return result;
}

//Handle user input
void input_player1(player_data &player1, bool &left)
{
    

    if(key_typed(LEFT_SHIFT_KEY))
    {
        if((sprite_animation_name(player1.spriteptr) != "3") & (left == false))
        {
            player1.spriteptr = player1.sprattack1;
            sprite_start_animation(player1.spriteptr, 0, 0);
    
        }

        if((sprite_animation_name(player1.spriteptr) != "4") & (left == true))
        {
            player1.spriteptr = player1.resprattack1;
            sprite_start_animation(player1.spriteptr, 0);
    
        }
        
    }

    else if(key_typed(D_KEY))
    {
        if (sprite_animation_name(player1.spriteptr) != "5" )
        {
            player1.spriteptr = player1.sprrun;
            sprite_start_animation(player1.spriteptr, 0);
            
        }
    }

    else if(key_typed(A_KEY))
    {
        if (sprite_animation_name(player1.spriteptr) != "6" )
        {
            player1.spriteptr = player1.resprrun;
            sprite_start_animation(player1.spriteptr, 0);
            
        }
    }

    else if(sprite_animation_has_ended(player1.spriteptr) or key_released(A_KEY) or key_released(D_KEY))
    {
        if(left == false)
        {
            player1.spriteptr = player1.spridle;
            sprite_start_animation(player1.spriteptr, 0);
        }

        else if(left == true)
        {
            player1.spriteptr = player1.respridle;
            sprite_start_animation(player1.spriteptr, 0);
        }

    }

    
    update_sprite_animation(player1.spriteptr);
    update_sprite(player1.spriteptr);
   
    draw_sprite(player1.spriteptr);
}

//Moving all the bitmaps when the sprite moves
void manage_position(player_data &player1)
{
    
    
    if(key_down(D_KEY))
    {
        
        sprite_set_x(player1.spridle, sprite_position(player1.spridle).x + 3);
        sprite_set_x(player1.sprattack1, sprite_position(player1.sprattack1).x + 3);
        sprite_set_x(player1.sprrun, sprite_position(player1.sprrun).x + 3);
        sprite_set_x(player1.respridle, sprite_position(player1.respridle).x + 3);
        sprite_set_x(player1.resprattack1, sprite_position(player1.resprattack1).x + 3);
        sprite_set_x(player1.resprrun, sprite_position(player1.resprrun).x + 3);
        sprite_set_x(player1.sprtakehit, sprite_position(player1.sprtakehit).x + 3);
        sprite_set_x(player1.resprtakehit, sprite_position(player1.resprtakehit).x + 3);
        sprite_set_x(player1.sprdeath, sprite_position(player1.sprdeath).x + 3);
        sprite_set_x(player1.resprdeath, sprite_position(player1.resprdeath).x + 3);





        
    }

    else if(key_down(A_KEY))
    {
        sprite_set_x(player1.spridle, sprite_position(player1.spridle).x - 3);
        sprite_set_x(player1.sprattack1, sprite_position(player1.sprattack1).x - 3);
        sprite_set_x(player1.sprrun, sprite_position(player1.sprrun).x - 3);
        sprite_set_x(player1.respridle, sprite_position(player1.respridle).x - 3);
        sprite_set_x(player1.resprattack1, sprite_position(player1.resprattack1).x - 3);
        sprite_set_x(player1.resprrun, sprite_position(player1.resprrun).x - 3);
        sprite_set_x(player1.sprtakehit, sprite_position(player1.sprtakehit).x - 3);
        sprite_set_x(player1.resprtakehit, sprite_position(player1.resprtakehit).x - 3);
        sprite_set_x(player1.sprdeath, sprite_position(player1.sprdeath).x - 3);
        sprite_set_x(player1.resprdeath, sprite_position(player1.resprdeath).x - 3);


    }
}           

