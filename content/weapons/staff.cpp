#include "staff.h"

Staff::Staff(int damage)
    :Weapon{"staff_green", damage}{}

void Staff::use(Engine& engine, Actor& attacker, Actor& defender){
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
}