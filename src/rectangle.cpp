#include "rectangle.h"

bool Rectangle::collides(const Rectangle& that) {
    return (x + w >= that.x && that.x + that.w >= x && y + h >= that.y &&
            that.y + that.h >= y);
}
