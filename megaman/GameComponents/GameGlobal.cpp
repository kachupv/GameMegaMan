#include "GameGlobal.h"

LPD3DXSPRITE GameGlobal::mSpriteHandler = NULL;
int GameGlobal::mWidth = 256;
int GameGlobal::mHeight = 224;
LPDIRECT3DDEVICE9 GameGlobal::mDevice = nullptr;
D3DXCOLOR GameGlobal::mTransColor = D3DCOLOR_XRGB(0, 102, 102);

GameGlobal::GameGlobal()
{

}


GameGlobal::~GameGlobal()
{
}

void GameGlobal::SetCurrentDevice(LPDIRECT3DDEVICE9 device)
{
    mDevice = device;
}

LPDIRECT3DDEVICE9 GameGlobal::GetCurrentDevice()
{
    return mDevice;
}

void GameGlobal::SetCurrentSpriteHandler(LPD3DXSPRITE spriteHandler)
{
    mSpriteHandler = spriteHandler;
}

LPD3DXSPRITE GameGlobal::GetCurrentSpriteHandler()
{
    return mSpriteHandler;
}

void GameGlobal::SetWidth(int width)
{
    mWidth = width;
}

int GameGlobal::GetWidth()
{
    return mWidth;
}

void GameGlobal::SetHeight(int height)
{
    mHeight = height;
}

int GameGlobal::GetHeight()
{
    return mHeight;
}

D3DXCOLOR GameGlobal::GetTransColor()
{
    return mTransColor;
}
void GameGlobal::SetTransColor(D3DXCOLOR keyColor)
{
    mTransColor = keyColor;
}