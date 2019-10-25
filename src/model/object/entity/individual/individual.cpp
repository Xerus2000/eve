#include "individual.h"

int Individual::numberOfIndividuals = 0;
Individual::Individual(int x, int y, int energy) :
    Entity(x, y, energy),
    ID(numberOfIndividuals)
{numberOfIndividuals++;}

int Individual::getID() {return ID;}

int Individual::getVisionRange() { return visionRange;}

Action * Individual::act(std::vector<Object *> * visibles) {return new Sleep();}
