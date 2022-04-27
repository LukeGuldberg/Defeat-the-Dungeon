#pragma once

#include "herotype.h"
#include "none.h"
#include "move.h"

namespace Heros {
    using Reaction = std::function<std::unique_ptr<Action>()>;

    std::unordered_map<std::string, Reaction> key_bindings = {
        {"Left", []() { return std::make_unique<Move>(Vec{-1, 0}); } },
    
        {"Right", []() { return std::make_unique<Move>(Vec{1, 0}); } },
    
        {"Up", []() { return std::make_unique<Move>(Vec{0, 1}); } },
    
        {"Down", []() { return std::make_unique<Move>(Vec{0, -1}); } },
    
        {"Space", []() { return std::make_unique<Move>(Vec{0, 0}); } },
    };

    constexpr int default_speed{8};
    const HeroType nobody{"none", default_speed, 1, std::make_shared<None>(), {}};
    const HeroType dude{"knight", default_speed, 1, std::make_shared<None>(), {key_bindings}};
    
}
