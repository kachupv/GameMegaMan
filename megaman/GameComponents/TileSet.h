#ifndef _TILE_SET_H_
#define _TILE_SET_H_

#include "Sprite.h"


class TileSet : public Sprite
{
public:
    TileSet(const char *fileTileSet, int tileWidth, int tileHeight, int spacing, int margin, int tileCount, int columns);
    ~TileSet();

    // override GetRect() 
    RECT GetRect();
private:
    TileSet();

protected:
    int mSpacing;
    int mMargin;
};

#endif // !_TILE_SET_H_