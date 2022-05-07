#include "swing.h"

constexpr int duration = 10;

Swing::Swing(Sprite& sprite, Vec direction, Actor& defender, int damage)
    :Event{duration}, sprite{sprite}, copy{sprite}, defender{defender}, 
    damage{damage}, starting_angle{sprite.angle}{
        if(direction == Vec{1,0}){
            starting_angle = 0;
            delta = 135.0 / (duration-1);
        }
    }
    
void Swing::execute(Engine& engine){
    sprite.angle += starting_angle + delta * frame_count;
}
void Swing::when_done(Engine& engine){
    sprite = copy;
    engine.events.add(Hit{defender, damage});
}