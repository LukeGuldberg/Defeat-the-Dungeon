#pragma once
#include "engine.h"
#include "sprite.h"
#include "actor.h"
#include "vec.h"
#include "event.h"
#include "hit.h"

class Shoot : public Event {
public: 
    Shoot(Sprite& sprite, Vec direction, int damage, Vec start_pos, Vec end_pos);
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;
private:
    Sprite& weapon;
    Vec direction;
    int damage;
    Vec start_pos, end_pos;
    double starting_angle;
    Vec position;
    Sprite projectile;
    double projectile_angle;
    };