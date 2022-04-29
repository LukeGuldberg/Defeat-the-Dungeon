#pragma once
#include "engine.h"
#include "action.h"

class OpenDoor : public Action{
public:
    OpenDoor(Vec);
    Result perform(Engine& engine) override;
protected:
    Vec position;
};