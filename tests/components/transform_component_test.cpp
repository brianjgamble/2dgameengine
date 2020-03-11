#include "../../src/components/transform_component.h"
#include <catch.hpp>

TransformComponent tc {11, 22, 10, 20, 5, 15, 2};

TEST_CASE("Update dimensions changes the width and height") {
    SDL_Rect r{};
    tc.updateDimensions(r);

    REQUIRE(r.w == 5);
    REQUIRE(r.h == 15);
}

TEST_CASE("Update scaled dimensions changes the width and height by a factor") {
    SDL_Rect r{};
    tc.updateScaledDimensions(r);

    REQUIRE(r.w == 10);
    REQUIRE(r.h == 30);
}

TEST_CASE("Update position changes the x and y") {
    SDL_Rect r{};
    tc.updatePosition(r);

    REQUIRE(r.x == 11);
    REQUIRE(r.y == 22);
}

TEST_CASE("Updates a rectangle position given a factor") {
    SDL_Rect r {};
    tc.updatePositionByFactor(r, 10);

    REQUIRE(r.y == 150);
}

TEST_CASE("Calculates the distance from an origin") {
    glm::vec2 origin {5, 5};
    int val = tc.distanceFrom(origin);
    REQUIRE(val == 18);
}