#include "splashkit.h"
#include "player.h"

//generate data about fire monster
player_data new_fire_monster()
{
    player_data result;
    
   

    bitmap bmpidle = bitmap_named("fireidle");
    bitmap bmpattack1 = bitmap_named("fireattack1");
    bitmap bmprun = bitmap_named("firerun");
    bitmap rebmpidle = bitmap_named("fireidleleft");
    bitmap rebmpattack1 = bitmap_named("fireattack1left");
    bitmap rebmprun = bitmap_named("firerunleft");
    bitmap bmptakehit = bitmap_named("firetakehit");
    bitmap rebmptakehit = bitmap_named("firetakehitleft");
    bitmap bmpdeath = bitmap_named("firedeath");
    bitmap rebmpdeath = bitmap_named("firedeathleft");



    result.idlescpt = load_animation_script("IdleScript", "fireidle.txt");
    result.attackscpt = load_animation_script("AttackScript","fireattack1.txt");
    result.runscpt = load_animation_script("RunScript", "firerun.txt");
    result.reidlescpt = load_animation_script("reIdleScript", "fireidleleft.txt");
    result.reattackscpt = load_animation_script("reAttackScript","fireattack1left.txt");
    result.rerunscpt = load_animation_script("reRunScript", "firerunleft.txt");
    result.takehitscpt = load_animation_script("TakeScript", "firetakehit.txt");
    result.retakehitscpt = load_animation_script("reTakeScript", "firetakehitleft.txt");
    result.deathscpt = load_animation_script("DeathScript", "firedeath.txt");
    result.redeathscpt = load_animation_script("reDeathScript", "firedeathleft.txt");
    



    result.aniidle = create_animation(result.idlescpt, "1");
    result.reaniidle = create_animation(result.reidlescpt, "2");
    result.aniattack1 = create_animation(result.attackscpt, "3");
    result.reaniattack1 = create_animation(result.reattackscpt, "4");
    result.anirun = create_animation(result.runscpt, "5");
    result.reanirun = create_animation(result.rerunscpt, "6");
    result.anitakehit = create_animation(result.takehitscpt, "7");
    result.reanitakehit = create_animation(result.retakehitscpt, "8");
    result.anideath = create_animation(result.deathscpt, "9");
    result.reanideath = create_animation(result.redeathscpt, "10");

    

    result.spridle = create_sprite(bmpidle, result.idlescpt);
    result.respridle = create_sprite(rebmpidle, result.reidlescpt);
    result.sprattack1 = create_sprite(bmpattack1, result.attackscpt);
    result.resprattack1 = create_sprite(rebmpattack1, result.reattackscpt);
    result.sprrun = create_sprite(bmprun,result.runscpt);
    result.resprrun = create_sprite(rebmprun,result.rerunscpt);
    result.sprtakehit = create_sprite(bmptakehit, result.takehitscpt);
    result.resprtakehit = create_sprite(rebmptakehit, result.retakehitscpt);
    result.sprdeath = create_sprite(bmpdeath, result.deathscpt);
    result.resprdeath = create_sprite(rebmpdeath, result.redeathscpt);



    result.idleopt = option_with_animation(result.aniidle);
    result.attack1opt = option_with_animation(result.aniattack1);
    result.leftidleopt = option_with_animation(result.reaniidle);
    result.attack1opt = option_with_animation(result.reaniattack1);
    result.rightrunopt = option_with_animation(result.anirun);
    result.leftrunopt = option_with_animation(result.reanirun);
    result.takehitopt = option_with_animation(result.anitakehit);
    result.deathopt = option_with_animation(result.anideath);
    result.lefttakehitopt = option_with_animation(result.reanitakehit);
    result.leftdeathopt = option_with_animation(result.reanideath);
    
    result.hp = 100;

    return result;

}