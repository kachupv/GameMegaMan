#ifndef _GAMEGLOBAL_H_
#define _GAMEGLOBAL_H_

#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>


class GameGlobal
{
public:
    GameGlobal();
    ~GameGlobal();

    static void SetCurrentSpriteHandler(LPD3DXSPRITE spriteHandler);
    static LPD3DXSPRITE GetCurrentSpriteHandler();

    static void SetCurrentDevice(LPDIRECT3DDEVICE9 device);
    static LPDIRECT3DDEVICE9 GetCurrentDevice();

    static void SetWidth(int width);
    static int GetWidth();

    static void SetHeight(int height);
    static int GetHeight();

    static D3DXCOLOR GetTransColor();
    static void SetTransColor(D3DXCOLOR keyColor);

private:
    static LPD3DXSPRITE mSpriteHandler; //This object to drawing sprites using D3D
    static int mWidth, mHeight;            // size window
    static LPDIRECT3DDEVICE9 mDevice;
    static D3DXCOLOR mTransColor;        // transparency
};

#endif // !_GAMEGLOBAL_H_