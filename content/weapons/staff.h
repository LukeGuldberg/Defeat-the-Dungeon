#pragma once
#include "weapon.h"
#include "actor.h"
#include "engine.h"
#include "hit.h"
#include "swing.h"

class Staff : public Weapon{
public: 
    Staff(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;

};