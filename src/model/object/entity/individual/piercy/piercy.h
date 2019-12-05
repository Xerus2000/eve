#ifndef EVE_PIERCY_H
#define EVE_PIERCY_H

#define FLUSH_AMOUNT 1000

#include "../individual.h"
#include "../../../object.h"
#include "../../../../action/action.h"

#include <iostream>
#include <limits>
#include <memory>

class Piercy : public Individual {
public:
    /** Constructs a new individual of species Species
     * @param ID is unique and set automatically by the World
     * @param x is the latitude of the object
     * @param y is the longitude of the object
     * @param a is the direction it's looking
     * @param energy is its life source */
    Piercy(long ID, double x, double y, double a, double energy);
    /** Constructs a new individual of species Species
     * @param ID is unique and set automatically by the World
     * @param position sets the coordinates of Species
     * @param a is the direction it's looking
     * @param energy is its life source */
    Piercy(long ID, Point position, double a, double energy);

    Piercy * reproduce (long ID) override;

    /** Waits for a key input in stdin and then returns an action based on that key. */
    Action act(const std::unique_ptr<std::vector<Object *>> & visibles) override;
};

#endif //EVE_PIERCY_H
