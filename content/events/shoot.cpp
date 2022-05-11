#include "shoot.h"
#include <cmath>
constexpr int duration = 10;

Shoot::Shoot(Sprite& sprite, Sprite& projectile, Vec direction, Actor& defender, int damage)
    :Event{duration}, sprite{sprite}, copy{sprite}, defender{defender}, 
    damage{damage}, starting_angle{sprite.angle}{}

void Shoot::execute(Engine& engine){

}