#include "action.h"
#include "closedoor.h"
#include "updatefov.h"
#include "engine.h"
#include <iostream>

Result CloseDoor::perform(Engine& engine){
    bool closed_any_doors{false};
    auto neighbors = engine.dungeon.neighbors(actor->get_position());
    for (const Vec& position : neighbors) {
        Tile& tile = engine.dungeon.tiles(position);
        //std::cout << position << ' ' << tile.is_door() << '\n';
        if (tile.is_door()) {
            Door& door = engine.dungeon.doors.at(position);
            if (door.is_open()) {
                door.close();
                tile.walkable = false;
                closed_any_doors = true;
            }
        }
    }
    if (closed_any_doors){
        engine.events.add(UpdateFOV{});
        return success();
    }else{
        return failure();
    }
}
