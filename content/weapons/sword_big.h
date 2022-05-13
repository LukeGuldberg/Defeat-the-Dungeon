#pragma once
#include "weapon.h"
#include "actor.h"
#include "engine.h"
#include "hit.h"
#include "swing.h"

class Sword_Big : public Weapon{
public: 
    Sword_Big(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;

};