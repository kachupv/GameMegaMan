#include "GameMegaMan.h"


GameMegaMan::GameMegaMan(HINSTANCE hInstance, LPCSTR name, int frameRate):
Game(hInstance, name, frameRate)
{
}

GameMegaMan::~GameMegaMan()
{
}


void GameMegaMan::Draw()
{
	SceneManager::GetInstance()->GetCurrentScene()->Draw();
}

void GameMegaMan::Update(float delta)
{
	SceneManager::GetInstance()->GetCurrentScene()->Update(delta);
	Render();
}

void GameMegaMan::ProcessInput()
{
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;

	if (IsKeyDown(DIK_UP))
	{
		up = true;
	}
	else if (IsKeyDown(DIK_DOWN))
	{
		down = true;
	}
	else if (IsKeyDown(DIK_LEFT))
	{
		left = true;
	}
	else if (IsKeyDown(DIK_RIGHT))
	{
		right = true;
	}


	SceneManager::GetInstance()->GetCurrentScene()->ProcessInput(up, down, left, right);
}

void GameMegaMan::LoadResources()
{
	// set current scene is Playing scene
	SceneManager::GetInstance()->SetCurrentScene(new PlayingScene());
}

void GameMegaMan::OnKeyDown(int keyCode)
{
	SceneManager::GetInstance()->GetCurrentScene()->OnKeyDown(keyCode);
}