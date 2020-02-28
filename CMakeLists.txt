cmake_minimum_required(VERSION 3.15)
project(game)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

# Include required libraries
find_package(Lua REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

include_directories(
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS}
        ${SDL2_TTF_INCLUDE_DIRS}
        ${SDL2_MIXER_INCLUDE_DIRS})

# Define the sources
list(APPEND SOURCES
        src/game.cpp
        src/component.cpp src/component.h
        src/entity.cpp src/entity.h
        src/entity_manager.cpp src/entity_manager.h
        src/components/transform_component.cpp src/components/transform_component.h
        src/texture_manager.cpp src/texture_manager.h
        src/asset_manager.cpp src/asset_manager.h
        src/components/sprite_component.cpp src/components/sprite_component.h
        src/animation.cpp src/animation.h
        src/components/keyboard_control_component.cpp src/components/keyboard_control_component.h)


# Build the executable
add_executable(game src/main.cpp ${SOURCES})

target_link_libraries(game
        ${LUA_LIBRARIES}
        ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        ${SDL2_MIXER_LIBRARIES})