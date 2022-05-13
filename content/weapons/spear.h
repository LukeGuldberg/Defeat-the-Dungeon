#pragma once
#include "weapon.h"
#include "actor.h"
#include "engine.h"
#include "hit.h"
#include "swing.h"

class Spear : public Weapon{
public: 
    Spear(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;

};