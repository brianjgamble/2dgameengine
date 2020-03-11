#include "../../src/components/transform_component.h"
#include <catch.hpp>

TransformComponent tc {11, 22, 10, 20, 5, 15, 2};

TEST_CASE("Apply the current dimensions to the given rectangle") {
    SDL_Rect r {};
    tc.applyDimensionsTo(r);

    REQUIRE(r.w == 5);
    REQUIRE(r.h == 15);
}

TEST_CASE("Apply scaled dimensions to the given rectangle") {
    SDL_Rect r {};
    tc.applyScaledDimensionsTo(r);

    REQUIRE(r.w == 10);
    REQUIRE(r.h == 30);
}

TEST_CASE("Apply the current position to the given rectangle") {
    SDL_Rect r {};
    tc.applyPositionTo(r);

    REQUIRE(r.x == 11);
    REQUIRE(r.y == 22);
}

TEST_CASE("Apply a factored vertical position to the given rectangle") {
    SDL_Rect r {};
    tc.applyVerticalFactorTo(r, 10);

    REQUIRE(r.y == 150);
}

TEST_CASE("Calculates the distance from an origin") {
    glm::vec2 origin {5, 5};
    int val = tc.distanceFrom(origin);
    REQUIRE(val == 18);
}