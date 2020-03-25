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