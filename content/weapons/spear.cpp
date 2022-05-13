#include "spear.h"
Spear::Spear(int damage)
    :Weapon{"knife", damage}{}

void Spear::use(Engine& engine, Actor& attacker, Actor& defender){
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
}