#include "monsters.h"
#include "none.h"
#include "monstertype.h"
#include "rest.h"
#include "randomness.h"
#include "wander.h"
#include "engine.h"
#include "move.h"
#include "knife.h"
#include "hammer.h"
#include "staff.h"
namespace Monsters {
    std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me){
        if (me.is_visible() && engine.hero) {
            Vec from = me.get_position();
            Vec to = engine.hero->get_position();
            std::vector<Vec> path = engine.dungeon.calculate_path(from, to);
            if (path.size() > 1) {
                Vec direction = path.at(1) - path.at(0);
                return std::make_unique<Move>(direction);
            }
        }
        // Monster doesn't see Hero
        if (probability(66)) {
            return std::make_unique<Wander>();
        }
        else {
            return std::make_unique<Rest>();
        }
    }

    MonsterType goblin(){
        int health = 2;
        return {"goblin", default_speed, health, std::make_shared<Knife>(1), default_behavior};
    }
    MonsterType necromancer(){
        int health = 4;
        return {"necromancer", default_speed, health, std::make_shared<Staff>(3), default_behavior};
    }
    MonsterType muddy(){
        int health = 3;
        return {"muddy", default_speed, health, std::make_shared<Hammer>(2), default_behavior};
    }

}
