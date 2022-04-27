#include "move.h"
#include "actor.h"
#include "engine.h"

Move::Move(Vec direction)
    :direction{direction}{}

Result Move::perform(Engine& engine){
    Vec new_position = actor->get_position() + direction;
    Tile& tile = engine.dungeon.tiles(new_position);
    actor->change_direction(direction);
    if(tile.is_wall() || tile.actor) {
        return failure();
    }
    if(tile.is_door()){
        return failure();
    }
    actor->move_to(new_position);
    return success();
}

