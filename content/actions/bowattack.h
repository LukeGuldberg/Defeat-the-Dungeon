#pragma once
#include "engine.h"
#include "action.h"
#include "actor.h"

class BowAttack : public Action{
public:
    BowAttack();
    Result perform(Engine& engine) override;
private:
};