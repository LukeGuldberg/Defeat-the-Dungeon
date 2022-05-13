#include "sword_big.h"
Sword_Big::Sword_Big(int damage)
    :Weapon{"knife", damage}{}

void Sword_Big::use(Engine& engine, Actor& attacker, Actor& defender){
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
}