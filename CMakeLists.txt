cmake_minimum_required(VERSION 3.15)
project(game)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

# Include required libraries
find_package(Lua REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

# mixer is not currently used
#find_package(SDL2_mixer REQUIRED)

include_directories(
        ${LUA_INCLUDE_DIR}
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS}
        ${SDL2_TTF_INCLUDE_DIRS})
        #${SDL2_MIXER_INCLUDE_DIRS})

# Define the sources
list(APPEND SOURCES
        src/game.cpp
        src/component.h
        src/entity.cpp src/entity.h
        src/entity_manager.cpp src/entity_manager.h
        src/components/transform_component.cpp src/components/transform_component.h
        src/texture_manager.cpp src/texture_manager.h
        src/asset_manager.cpp src/asset_manager.h
        src/components/sprite_component.cpp src/components/sprite_component.h
        src/animation.cpp src/animation.h
        src/components/keyboard_control_component.cpp src/components/keyboard_control_component.h
        src/map.cpp src/map.h
        src/components/tile_component.cpp src/components/tile_component.h
        src/collision.cpp src/collision.h
        src/components/collider_component.cpp src/components/collider_component.h
        src/font_manager.cpp src/font_manager.h
        src/components/text_label_component.cpp src/components/text_label_component.h
        src/components/projectile_emitter_component.cpp src/components/projectile_emitter_component.h)

add_library(sources_lib ${SOURCES})

# Build the executable
add_executable(game src/main.cpp)

target_link_libraries(game
        sources_lib
        ${LUA_LIBRARIES}
        ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES})
        #${SDL2_MIXER_LIBRARIES})

enable_testing()
add_subdirectory(tests)