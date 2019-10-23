#include "model.h"

Point::Point(int x, int y) : x{x}, y{y} {}

bool operator == (const Point & a, const Point & b) {
    return a.x == b.x && a.y == b.y;
}

