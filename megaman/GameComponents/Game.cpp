#include "Game.h"

Game::Game(HINSTANCE hInstance, LPWSTR Name, int FrameRate)
{
    mD3d = NULL;
    mD3ddv = NULL;

    mDirectInput = NULL;
    mKeyboard = NULL;

    mName = Name;
    mFrameRate = FrameRate;

    mHInstance = hInstance;

    mScreenWidth = 256;
    mScreenHeight = 224;
}

void Game::InitWindow()
{
    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);

	//fill the struct with info
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)Game::WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = this->mHInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = this->mName;
	wc.hIconSm = NULL;

	//set up the window with the class info
	RegisterClassEx(&wc);

    mHWnd =
        CreateWindow(
        mName,
        mName,
		WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        mScreenWidth,
        mScreenHeight,
        NULL,
        NULL,
        mHInstance,
        NULL);

    if (!mHWnd)
    {
        trace(L"[ERROR] Failed to created window!");
        DWORD ErrCode = GetLastError();
    }

    ShowWindow(mHWnd, SW_SHOWNORMAL);
    UpdateWindow(mHWnd);
}

void Game::InitDirectX()
{
    mD3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (this->mD3d == NULL)
	{
		trace(L"[ERROR] Failed initializing Direct3D");
		return;
	}

	//set Direct3D presentation parameters
    D3DPRESENT_PARAMETERS d3dpp;

    ZeroMemory(&d3dpp, sizeof(d3dpp));

    d3dpp.Windowed = TRUE;

    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;

	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
    d3dpp.BackBufferCount = 1;
    d3dpp.BackBufferHeight = mScreenHeight;
    d3dpp.BackBufferWidth = mScreenWidth;

	//create Direct3D device
    mD3d->CreateDevice(
        D3DADAPTER_DEFAULT,
        D3DDEVTYPE_HAL,
        mHWnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING,
        &d3dpp,
        &mD3ddv);

    if (mD3ddv == NULL)
    {
        trace(L"[ERROR] Failed to created Directx!");
		return;
    }

    GameGlobal::SetCurrentDevice(mD3ddv);
	// create SpriteHandler
	if (D3DXCreateSprite(GameGlobal::GetCurrentDevice(), &mSpriteHandler) != D3D_OK)
	{
		trace(L"[ERROR] Failed to create Sprite Handler");
		return;
	}
    GameGlobal::SetCurrentSpriteHandler(mSpriteHandler);
}

void Game::InitKeyboard()
{
    HRESULT
        hr = DirectInput8Create
        (
        mHInstance,
        DIRECTINPUT_VERSION,
        IID_IDirectInput8, (VOID**)&mDirectInput, NULL
        );

    // TO-DO: put in exception handling
    if (hr != DI_OK) return;

    trace(L"DirectInput has been created");

    hr = mDirectInput->CreateDevice(GUID_SysKeyboard, &mKeyboard, NULL);

    // TO-DO: put in exception handling
    if (hr != DI_OK) return;

    trace(L"DirectInput keyboard has been created");

    // Set the data format to "keyboard format" - a predefined data format 
    //
    // A data format specifies which controls on a device we
    // are interested in, and how they should be reported.
    //
    // This tells DirectInput that we will be passing an array
    // of 256 bytes to IDirectInputDevice::GetDeviceState.

    hr = mKeyboard->SetDataFormat(&c_dfDIKeyboard);

    trace(L"SetDataFormat for keyboard successfully");

    hr = mKeyboard->SetCooperativeLevel(mHWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

    trace(L"SetCooperativeLevel for keyboard successfully");

    // IMPORTANT STEP TO USE BUFFERED DEVICE DATA!
    //
    // DirectInput uses unbuffered I/O (buffer size = 0) by default.
    // If you want to read buffered data, you need to set a nonzero
    // buffer size.
    //
    // Set the buffer size to DINPUT_BUFFERSIZE (defined above) elements.
    //
    // The buffer size is a DWORD property associated with the device.
    DIPROPDWORD dipdw;

    dipdw.diph.dwSize = sizeof(DIPROPDWORD);
    dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
    dipdw.diph.dwObj = 0;
    dipdw.diph.dwHow = DIPH_DEVICE;
    dipdw.dwData = KEYBOARD_BUFFER_SIZE; // Arbitary buffer size

    trace(L"SetProperty for keyboard successfully");

    hr = mKeyboard->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);
    if (hr != DI_OK) return;

    hr = mKeyboard->Acquire();
    if (hr != DI_OK) return;

    trace(L"Keyboard has been acquired successfully");
}
void Game::Init()
{
    InitWindow();
    InitDirectX();
    InitKeyboard();
    LoadResources();
}

void Game::Render()
{
    auto device = GameGlobal::GetCurrentDevice();

    device->Clear(0, NULL, D3DCLEAR_TARGET, 0x4866ff, 0.0f, 0);
    //start rendering
    if (device->BeginScene())
    {
        //Prepares device for drawing sprites
        GameGlobal::GetCurrentSpriteHandler()->Begin(D3DXSPRITE_ALPHABLEND);

        // draw here
        Draw();

        //Restores device state
        GameGlobal::GetCurrentSpriteHandler()->End();

        //stop rendering
        device->EndScene();
    }
    //display the back buffer on the screen
    device->Present(0, 0, 0, 0);
}

void Game::Update(float delta)
{
    
}

void Game::Draw()
{
    //mD3ddv->Clear(0, NULL, D3DCLEAR_TARGET, 0x4866ff, 0.0f, 0);
}

void Game::ProcessKeyBoard()
{
    // Collect all key states first
    mKeyboard->GetDeviceState(sizeof(mKeyStates), mKeyStates);

    if (IsKeyDown(DIK_ESCAPE))
    {
        trace(L"Escape key pressed!");
        PostMessage(mHWnd, WM_QUIT, 0, 0);
    }

    // Collect all buffered events
    DWORD dwElements = KEYBOARD_BUFFER_SIZE;
    HRESULT hr = mKeyboard->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), mKeyEvents, &dwElements, 0);

    // Scan through all data, check if the key is pressed or released
    for (DWORD i = 0; i < dwElements; i++)
    {
        int KeyCode = mKeyEvents[i].dwOfs;
        int KeyState = mKeyEvents[i].dwData;
        if ((KeyState & 0x80) > 0)
            OnKeyDown(KeyCode);
        else
            OnKeyUp(KeyCode);
    }
}

// Main game message loop
void Game::Run()
{
    MSG msg;
    int done = 0;
    DWORD start = GetTickCount();;

    DWORD tickPerFrame = 100 / mFrameRate;

    trace(L">>> Main game loop has been started");

    while (!done)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT) done = 1;

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        DWORD end = GetTickCount();
        mDeltaTime = end - start;
        if (mDeltaTime >= tickPerFrame)
        {
            start = end;
            Update(mDeltaTime);
            Render();
        }

        ProcessKeyBoard();

        ProcessInput();
    }

    trace(L"Main game loop has ended");
}


void Game::LoadResources() { }

void Game::ProcessInput() { }

Game::~Game()
{
    if (mD3ddv != NULL) mD3ddv->Release();
    if (mD3d != NULL) mD3d->Release();

    if (mKeyboard)
    {
        mKeyboard->Unacquire();
        mKeyboard->Release();
    }

    if (mDirectInput) mDirectInput->Release();
}

int Game::IsKeyDown(int keyCode)
{
    return (mKeyStates[keyCode] & 0x80) > 0;
}

void Game::OnKeyDown(int keyCode)
{

}

void Game::OnKeyUp(int keyCode)
{

}

LRESULT CALLBACK Game::WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}