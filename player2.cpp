#include "splashkit.h"
#include "player.h"

//check if the monster is turning to the left
bool is_left2(bool result)
{
    
    if(key_typed(LEFT_KEY))
    {
        result = true;
    }
    if(key_typed(RIGHT_KEY))
    {
        result = false;
    }

    return result;
}

//Handle player2's input
void input_player2(player_data &player2, bool &left)
{
    if(key_typed(SPACE_KEY))
    {
        if((sprite_animation_name(player2.spriteptr) != "3") & (left == false))
        {
            player2.spriteptr = player2.sprattack1;
            sprite_start_animation(player2.spriteptr, 0);
    
        }

        if((sprite_animation_name(player2.spriteptr) != "4") & (left == true))
        {
            player2.spriteptr = player2.resprattack1;
            sprite_start_animation(player2.spriteptr, 0);
    
        }
        
    }

    else if(key_typed(RIGHT_KEY))
    {
        if (sprite_animation_name(player2.spriteptr) != "5" )
        {
            player2.spriteptr = player2.sprrun;
            sprite_start_animation(player2.spriteptr, 0);
            
        }
    }

    else if(key_typed(LEFT_KEY))
    {
        if (sprite_animation_name(player2.spriteptr) != "6" )
        {
            player2.spriteptr = player2.resprrun;
            sprite_start_animation(player2.spriteptr, 0);
            
        }
    }

    else if(sprite_animation_has_ended(player2.spriteptr) or key_released(LEFT_KEY) or key_released(RIGHT_KEY))
    {
        if(left == true)
        {
            player2.spriteptr = player2.respridle;
            sprite_start_animation(player2.spriteptr, 0);
        }

        else if(left == false)
        {
            player2.spriteptr = player2.spridle;
            sprite_start_animation(player2.spriteptr, 0);
        }

    }

    
    update_sprite_animation(player2.spriteptr);
    update_sprite(player2.spriteptr);
   
    draw_sprite(player2.spriteptr);
}

//Move all the bitmap when the sprite moves
void manage_position2(player_data &player2)
{
    
    if(key_down(RIGHT_KEY))
    {
        
        sprite_set_x(player2.spridle, sprite_position(player2.spridle).x + 3);
        sprite_set_x(player2.sprattack1, sprite_position(player2.sprattack1).x + 3);
        sprite_set_x(player2.sprrun, sprite_position(player2.sprrun).x + 3);
        sprite_set_x(player2.respridle, sprite_position(player2.respridle).x + 3);
        sprite_set_x(player2.resprattack1, sprite_position(player2.resprattack1).x + 3);
        sprite_set_x(player2.resprrun, sprite_position(player2.resprrun).x + 3);
        sprite_set_x(player2.sprtakehit, sprite_position(player2.sprtakehit).x + 3);
        sprite_set_x(player2.resprtakehit, sprite_position(player2.resprtakehit).x + 3);
        sprite_set_x(player2.sprdeath, sprite_position(player2.sprdeath).x + 3);
        sprite_set_x(player2.resprdeath, sprite_position(player2.resprdeath).x + 3);

        
    }

    else if(key_down(LEFT_KEY))
    {
        sprite_set_x(player2.spridle, sprite_position(player2.spridle).x - 3);
        sprite_set_x(player2.sprattack1, sprite_position(player2.sprattack1).x - 3);
        sprite_set_x(player2.sprrun, sprite_position(player2.sprrun).x - 3);
        sprite_set_x(player2.respridle, sprite_position(player2.respridle).x - 3);
        sprite_set_x(player2.resprattack1, sprite_position(player2.resprattack1).x - 3);
        sprite_set_x(player2.resprrun, sprite_position(player2.resprrun).x - 3);
        sprite_set_x(player2.sprtakehit, sprite_position(player2.sprtakehit).x - 3);
        sprite_set_x(player2.resprtakehit, sprite_position(player2.resprtakehit).x - 3);
        sprite_set_x(player2.sprdeath, sprite_position(player2.sprdeath).x - 3);
        sprite_set_x(player2.resprdeath, sprite_position(player2.resprdeath).x - 3);



    }
}           

