#include "bowattack.h"
#include "shoot.h"
#include "weapon.h"
#include "tile.h"

BowAttack::BowAttack(){}

Result BowAttack::perform(Engine& engine){
    Vec direction = actor->direction;
    Vec position = actor->get_position() + direction;
    Tile& tile = engine.dungeon.tiles(position);
    
    while(!tile.actor && !tile.is_door() && !tile.is_wall()){
        position = position + direction;
        tile = engine.dungeon.tiles(position);
    }
    if(tile.actor){
            actor->attack(*tile.actor);
        } else{
            Sprite sprite = engine.graphics.get_sprite("bow");
            engine.events.add(Shoot{sprite, direction, 4, actor->get_position(), position});
        }
    return success();
}