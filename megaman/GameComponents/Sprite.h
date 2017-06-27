#ifndef _SPRITE_H_
#define _SPRITE_H_
#include <d3d9.h>
#include <d3dx9.h>

#include "../Utils/trace.h"
#include "GameGlobal.h"
#include "Camera.h"

class Sprite
{
public:
	// This constructor to create the sprites for animation object
    Sprite(const char *filePath, int width, int height, int count, int spritePerRow, D3DCOLOR colorKey = NULL);
	// This constructor to create the tilesets object
	Sprite(const char *filePath); 
    ~Sprite();

    // Render current sprite with a scale, rotation and position
    void Render(D3DXVECTOR2 Scaling, float Rotation, D3DXVECTOR2 Pos);

    // Advance to next sprite
    void Next();

    // Reset current sprite index to 0
    void Reset();

    // Get rectangle of current sprite
    virtual RECT GetRect();

    // Set/get current sprite index
    void SetIndex(int index);
    int GetIndex();

protected:
    Sprite();

    LPDIRECT3DTEXTURE9 mTexture;
    LPD3DXSPRITE mSpriteHandler;

    int mIndex;                // Current sprite index
    int mWidth;                // Sprite width
    int mHeight;               // Sprite height
    int mCount;                // Number of sprites
    int mSpritePerRow;         // Number of sprites per row
};
#endif // !_SPRITE_H_