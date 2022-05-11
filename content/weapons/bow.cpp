#include "bow.h"

Bow::Bow(int damage)
    :Weapon{"bow", damage}{}

void Bow::use(Engine& engine, Actor& attacker, Actor& defender){
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Shoot{sprite, "arrow", direction, defender, damage});
    engine.events.add(Swing{sprite, direction, defender, damage});

}