#ifndef _GAME_H_
#define _GAME_H_

#include <Windows.h>
#include <d3d9.h>
#include <dinput.h>

#include "../Utils/trace.h"
#include "GameGlobal.h"

#define KEYBOARD_BUFFER_SIZE    1024

class Game
{
public:
    LPDIRECT3D9 GetDirectX();
    LPDIRECT3DDEVICE9 GetDevice();
    LPDIRECT3DSURFACE9 GetBackBuffer();

    int GetScreenWidth();
    int GetScreenHeight();
    int GetDepth();

	Game(HINSTANCE hInstance, LPWSTR Name, int FrameRate);
    Game();
    ~Game();

    // Initialize the game with set parameters
    void Init();

    // Run game
    void Run();

protected:
    static LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    void InitWindow();
    void InitDirectX();
    void InitKeyboard();

    void ProcessKeyBoard();
    int IsKeyDown(int keyCode);

    // Render a single frame
    void Render();

    virtual void Draw();
    virtual void Update(float delta);
    virtual void LoadResources();

    virtual void ProcessInput();
    virtual void OnKeyDown(int keyCode);
    virtual void OnKeyUp(int keyCode);

protected:
    LPDIRECT3D9 mD3d;
    LPDIRECT3DDEVICE9 mD3ddv;
    //LPDIRECT3DSURFACE9 mBackBuffer;

    LPDIRECTINPUT8       mDirectInput;        // The DirectInput object         
    LPDIRECTINPUTDEVICE8 mKeyboard;    // The keyboard device 

    BYTE  mKeyStates[256];            // DirectInput keyboard state buffer 

    // Buffered keyboard data
    DIDEVICEOBJECTDATA mKeyEvents[KEYBOARD_BUFFER_SIZE];

    DWORD mDeltaTime;        // Time between the last frame and current frame
    int mFrameRate;

    int mScreenWidth;
    int mScreenHeight;
    int mDepth;

    HINSTANCE mHInstance;    // Handle of the game instance
    HWND mHWnd;                // Handle of the Game Window

    LPD3DXSPRITE            mSpriteHandler;

	LPWSTR mName;            // Name of game will be used as Window Class Name
};

#endif // !_GAME_H_