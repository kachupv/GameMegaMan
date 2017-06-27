#include "PlayingScene.h"

#define MEGAMAN_SPEED 0.05f
#define GROUND_Y 40

#define ANIMATE_RATE 120

PlayingScene::PlayingScene()
{
    Init();
}


PlayingScene::~PlayingScene()
{
}

void PlayingScene::Init()
{
    const char *megaman = "MegaManStand.png";

    //mMegaman = new Sprite(megaman, 24, 24, 3, 3);
    mMegamanX = 100.0f;
	//mMegamanY = 100.0f;
	mMegamanY = 2096.0f;
    mMegamanVx = 0.0f;
    mMegamanVy = 0.0f;
    mMegamanLastVx = 1.0f;

    mReverse = 1;

    const char *gameMap = "CutManStage.tmx";
    const char *tileSet = "CutManTiles.png";
    //mGameMap = new GameMap(gameMap, tileSet);

	// Init camera
	Camera::GetInstance()->SetWidth(GameGlobal::GetWidth());
	Camera::GetInstance()->SetHeight(GameGlobal::GetHeight());
	//Camera::GetInstance()->SetPosition(0.0f, GameGlobal::GetHeight());
	Camera::GetInstance()->SetPosition(0.0f, 2096.0f);

}

void PlayingScene::Update(float delta)
{
    //mMegaMan->Update(delta);

    // TO-DO: should enhance CGame to put a separate virtual method for updating game status


    // NOTES: If there is a class for kitty, this should be Kitty->Update(t);
    // Update kitty status
    mMegamanX += mMegamanVx * delta;
    mMegamanY += mMegamanVy * delta;

    // Animate kitty if she is running
    DWORD now = GetTickCount();
    int id = 1;
    /*if (now - mLastTime > 1000 / ANIMATE_RATE)
    {
        if (mMegamanVx == 0)
        {
            mMegaman->Reset();
        }
        else
        {
            mMegaman->Next();
        }

        if (mMegamanVx > 0)
        {
            mReverse = -1;
        }

        if (mMegamanVx < 0)
        {
            mReverse = 1;
        }
        mLastTime = now;
    }*/
}

void PlayingScene::Draw()
{
	//mGameMap->Draw();
	//mMegaman->Render(D3DXVECTOR2(mReverse*1.0f, 1.0f), 0.0f, D3DXVECTOR2(mMegamanX, mMegamanY));
	
}

void PlayingScene::OnKeyDown(int keyCode)
{
    //switch (keyCode)
    //{
    //case VK_SPACE:
    //    if (mPosMegaMan.y >= GROUND_Y)
    //    {
    //        mMegaManVy -= 3.0f;            // start jump if is not "on-air"
    //    }
    //    break;
    //}
}

void PlayingScene::ProcessInput(bool up, bool down, bool left, bool right)
{ 
    if (left)
    {
        mMegamanVx = -MEGAMAN_SPEED;
        mMegamanLastVx = mMegamanVx;
		Camera::GetInstance()->SetPosition(Camera::GetInstance()->GetPosition().x - 10, Camera::GetInstance()->GetPosition().y);
    }
    else if (right)
    {
        mMegamanVx = MEGAMAN_SPEED;
        mMegamanLastVx = mMegamanVx;
		Camera::GetInstance()->SetPosition(Camera::GetInstance()->GetPosition().x + 10, Camera::GetInstance()->GetPosition().y);
    }
    else if (up)
    {
        mMegamanVy = -MEGAMAN_SPEED;
    }
    else if (down)
    {
        mMegamanVy = MEGAMAN_SPEED;
    }
    else
    {
        mMegamanVx = 0;
        mMegamanVy = 0;
    }
}
