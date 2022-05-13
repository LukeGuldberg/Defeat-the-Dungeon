#pragma once
#include "rest.h"
#include "closedoor.h"
#include "opendoor.h"
#include "herotype.h"
#include "none.h"
#include "move.h"
#include "staff.h"
#include "bowattack.h"
#include "bow.h"

namespace Heros {
    using Reaction = std::function<std::unique_ptr<Action>()>;

    std::unordered_map<std::string, Reaction> key_bindings = {
        {"Left", []() { return std::make_unique<Move>(Vec{-1, 0}); } },
    
        {"Right", []() { return std::make_unique<Move>(Vec{1, 0}); } },
    
        {"Up", []() { return std::make_unique<Move>(Vec{0, 1}); } },
    
        {"Down", []() { return std::make_unique<Move>(Vec{0, -1}); } },
    
        {"Space", []() { return std::make_unique<Rest>(); } },

        {"C", []() { return std::make_unique<CloseDoor>(); } },

        {"B", []() { return std::make_unique<BowAttack>(); } } //shoots the arrow
    };

    constexpr int default_speed{8};
    const HeroType nobody{"none", default_speed, 1, std::make_shared<None>(), {}};
    const HeroType dude{"wizard", default_speed, 15, std::make_shared<Staff>(4), {key_bindings}};
    const HeroType bro{"elf", default_speed, 15, std::make_shared<Bow>(4), {key_bindings}};
    
}
