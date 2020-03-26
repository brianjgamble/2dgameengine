#include "rectangle.h"

bool Coordinate::operator==(const Coordinate& c) const {
    return x == c.x && y == c.y;
}

bool Dimensions::operator==(const Dimensions& d) const {
    return w == d.w && h == d.h;
}

bool Rectangle::operator==(const Rectangle& that) const {
    return x == that.x && y == that.y && w == that.w && h == that.h;
}

Coordinate Rectangle::operator-(const Rectangle& r) {
    return Coordinate {x - r.x, y - r.y};
}

bool Rectangle::collidesWith(const Rectangle& that) const {
    return (x + w >= that.x && that.x + that.w >= x && y + h >= that.y &&
            that.y + that.h >= y);
}

void Rectangle::moveTo(const Coordinate& c) {
    x = c.x;
    y = c.y;
}
Coordinate Rectangle::getCoordinate() const {
    return Coordinate {x, y};
}

void Rectangle::resize(const Dimensions& d) {
    w = d.w;
    h = d.h;
}

Dimensions Rectangle::getDimensions() const {
    return Dimensions {w, h};
}
