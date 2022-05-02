#include "engine.h"
#include "heros.h"
#include "monsters.h"
using namespace std;
int main() {
    std::string filename{"settings.txt"};
    Settings settings = read_settings(filename);
    Engine engine{settings};

    engine.create_hero(Heros::dude);
    
    engine.create_monster(Monsters::goblin());
    engine.create_monster(Monsters::necromancer());
    engine.create_monster(Monsters::muddy());

    engine.run();
}
