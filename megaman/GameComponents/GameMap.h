#ifndef _GAME_MAP_H_
#define _GAME_MAP_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "../MapReader/Tmx.h.in"
#include "Sprite.h"
#include "Camera.h"


class GameMap
{
public:
	GameMap(char *fileMap);
    ~GameMap();

	/*Tmx::Map* GetMap();

	int GetMapWidth();
	int GetMapHeight();
	int GetTileWidth();
	int GetTileHeight();*/

    // draw map to screen
    void Draw();

private:
	// Store contents of a map editor (.tmx)
	Tmx::Map *mMap; 
	// Store tile id for map
	std::map<int, Sprite*> mTiles;
};

#endif // !_GAME_MAP_H_