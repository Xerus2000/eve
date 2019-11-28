#include "entity.h"

Entity::Entity(double x, double y, double energy) :
    Entity(Point(x, y), energy) {}

Entity::Entity(Point position, double energy) :
    Object(position),
    energy{energy} {checkEnergy();}

void Entity::checkEnergy() const {
    if (energy <= 0) throw std::range_error("Entity::checkEnergy(): Energy has to be positive");
}

double Entity::getEnergy() const {return energy;}

void Entity::setPosition(Point p) { position = p;}
void Entity::setPosition(double x, double y) { position = Point(x, y);}

double Entity::getRadius() const { return sqrt(energy) / M_PI; }

