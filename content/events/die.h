#pragma once
#include "event.h"
#include "engine.h"
#include "actor.h"

class Die : public Event {
public:
    Die(Actor& actor);
    void execute(Engine& engine) override;

private:
    Actor& actor;
};