#include <Windows.h>

#include "GameComponents/GameMegaMan.h"

#define GAME_NAME "Game Megaman"
#define FPS 60

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	GameMegaMan megaMan(hInstance, GAME_NAME, 60);

	megaMan.Init();
	megaMan.Run();

	return 0;
}