# C++ 2D Game Engine Fundamentals

This is source code for the game that is created in a [course](https://courses.pikuma.com/courses/2dgameengine) 
which teaches 2D game engine design using C++, SDL, and Lua.  In the repo, the tag 1.0 signifies the code's state at the end of the course.  

## Requirements
 
### Tools

- [CMake](https://cmake.org)

### Libraries

- [SDL2](https://www.libsdl.org/download-2.0.php)
- [SDL_image](https://www.libsdl.org/projects/SDL_image/)
- [SDL_ttf](https://www.libsdl.org/projects/SDL_ttf/)
- [Lua](https://www.lua.org)

## What's next?

Continue working on the code to add additional features along with architectural 
changes.  I would like to separate the core game engine logic from the SDL code.

Other ideas include:

- Introduce unit tests
- Alter the design of the code
    - [Tell, Don't Ask](https://pragprog.com/articles/tell-dont-ask)
    - [Why getter and setter methods are evil](https://www.javaworld.com/article/2073723/why-getter-and-setter-methods-are-evil.html)
- Add the helicopter sound
- Add joystick controls
    - ~~dpad~~
    - analog stick