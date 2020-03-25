#ifndef GAME_RECTANGLE_H
#define GAME_RECTANGLE_H

class Rectangle {
  public:
    Rectangle(int x, int y, int width, int height)
        : x {x}, y {y}, w {width}, h {height} {}

    bool collides(const Rectangle& that);

  private:
    int x, y;
    int w, h;
};

#endif
