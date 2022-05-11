#pragma once
#include "weapon.h"
#include "actor.h"
#include "engine.h"
#include "hit.h"
#include "shoot.h"
#include "swing.h"

class Bow : public Weapon{
public: 
    Bow(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;

};