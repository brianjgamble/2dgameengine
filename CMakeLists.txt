cmake_minimum_required(VERSION 3.15)
project(game)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

# Include required libraries
find_package(Lua REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

include_directories(
        ${LUA_INCLUDE_DIR}
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS}
        ${SDL2_TTF_INCLUDE_DIRS}
        ${SDL2_MIXER_INCLUDE_DIRS})

# Define the sources
list(APPEND SOURCES
        src/components/text_label_component.cpp
        src/components/projectile_emitter_component.cpp
        src/components/collider_component.cpp
        src/components/tile_component.cpp
        src/components/keyboard_control_component.cpp
        src/components/sprite_component.cpp
        src/components/transform_component.cpp
        src/components/joystick_control_component.cpp
        src/components/sound_control_component.cpp
        src/game.cpp
        src/entity.cpp
        src/entity_manager.cpp
        src/texture_manager.cpp
        src/asset_manager.cpp
        src/animation.cpp
        src/map.cpp
        src/collision.cpp
        src/font_manager.cpp
        src/levels.cpp
        src/sound.cpp
        src/window.cpp)

# Define source library
add_library(sources_lib ${SOURCES})

# Build the executable
add_executable(game src/main.cpp)
target_link_libraries(game
        sources_lib
        ${LUA_LIBRARIES}
        ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        ${SDL2_MIXER_LIBRARIES})

enable_testing()
add_subdirectory(tests)