#ifndef GAME_MAP_H
#define GAME_MAP_H

#include <string>

class Map {
  public:
    Map(std::string textureId, int scale, int tileSize);
    ~Map() = default;

    void loadMap(std::string filePath, int mapSizeX, int mapSizeY);
    void addTile(int sourceRectX, int sourceRectY, int x, int y);

  private:
    std::string textureId;
    int scale;
    int tileSize;
};

#endif
