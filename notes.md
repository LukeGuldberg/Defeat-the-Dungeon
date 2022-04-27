# Notes one the Game

Each step for adding a feature:
- define what you want to do, e.g. Add a hero
- investigating parts of the engine that you need
- make notes on these parts
- make a detailed TODO list of what code to write
- write code
- add your results to notes

## Step 1 - Make my hero show up
Looking in `main.cpp` I see
```C++
#include "engine.h"
#include "heros.h"
engine.create_hero(Heros::nobody);
```
Characters are in `content/actors/heros.h`
``` const HeroType nodoby{"none", default_speed, 1, std::make_shared<None>(), {}};```
- "none" is the name of sprite in `assets/heros.txt`

HOMEWORK: Tour of C++
- shared_ptr, make_shared: what is the relationshi? Where do I specify the type?
- unordered_map? string & reaction
- Reaction = std::function<std::unique_ptr<Action>()>;, what is a function?

NOTES:
- shared_ptr is used to prevent memory leaks. If a regular point was used, you would have to worry about deleting the pointer. Whereas when a shared_ptr is out of scope then it automatically is deleted. 
- Make_shared is the safest way to assign value to a pointer because it makes sure that both the pointer and the value are valid (this is important because if the pointer is given some memory that is misallocated then it will not be deleted properly when it is out scope - causing a memory leak), and it is faster than assigning the pointer to a value
```C++
std::shared_ptr<Hero> h = std::make_shared<Hero>(dude)
```
- an unordered_map is filled with variables mapped out. They can have multiple values set in each spot like an item of a class. It is another container to keep data, similar to a vector but organized differently.
- Reaction = std::function<std::unique_ptr<Action>()>; 
I am a little more confused about this part, but what I think it is doing is using the pointer function (this points to a function not a variable of course), and it uses said pointer to make a reaction. Function is the name of the pointer