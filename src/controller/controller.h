#ifndef EVE_CONTROLLER_H
#define EVE_CONTROLLER_H

#include "../config.h"
#include "../model/object/entity/food/food.h"
#include "../model/object/entity/individual/fred/fred.h"
#include "../model/object/entity/individual/piercy/piercy.h"
#include "../model/random/random.h"
#include "../view/terminalview/terminalview.h"
#include "../view/sdlview/sdlview.h"
#include "../model/world/world.h"

#include <cmath>
#include <stdexcept>
#include <vector>

class Controller {
private:
    long iteration = 0;
    bool initialised = false;

    bool simulate();
public:
    World world;
    TerminalView terminalview;
    SDLView sdlview;

    Controller(double WIDTH, double HEIGHT, double ENERGY);

    void init();
    long run();
};

#endif //EVE_CONTROLLER_H
