//
// Created by aaron on 27/09/2019.
//

#include "controller.h"

Controller::Controller(int WIDTH, int HEIGHT, int ENERGY) :
    world(World(WIDTH, HEIGHT, ENERGY))
{}

void Controller::init() {
    for (int i = 0; i < 4; i++) world.addIndividual(new Fred(10 * i, 10 * i, 40));
    world.fillWithFood([](const World * w, int e) -> Food * {
        return new Food(
                std::experimental::randint(0, w->WIDTH),
                std::experimental::randint(0, w->HEIGHT),
                (w->ENERGY - e) < MIN_FOOD_SIZE ? w->ENERGY - e : std::experimental::randint(1, MIN_FOOD_SIZE));
    });

    initialised = true;
}

int Controller::run() {
    if (not initialised) throw(std::logic_error("Controller::run(): .init() must be run first"));
    while (simulate()) iteration++;
    return iteration;
}

bool Controller::simulate() {
    world.kill(iteration);
    return not world.getIndividuals().empty();
}