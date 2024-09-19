#include "splashkit.h"
#include "player.h"

//generate data about wind monster
player_data new_wind_monster()
{
    player_data result;
   

    bitmap bmpidle = bitmap_named("windidle");
    bitmap bmpattack1 = bitmap_named("windattack1");
    bitmap bmprun = bitmap_named("windrun");
    bitmap rebmpidle = bitmap_named("windidleleft");
    bitmap rebmpattack1 = bitmap_named("windattack1left");
    bitmap rebmprun = bitmap_named("windrunleft");
    bitmap bmptakehit = bitmap_named("windtakehit");
    bitmap rebmptakehit = bitmap_named("windtakehitleft");
    bitmap bmpdeath = bitmap_named("winddeath");
    bitmap rebmpdeath = bitmap_named("winddeathleft");



    result.idlescpt = load_animation_script("IdleScript", "windidle.txt");
    result.attackscpt = load_animation_script("AttackScript","windattack1.txt");
    result.runscpt = load_animation_script("RunScript", "windrun.txt");
    result.reidlescpt = load_animation_script("reIdleScript", "windidleleft.txt");
    result.reattackscpt = load_animation_script("reAttackScript","windattack1left.txt");
    result.rerunscpt = load_animation_script("reRunScript", "windrunleft.txt");
    result.takehitscpt = load_animation_script("TakeScript", "windtakehit.txt");
    result.retakehitscpt = load_animation_script("reTakeScript", "windtakehitleft.txt");
    result.deathscpt = load_animation_script("DeathScript", "winddeath.txt");
    result.redeathscpt = load_animation_script("reDeathScript", "winddeathleft.txt");
    



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
