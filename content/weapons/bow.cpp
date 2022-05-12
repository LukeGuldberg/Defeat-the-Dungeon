#include "bow.h"
#include <cmath>
Bow::Bow(int damage)
    :Weapon{"bow", damage}{}

void Bow::use(Engine& engine, Actor& attacker, Actor& defender){
    Vec distance = attacker.get_position() - defender.get_position();
    if(abs(distance.x) == 1 || abs(distance.y) == 1){
        engine.events.add(Swing{sprite, attacker.direction, defender, damage-2});
    } else {
        engine.events.add(Shoot{sprite, attacker.direction, damage, attacker.get_position(), defender.get_position()});
    }

}