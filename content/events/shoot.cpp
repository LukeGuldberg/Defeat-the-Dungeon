#include "shoot.h"
#include "camera.h"
#include "sprite.h"
#include <cmath>

Shoot::Shoot(Sprite& sprite, Vec direction, int damage, Vec start_pos, Vec end_pos)
    :Event{distance(start_pos, end_pos)}, weapon{sprite}, direction{direction},
    damage{damage}, start_pos{start_pos}, end_pos{end_pos}, starting_angle{sprite.angle}, position{direction+start_pos}{
       if(direction == Vec{1,0}){
            projectile_angle = 90;
        }
        else if(direction == Vec{-1,0}){
            sprite.flip = true;
            starting_angle = 0;
            projectile_angle = -90;
        }                              //rotating the projectile according 
        else if(direction == Vec{0,1}){//to the direction of the actor
            starting_angle = -90;
            projectile_angle = 0;
        }
        else {
            starting_angle = 90;
            projectile_angle = 180;
        }
    }

void Shoot::execute(Engine& engine){ //shows animation of the arrow and sets the angle for the projectile
    if(frame_count == 0){
        projectile = engine.graphics.get_sprite("arrow");
        projectile.angle = projectile_angle;
    }
    engine.camera.add_overlay(position, projectile); //shows a picture of the arrow on one tile, 
                                                     //then the function is called again and again until you
    position = position + direction;                 // reach your end_pos
}

void Shoot::when_done(Engine& engine){
    Tile& tile = engine.dungeon.tiles(end_pos);
    if(tile.actor){
        engine.events.add(Hit{*tile.actor, damage}); //only deals damage if end_pos has an actor on it
    }
} 