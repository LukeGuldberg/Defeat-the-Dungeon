#pragma once
#include "weapon.h"
#include "actor.h"
#include "engine.h"
#include "hit.h"
#include "swing.h"

class Hammer : public Weapon{
public: 
    Hammer(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;

};