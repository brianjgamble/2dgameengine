# Define the test sources
list(APPEND TEST_SOURCES
        test_main.cpp
        components/transform_component_test.cpp)

add_executable(tests_game ${TEST_SOURCES})

target_include_directories(tests_game PRIVATE ../lib/catch2)
target_link_libraries(tests_game sources_lib)

add_test(
        NAME tests_game
        COMMAND tests_game --success)