#include "Animation.h"

Animation::Animation()
{

}

Animation::Animation(const char* filePath, int width, int height, int count, int spritePerRow)
{
	this->InitWithSprite(filePath);

	mWidth = width;
	mHeight = height;
	mCount = count;
	mSpritePerRow = spritePerRow;
	mIndex = 0;
}

Animation::~Animation()
{
}

void Animation::Draw(float x, float y)
{
	RECT srect;

	srect.left = (mIndex % mSpritePerRow)*(mWidth)+1;
	srect.top = (mIndex / mSpritePerRow)*(mHeight)+1;
	srect.right = srect.left + mWidth;
	srect.bottom = srect.top + mHeight + 1;

	D3DXVECTOR3 position(x, y, 0);

	Sprite::Draw(position, srect);
}

void Animation::Next()
{
	mIndex = (mIndex + mCount - 1) % mCount;
}

void Animation::Reset()
{
	mIndex = 0;
}