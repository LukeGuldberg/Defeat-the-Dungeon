#include "engine.h"
#include "heros.h"
#include "monsters.h" 
using namespace std;
int main() {
    std::string filename{"settings.txt"};
    Settings settings = read_settings(filename);
    Engine engine{settings};

    engine.create_hero(Heros::bro);
    //engine.create_hero(Heros::dude);
    

    for(int x = 0; x<3; x++){
        engine.create_monster(Monsters::goblin());
        engine.create_monster(Monsters::necromancer());
        engine.create_monster(Monsters::muddy());
        engine.create_monster(Monsters::demon_big());
        engine.create_monster(Monsters::zombie_big());
        engine.create_monster(Monsters::ogre());



    }


    engine.run();
}
