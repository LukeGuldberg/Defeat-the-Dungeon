#include "attack.h"
#include "rest.h"
Attack::Attack(Actor& attacker, Actor& defender)
    :attacker{attacker}, defender{defender}{}

Result Attack::perform(Engine& engine){
    if (defender.team == 0){
        attacker.attack(defender);
        return success();
    }else{
        return alternative(Rest());
    }
}