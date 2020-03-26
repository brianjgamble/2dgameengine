#ifndef GAME_RECTANGLE_H
#define GAME_RECTANGLE_H

struct Coordinate {
    int x;
    int y;

    bool operator==(const Coordinate& c) const;
};

struct Dimensions {
    int w;
    int h;

    bool operator==(const Dimensions& d) const;
};

class Rectangle {
  public:
    Rectangle() = default;
    Rectangle(int x, int y, int width, int height)
        : x {x}, y {y}, w {width}, h {height} {}
    Rectangle(const Rectangle& r) = default;

    bool operator==(const Rectangle& that) const;
    Coordinate operator-(const Rectangle& r);
    bool collides(const Rectangle& that);
    void moveTo(const Coordinate& c);
    void resize(const Dimensions& d);

    [[nodiscard]] Coordinate getCoordinate() const;
    [[nodiscard]] Dimensions getDimensions() const;

  private:
    int x, y;
    int w, h;
};

#endif
