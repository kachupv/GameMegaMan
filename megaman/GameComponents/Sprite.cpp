#include "Sprite.h"

Sprite::Sprite(const char* filePath, int width, int height, int count, int spritePerRow, D3DCOLOR colorKey)
{
    mWidth = width;
    mHeight = height;
    mIndex = 0;
    mCount = count;
    mSpritePerRow = spritePerRow;
    mSpriteHandler = GameGlobal::GetCurrentSpriteHandler();

    D3DXIMAGE_INFO imageInfo;
    HRESULT result = D3DXGetImageInfoFromFileA(filePath, &imageInfo);
    if (D3D_OK != result)
    {
        trace(L"[ERROR] Failed to get information from image file '%s'", filePath);
        return;
    }
    

    LPDIRECT3DDEVICE9 device;
    mSpriteHandler->GetDevice(&device);

    // default transColor
    if (colorKey == NULL)
    {
        colorKey = GameGlobal::GetTransColor();
    }

    result = D3DXCreateTextureFromFileExA(
        device,
        filePath,
        imageInfo.Width,
        imageInfo.Height,
        1,
        D3DUSAGE_DYNAMIC,
        D3DFMT_UNKNOWN,
        D3DPOOL_DEFAULT,
        D3DX_DEFAULT,
        D3DX_DEFAULT,
        colorKey,
        &imageInfo,
        NULL,
        &mTexture);

    if (D3D_OK != result)
    {
        trace(L"[ERROR] Failed to create texture from file '%s'", filePath);
        return;
    }
}

Sprite::Sprite(const char *filePath) :
Sprite(filePath, 0, 0, 0, 0, NULL)
{
}

Sprite::Sprite()
{
}

Sprite::~Sprite()
{
    if (mTexture != NULL)
    {
        mTexture->Release();
        mTexture = NULL;
    }
}

void Sprite::Render(D3DXVECTOR2 Scaling, float Rotation, D3DXVECTOR2 Pos)
{
    // Get rectangle of a frame's sprite
    RECT srcRect = this->GetRect();

    // Texture being used is mWidth by mHeight
    D3DXVECTOR2 spriteCentre = D3DXVECTOR2((float)mWidth / 2, (float)mHeight / 2);

    // Screen position of the sprite
	D3DXVECTOR2 position = Pos;
	Camera::GetInstance()->TransformToWorld(&position);

    // Rotate based on the time passed
    float rotation = Rotation;

    // a point identifying the scale.
    D3DXVECTOR2 scaling = Scaling;

    // Build our matrix to rotate, scale and position our sprite
	D3DXMATRIX transform;

    // Get matrix origin
    D3DXMATRIX origin;
    //mSpriteHandler->GetTransform(&origin);

    // scaling centre, scaling rotation, scaling, rotation centre, rotation, translation
    //D3DXMatrixTransformation2D(&transform, NULL, 0.0, &scaling, &spriteCentre, rotation, &trans);

	D3DXMatrixIdentity(&transform);
	transform._11 = scaling.x;
	transform._22 = scaling.y;

    // Tell the sprite about the matrix
    //mSpriteHandler->SetTransform(&transform);

    // Draw the sprite 
    mSpriteHandler->Draw(mTexture,
        &srcRect,
        &D3DXVECTOR3(spriteCentre.x, spriteCentre.y, 0),
        &D3DXVECTOR3(position.x, position.y, 0),
        D3DCOLOR_ARGB(255, 255, 255, 255));

    // Tell the sprite about the matrix origin
    //mSpriteHandler->SetTransform(&origin);
}

void Sprite::Next()
{
    mIndex = (mIndex + mCount - 1) % mCount;
}

void Sprite::Reset()
{
    mIndex = 0;
}

RECT Sprite::GetRect()
{
    RECT rect;
    rect.left = (mIndex % mSpritePerRow)*(mWidth)+1;
    rect.top = (mIndex / mSpritePerRow)*(mHeight)+1;
    rect.right = rect.left + mWidth;
    rect.bottom = rect.top + mHeight;

    return rect;
}

void Sprite::SetIndex(int index)
{
    mIndex = index;
}

int Sprite::GetIndex()
{
    return mIndex;
}