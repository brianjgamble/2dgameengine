#include "map.h"
#include "components/tile_component.h"
#include "entity_manager.h"
#include <fstream>

extern EntityManager manager;

Map::Map(const std::string& textureId, int scale, int tileSize) {
    this->textureId = textureId;
    this->scale     = scale;
    this->tileSize  = tileSize;
}

void Map::loadMap(const std::string& filePath, int mapSizeX, int mapSizeY) {
    std::fstream mapFile;
    mapFile.open(filePath);

    for (int y = 0; y < mapSizeY; y++) {
        for (int x = 0; x < mapSizeX; x++) {
            char ch;

            mapFile.get(ch);
            int sourceRectY = atoi(&ch) * tileSize;

            mapFile.get(ch);
            int sourceRectX = atoi(&ch) * tileSize;

            addTile(sourceRectX, sourceRectY, x * (scale * tileSize),
                    y * (scale * tileSize));
            mapFile.ignore();
        }
    }

    mapFile.close();
}

void Map::addTile(int sourceRectX, int sourceRectY, int x, int y) {
    Entity& newTile(manager.addEntity("Tile", LayerType::tilemap));
    newTile.addComponent<TileComponent>(sourceRectX, sourceRectY, x, y,
                                        tileSize, scale, textureId);
}
