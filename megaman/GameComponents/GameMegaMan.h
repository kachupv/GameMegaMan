#ifndef _GAME_MEGAMAN_H_
#define _GAME_MEGAMAN_H_

#include <d3dx9.h>

#include "Game.h"
#include "Scene.h"
#include "../GameControllers/SceneManager.h"
#include "../Scenes/PlayingScene.h"

class GameMegaMan : public Game
{
public:
	GameMegaMan(HINSTANCE hInstance, LPWSTR name, int frameRate);
    ~GameMegaMan();

protected:
    LPDIRECT3DSURFACE9 _Background;

    // load/init game
    virtual void LoadResources();

    // draw game
    void Draw();
    void Update(float delta);

    // handle keys left/right/up/down
    void ProcessInput();
    // handle key space
    void OnKeyDown(int keyCode);
};

#endif // !_GAME_MEGAMAN_H_