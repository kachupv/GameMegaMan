#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include <Windows.h>
#include <d3dx9.h>
#include <d3d9.h>
#include <vector>

#include "Sprite.h"

using namespace std;

class Animation : public Sprite
{
public:
	Animation(const char* filePath, int width, int height, int count, int spritePerRow);
    Animation();
    ~Animation();

	void Next();
	void Reset();
	void Draw(float x, float y);

protected:
	int mIndex;								// Current sprite index
	int mWidth;								// Sprite width
	int mHeight;							// Sprite height
	int mCount;								// Number of sprites
	int mSpritePerRow;						// Number of sprites per row
};

#endif // !_ANIMATION_H_
