#pragma once
#include "engine.h"
#include "action.h"
#include "actor.h"

class Attack : public Action{
public:
    Attack(Actor&, Actor&);
    Result perform(Engine& engine) override;
private:
    Actor& attacker;
    Actor& defender;
};
