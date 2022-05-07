#include "hit.h"

Hit::Hit(Actor& defender, int amount)
    :defender{defender}, amount{amount}{}

void Hit::execute(Engine& engine){
    defender.take_damage(amount);
    if(defender.health <= 0){
        engine.events.add(Die{defender});
    }
}