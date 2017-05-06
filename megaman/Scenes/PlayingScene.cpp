#include "PlayingScene.h"

#define MEGAMAN_SPEED 1.0f
#define GROUND_Y 40

#define ANIMATE_RATE 60

PlayingScene::PlayingScene()
{
    Init();
}


PlayingScene::~PlayingScene()
{
    if (mMegaMan != NULL)
    {
        delete mMegaMan;
        mMegaMan = NULL;
    }
}

void PlayingScene::Init()
{
    const char *filePath = "MegaManStand.png";
    mMegaMan = new Animation(filePath, 24, 24, 3, 3);

	mPosMegaMan = D3DXVECTOR3(100, GROUND_Y, 0);
	mMegaMan->SetPosition(mPosMegaMan);

	mMegaManVx = 0.0f;
	mMegaManVy = 0.0f;
	mMegaManVxLast = 1.0f;	
}

void PlayingScene::Update(float delta)
{
    //mMegaMan->Update(delta);

	// TO-DO: should enhance CGame to put a separate virtual method for updating game status


	// NOTES: If there is a class for kitty, this should be Kitty->Update(t);
	// Update kitty status
	mPosMegaMan.x += mMegaManVx * delta;
	mPosMegaMan.y += mMegaManVy * delta;

	// Animate kitty if she is running
	DWORD now = GetTickCount();
	if (now - mLastTime > 100 / ANIMATE_RATE)
	{
		mMegaMan->Next();
		mLastTime = now;
	}
}

void PlayingScene::Draw()
{
	mMegaMan->Draw(mPosMegaMan.x, mPosMegaMan.y);
}

void PlayingScene::OnKeyDown(int keyCode)
{
	switch (keyCode)
	{
	case VK_SPACE:
		if (mPosMegaMan.y >= GROUND_Y)
		{
			mMegaManVy -= 3.0f;			// start jump if is not "on-air"
		}
		mMegaMan->SetPosition(mMegaMan->GetPosition() + D3DXVECTOR3(mPosMegaMan.x, mPosMegaMan.y, 0));
		break;
	}
	
}

void PlayingScene::ProcessInput(bool up, bool down, bool left, bool right)
{
	if (up)
	{

	}
	else if (down)
	{

	}
	else if (left)
	{
		mMegaManVx = -MEGAMAN_SPEED;
		mMegaManVxLast = mMegaManVx;
		
	}
	else if (right)
	{

		if (!mMegaMan->IsFlipVertical())
		{
			mMegaMan->FlipVertical(true);
		}

		mMegaManVx = MEGAMAN_SPEED;
		mMegaManVxLast = mMegaManVx;
	}
	else
	{
		mMegaManVx = 0;
		mMegaMan->Reset();
	}
}
