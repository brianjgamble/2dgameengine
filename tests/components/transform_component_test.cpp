#include "../../src/components/transform_component.h"
#include <catch.hpp>

TransformComponent tc {11, 22, 10, 20, 5, 15, 2};

TEST_CASE("Apply the current dimensions to the given rectangle") {
    Rectangle r {};

    tc.applyDimensionsTo(r);
    auto dim = r.getDimensions();

    REQUIRE(dim.w == 5);
    REQUIRE(dim.h == 15);
}

TEST_CASE("Apply scaled dimensions to the given rectangle") {
    Rectangle r {};

    tc.applyScaledDimensionsTo(r);
    auto dim = r.getDimensions();

    REQUIRE(dim.w == 10);
    REQUIRE(dim.h == 30);
}

TEST_CASE("Apply the current position to the given rectangle") {
    Rectangle r {};

    tc.applyPositionTo(r);
    auto coord = r.getCoordinate();

    REQUIRE(coord.x == 11);
    REQUIRE(coord.y == 22);
}

TEST_CASE("Apply a factored vertical position to the given rectangle") {
    Rectangle r {};

    tc.applyVerticalFactorTo(r, 10);
    auto coord = r.getCoordinate();

    REQUIRE(coord.y == 150);
}

TEST_CASE("Calculates the distance from an origin") {
    glm::vec2 origin {5, 5};
    int val = tc.distanceFrom(origin);
    REQUIRE(val == 18);
}

TEST_CASE("Velocity can be changed") {
    float angleRadians = glm::radians(static_cast<float>(30));
    int speed = 70;

    TransformComponent expected {11, 22, 60, 35, 5, 15, 2};
    tc.setVelocity(angleRadians, speed);

    REQUIRE(tc == expected);
}

TEST_CASE("Move up changes the velocity to a negative y-axis") {
    TransformComponent expected {11, 22, 0, -50, 5, 15, 2};
    tc.moveUp();
    REQUIRE(tc == expected);
}

TEST_CASE("Move right changes the velocity to a positive x-axis") {
    TransformComponent expected {11, 22, 50, 0, 5, 15, 2};
    tc.moveRight();
    REQUIRE(tc == expected);
}

TEST_CASE("Move down changes the velocity to a positive y-axis") {
    TransformComponent expected {11, 22, 0, 50, 5, 15, 2};
    tc.moveDown();
    REQUIRE(tc == expected);
}

TEST_CASE("Move left changes the velocity to a negative x-axis") {
    TransformComponent expected {11, 22, -50, 0, 5, 15, 2};
    tc.moveLeft();
    REQUIRE(tc == expected);
}

TEST_CASE("Movement can be stopped") {
    TransformComponent expected {11, 22, 0, 0, 5, 15, 2};
    tc.stop();
    REQUIRE(tc == expected);
}

TEST_CASE("Center a rectangle") {
    TransformComponent tc2 {500, 600, 200, 200, 5, 15, 2};
    Rectangle r {20, 30, 50, 50};

    tc2.center(r);
    auto coord = r.getCoordinate();

    REQUIRE(coord.x == 50);
    REQUIRE(coord.y == 50);
}