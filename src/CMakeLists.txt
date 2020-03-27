# Define the sources
list(APPEND SOURCES
        components/text_label_component.cpp
        components/projectile_emitter_component.cpp
        components/collider_component.cpp
        components/tile_component.cpp
        components/keyboard_control_component.cpp
        components/sprite_component.cpp
        components/transform_component.cpp
        components/joystick_control_component.cpp
        components/sound_control_component.cpp
        game.cpp
        entity.cpp
        entity_manager.cpp
        asset_manager.cpp
        animation.cpp
        map.cpp
        font_manager.cpp
        levels.cpp
        sound.cpp
        renderer.cpp
        locator.cpp
        video_manager.cpp
        texture.cpp
        rectangle.cpp
        engine.cpp)

# Define source library
add_library(sources_lib ${SOURCES})

# Build the executable
add_executable(game main.cpp)
target_link_libraries(game
        sources_lib
        ${LUA_LIBRARIES}
        ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        ${SDL2_MIXER_LIBRARIES})
