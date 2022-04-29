#pragma once
#include "action.h"
#include "monster.h"
#include <memory>
namespace Monsters {
    constexpr int default_speed {8};

    std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me);
    MonsterType goblin();

}
