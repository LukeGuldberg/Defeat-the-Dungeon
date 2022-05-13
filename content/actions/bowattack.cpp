#include "bowattack.h"
#include "shoot.h"
#include "weapon.h"
#include "tile.h"

BowAttack::BowAttack(){}

Result BowAttack::perform(Engine& engine){
    Vec direction = actor->direction;
    Vec position = actor->get_position() + direction; //figure out position so that you can get the tile adjacent to the actor
    Tile tile = engine.dungeon.tiles(position);       //you need to know the adjacent tile because that is where the animation will start
    while(!tile.actor && !tile.is_wall()){ // figure out the tile that the projectile will stop on (next to a wall, a hero, or a closed door)
        if (tile.is_door()){
            if(!(engine.dungeon.doors.at(position)).is_open()){
                break;
            }
        }
        position = position + direction;
        tile = engine.dungeon.tiles(position);
    }
    if(tile.actor){
            actor->attack(*tile.actor); //goes to Bow.cpp where and does damage to the defender
        } else{
            Sprite sprite = engine.graphics.get_sprite("bow");
            engine.events.add(Shoot{sprite, direction, 4, actor->get_position(), position}); //skips Bow.cpp and just shows the annimation, 
        }                                                                                    //does no damage because there is no actor
    return success();
}
