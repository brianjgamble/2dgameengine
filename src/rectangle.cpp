#include "rectangle.h"

bool Rectangle::operator==(const Rectangle& that) const {
    return x == that.x && y == that.y && w == that.w && h == that.h;
}

Coordinate Rectangle::operator-(const Rectangle& r) {
    return Coordinate {x - r.x, y - r.y};
}

bool Rectangle::collides(const Rectangle& that) {
    return (x + w >= that.x && that.x + that.w >= x && y + h >= that.y &&
            that.y + that.h >= y);
}
