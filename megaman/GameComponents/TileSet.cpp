#include "TileSet.h"


TileSet::TileSet() : Sprite()
{}


TileSet::~TileSet()
{
}

TileSet::TileSet(const char *fileTileSet, int tileWidth, int tileHeight, int spacing, int margin, int tileCount, int columns) :
Sprite(fileTileSet, tileWidth, tileHeight, tileCount, columns)
{
    mSpacing = spacing;
    mMargin = margin;
}

RECT TileSet::GetRect()
{
    RECT srect;
    int id = this->GetIndex() - 1;
    srect.left = (id % mSpritePerRow)*mWidth + (id % mSpritePerRow)*mSpacing + mMargin;
    srect.top = (id / mSpritePerRow)*mHeight + (id / mSpritePerRow)*mSpacing + mMargin;
    srect.right = srect.left + mWidth;
    srect.bottom = srect.top + mHeight;
    return srect;
}