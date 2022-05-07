#pragma once
#include "weapon.h"
#include "actor.h"
#include "engine.h"
#include "hit.h"
#include "swing.h"

class Knife : public Weapon{
public: 
    Knife(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;

private:
    int damage;
};