cmake_minimum_required(VERSION 3.15)
project(game)

set(CMAKE_CXX_STANDARD 14)

# Include required libraries
find_package(PkgConfig REQUIRED)
find_package(Lua REQUIRED)
find_package(SDL2 REQUIRED)
pkg_search_module(SDL2_image REQUIRED SDL2_image>=2.0.0)
pkg_search_module(SDL2_ttf REQUIRED SDL2_ttf>=2.0.0)
pkg_search_module(SDL2_mixer REQUIRED SDL2_mixer>=2.0.0)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL_IMAGE_INCLUDE_DIRS} $
        {SDL2_TTF_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIRS})

# Define the sources
list(APPEND SOURCES
        src/game.cpp
        src/component.cpp src/component.h
        src/entity.cpp src/entity.h
        src/entity_manager.cpp src/entity_manager.h
        src/components/transform_component.cpp src/components/transform_component.h)


# Build the executable
add_executable(game src/main.cpp ${SOURCES})

target_link_libraries(game
        ${LUA_LIBRARIES}
        ${SDL2_LIBRARIES}
        ${SDL_IMAGE_LIBRARIES}
        ${SDL_TTF_LIBRARIES}
        ${SDL_MIXER_LIBRARIES})