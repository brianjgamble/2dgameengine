#ifndef GAME_LEVELS_H
#define GAME_LEVELS_H

#include "asset_manager.h"
#include "map.h"

class Levels {
  public:
    Levels(AssetManager* assetMgr, EntityManager& entityMgr);
    ~Levels();

    void loadLevel(int levelNumber);

  private:
    AssetManager* assetMgr;
    EntityManager& entityMgr;
    Map* map;
};

#endif
