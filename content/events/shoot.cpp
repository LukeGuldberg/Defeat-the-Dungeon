#include "shoot.h"
#include "camera.h"
#include "sprite.h"
#include <cmath>
constexpr int duration = 10;

Shoot::Shoot(Sprite& sprite, Vec direction, int damage, Vec start_pos, Vec end_pos)
    :Event{duration}, weapon{sprite}, direction{direction},
    damage{damage}, start_pos{start_pos}, end_pos{end_pos}, starting_angle{sprite.angle}, position{direction+start_pos}{
       if(direction == Vec{1,0}){
            projectile_angle = 90;
        }
        else if(direction == Vec{-1,0}){
            sprite.flip = true;
            starting_angle = 0;
            projectile_angle = -90;
        }
        else if(direction == Vec{0,1}){
            starting_angle = -90;
            projectile_angle = 0;
        }
        else {
            starting_angle = 90;
            projectile_angle = 180;
        }
    }

void Shoot::execute(Engine& engine){
    if(frame_count == 0){
        projectile = engine.graphics.get_sprite("arrow");
        projectile.angle = projectile_angle;
    }
    
    Tile& tile = engine.dungeon.tiles(position);
    engine.camera.add_overlay(position, projectile);

    if (tile.actor){
        frame_count = number_of_frames;
    } 
    if(tile.is_door() || tile.is_wall()){
        frame_count = number_of_frames;
    }
    position = position + direction;
}

void Shoot::when_done(Engine& engine){
    Tile& tile = engine.dungeon.tiles(end_pos);
    if(tile.actor){
        engine.events.add(Hit{*tile.actor, damage});
    }
}