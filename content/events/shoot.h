#pragma once
#include "engine.h"
#include "sprite.h"
#include "actor.h"
#include "vec.h"
#include "event.h"
#include "hit.h"

class Shoot : public Event {
public: 
    Shoot(Sprite& sprite, Sprite& projectile, Vec direction, Actor& defender, int damage);
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;
private:
    Sprite& sprite;
    Sprite& projectile;
    Sprite copy;
    Actor& defender;
    int damage;

    double starting_angle, delta;
};