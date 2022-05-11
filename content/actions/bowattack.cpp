#include "bowattack.h"
#include "rest.h"
#include "tile.h"
BowAttack::BowAttack(Actor& attacker, Actor& defender)
    :attacker{attacker}, defender{defender}{}

Result BowAttack::perform(Engine& engine){
    if (defender.team != attacker.team){
        attacker.attack(defender);
        return success();
    }else{
        return alternative(Rest());
    }
}