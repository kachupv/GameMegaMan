#include "GameGlobal.h"

HINSTANCE GameGlobal::mHInstance = NULL;
HWND GameGlobal::mHwnd = NULL;
LPD3DXSPRITE GameGlobal::mSpriteHandler = NULL;
int GameGlobal::mWidth = 800;
int GameGlobal::mHeight = 600;
LPDIRECT3DDEVICE9 GameGlobal::mDevice = nullptr;
bool GameGlobal::isGameRunning = true;
IDirect3DSurface9* GameGlobal::backSurface = nullptr;
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


HINSTANCE GameGlobal::GetCurrentHINSTACE()
{
    return mHInstance;
}

HWND GameGlobal::GetCurrentHWND()
{
    return mHwnd;
}

void GameGlobal::SetCurrentHWND(HWND hWnd)
{
    mHwnd = hWnd;
}

void GameGlobal::SetCurrentHINSTACE(HINSTANCE hInstance)
{
    mHInstance = hInstance;
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