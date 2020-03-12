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
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Define source library
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