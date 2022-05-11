#pragma once
#include "engine.h"
#include "action.h"
#include "actor.h"

class BowAttack : public Action{
public:
    BowAttack(Actor&, Actor&);
    Result perform(Engine& engine) override;
private:
    Actor& attacker;
    Actor& defender;
};