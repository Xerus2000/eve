//
// Created by aaron on 27/09/2019.
//

#ifndef EVE_CONTROLLER_H
#define EVE_CONTROLLER_H

#include "../model/world/world.h"
#include "../model/object/entity/food/food.h"
#include "../model/object/entity/individual/fred/fred.h"

#include <cmath>
#include <vector>
#include <stdexcept>
#include <experimental/random>

#define MIN_FOOD_SIZE 20

class Controller {
private:
    int iteration = 0;
    bool initialised = false;

    bool simulate();
public:
    World world;

    Controller(int WIDTH, int HEIGHT, int ENERGY);

    void init();
    int run();
};

#endif //EVE_CONTROLLER_H
