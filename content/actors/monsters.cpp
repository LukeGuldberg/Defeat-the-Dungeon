#include "monsters.h"
#include "none.h"
#include "monstertype.h"
#include "rest.h"
#include "randomness.h"
#include "wander.h"
namespace Monsters {
    std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me){
        if (probability(66)) { // engine/util/randomness.h
            return std::make_unique<Wander>();
        }else {
            return std::make_unique<Rest>();
        }
    }

    MonsterType goblin(){
        int health = 2;
        return {"goblin", default_speed, health, std::make_shared<None>(), default_behavior};
    }
    MonsterType necromancer(){
        int health = 4;
        return {"necromancer", default_speed, health, std::make_shared<None>(), default_behavior};
    }
    MonsterType muddy(){
        int health = 3;
        return {"muddy", default_speed*2, health, std::make_shared<None>(), default_behavior};
    }

}
