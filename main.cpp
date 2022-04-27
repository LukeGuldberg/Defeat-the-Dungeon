#include "engine.h"
#include "heros.h"
using namespace std;
int main() {
    std::string filename{"settings.txt"};
    Settings settings = read_settings(filename);
    Engine engine{settings};

    engine.create_hero(Heros::dude);
    engine.run();
}
\