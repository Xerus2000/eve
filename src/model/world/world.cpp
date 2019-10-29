#include "world.h"

World::World(int WIDTH, int HEIGHT, int ENERGY) :
    WIDTH{WIDTH},
    HEIGHT{HEIGHT},
    ENERGY{ENERGY}
{
    if (WIDTH <= 0) throw std::range_error("World(): WIDTH must be positive");
    if (HEIGHT <= 0) throw std::range_error("World(): HEIGHT must be positive");
    if (ENERGY <= 0) throw std::range_error("World(): ENERGY must be positive");

    objectLists[0] = (std::vector<Object *> *) & foods;
    objectLists[1] = (std::vector<Object *> *) & individuals;
    objectLists[2] = (std::vector<Object *> *) & obstacles;
}

World::~World() {
    for (auto food : foods) delete food;
    for (auto individual : individuals) delete individual;
}

void World::addFood(Food * food) {
    foods.push_back(food);
    incEnergy(food);
}

void World::addIndividual(Individual * individual) {
    individuals.push_back(individual);
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

std::vector<Object *> * World::getObjectsAround(const Point & position, double radius) {
    auto visibles = new std::vector<Object *>();
    for (auto objects : objectLists) {
        for (auto & object : * objects) {
            if (std::abs(object->getPosition() / position) < radius) visibles->push_back(std::move(object));
        }
    }
    return visibles;
}

void World::setRefillFunction(const std::function<Food * (World * world)> & f) {
    refillFunction = f;
}

bool World::fillWithFood(const std::function<Food * (World * world)> & f) {
    try {
        while (energy < ENERGY) addFood(f(this));
        return true;
    } catch (std::overflow_error & e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
}

bool World::fillWithFood() {
    return fillWithFood(refillFunction);
}

std::list<Individual *> World::getCemetery() {
    return cemetery;
}

bool World::kill(int ID) {
    unsigned long index = 0;
    for (auto individual : individuals) {
        if (individual->getID() == ID) {
            energy -= individual->getEnergy();
            cemetery.push_back(individual);
            individuals.erase(individuals.begin() + index);
            return true;
        }
        index++;
    }
    return false;
}