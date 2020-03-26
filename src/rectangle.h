#ifndef GAME_RECTANGLE_H
#define GAME_RECTANGLE_H

struct Coordinate {
    int x;
    int y;
};

class Rectangle {
  public:
    Rectangle(int x, int y, int width, int height)
        : x {x}, y {y}, w {width}, h {height} {}
    Rectangle(const Rectangle& r) = default;

    bool operator==(const Rectangle& that) const;
    Coordinate operator-(const Rectangle& r);
    bool collides(const Rectangle& that);

  private:
    int x, y;
    int w, h;
};

#endif
