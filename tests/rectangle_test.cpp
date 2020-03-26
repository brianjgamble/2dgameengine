#include "../src/rectangle.h"
#include <catch.hpp>

TEST_CASE("Isolated rectangles do not collide") {
    Rectangle a {0, 0, 5, 5};
    Rectangle b {6, 6, 5, 5};

    REQUIRE_FALSE(a.collides(b));
}

TEST_CASE("Overlaying rectangles collide") {
    Rectangle a {0, 0, 5, 5};
    Rectangle b {0, 0, 5, 5};

    REQUIRE(a.collides(b));
}

TEST_CASE("Overlapping rectangles collide") {
    Rectangle a {0, 0, 5, 5};
    Rectangle b {4, 4, 5, 5};

    REQUIRE(a.collides(b));
}

TEST_CASE("Rectangles sharing a single coordinate collide") {
    Rectangle a {0, 0, 5, 5};
    Rectangle b {5, 5, 5, 5};

    REQUIRE(a.collides(b));
}

TEST_CASE("Rectangles with the same values are equal") {
    Rectangle a {0, 0, 5, 5};
    Rectangle b {0, 0, 5, 5};

    REQUIRE(a == b);
}

TEST_CASE("A rectangle can be copied from another rectangle") {
    Rectangle a {0, 0, 5, 5};
    Rectangle b {a};

    REQUIRE(a == b);
}

TEST_CASE("Subtract two rectangles returns a coordinate") {
    Rectangle a {10, 7, 10, 10};
    Rectangle b {3, 4, 5, 5};

    auto coord = a - b;
    REQUIRE(coord.x == 7);
    REQUIRE(coord.y == 3);
}

TEST_CASE("Default constructor sets all values to 0") {
    Rectangle a {};
    Rectangle b {0, 0, 0, 0};

    REQUIRE(a == b);
}

TEST_CASE("A rectangle can be moved") {
    Rectangle a {10, 7, 10, 10};
    Coordinate newCoord {5, 15};

    a.moveTo(newCoord);
    REQUIRE(a.getCoordinate() == newCoord);
}

TEST_CASE("A rectangle can be resized") {
    Rectangle a {10, 7, 10, 10};
    Dimensions newDim {20, 30};

    a.resize(newDim);
    REQUIRE(a.getDimensions() == newDim);
}