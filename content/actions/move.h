#pragma once

#include "action.h"
#include "vec.h"
#include "attack.h"

class Move : public Action {
public:
    Move(Vec direction);
    Result perform(Engine& engine) override;
private:
    Vec direction;
};