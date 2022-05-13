#include "bow.h"
#include <cmath>
Bow::Bow(int damage)
    :Weapon{"bow", damage}{}

void Bow::use(Engine& engine, Actor& attacker, Actor& defender){
    Vec distance = defender.get_position() - attacker.get_position();
    if(abs(distance.x) == 1 || abs(distance.y) == 1){ //checking to see if the attacker and defender are right next to each other
        engine.events.add(Swing{sprite, attacker.direction, defender, damage-2}); //if they are, melee
    } else {
        engine.events.add(Shoot{sprite, attacker.direction, damage, attacker.get_position(), defender.get_position()}); //if they aren't, then shoot the arrow
    }

}