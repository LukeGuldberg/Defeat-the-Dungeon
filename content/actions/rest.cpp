#include "rest.h"
#include "actor.h"
Result Rest::perform(Engine&) {
    if(actor->health < actor->max_health){
        actor->take_damage(-1);
    }
    return success();
}
