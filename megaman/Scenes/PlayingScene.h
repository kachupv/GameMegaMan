#ifndef _PLAYING_SCENE_H_
#define _PLAYING_SCENE_H_

#include "../GameComponents/Scene.h"
#include "../GameComponents/Animation.h"

class PlayingScene : public Scene
{
public:
    PlayingScene();
    ~PlayingScene();

    void Init();
    void Update(float delta);
    void Draw();

	// Handle keys: Up/Down/Left/Right
	void ProcessInput(bool up, bool down, bool left, bool right);
    void OnKeyDown(int keyCode);


protected:
    Animation *mMegaMan;

	D3DXVECTOR3 mPosMegaMan; // position of MegaMan
	float mMegaManVx;		 // velocity of MegaMan
	float mMegaManVy;

	float mMegaManVxLast;	 //  last vx of MegaMan before stop ( to determine the direction of MegaMan)

	DWORD mLastTime;		// this is to control the animate rate of MegaMan
};


#endif // !_PLAYING_SCENE_H_