//
// Created by janek on 17.09.19.
//

#include "world.h"

World::World(int WIDTH, int HEIGHT, int ENERGY) :
    WIDTH{WIDTH},
    HEIGHT{HEIGHT},
    ENERGY{ENERGY}
{
    if (WIDTH <= 0) throw std::range_error("World(): WIDTH must be positive");
    if (HEIGHT <= 0) throw std::range_error("World(): HEIGHT must be positive");
    if (ENERGY <= 0) throw std::range_error("World(): ENERGY must be positive");
}

World::~World() {
    for (auto food : foods) delete food;
    for (auto individual : individuals) delete individual;
}

void World::addFood(Food * food) {
    foods.emplace_back(& * food);
    incEnergy(food);
}

void World::addIndividual(Individual * individual) {
    individuals.emplace_back(& * individual);
    incEnergy(individual);
}

void World::incEnergy(Entity * entity) {
    if (energy + entity->getEnergy() > ENERGY) throw std::overflow_error("World::incEnergy(): operation exceeds ENERGY");
    energy += entity->getEnergy();
}

int World::getEnergy() {
    return energy;
}

std::vector<Food *> World::getFood() {
    return foods;
}

std::vector<Individual *> World::getIndividuals() {
    return individuals;
}

bool World::fillWithFood(const std::function<Food *(const World * world, int energy)> & f) {
    try {
        while (energy < ENERGY) addFood(f(this, energy));
        return true;
    } catch (std::overflow_error & e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
}

bool World::kill(int ID) {
    for (int i = 0; i < individuals.size(); i++){
        if (individuals[i]->getID() == ID) {
            individuals.erase(individuals.begin() + i);
            return true;
        }
    }
    return false;
}