#ifndef _PLAYING_SCENE_H_
#define _PLAYING_SCENE_H_

#include "../GameComponents/Scene.h"
#include "../GameComponents/Sprite.h"
#include "../GameComponents/TileSet.h"
#include "../GameComponents/GameMap.h"
#include "../GameComponents/Camera.h"
#include "../GameObjects/Player/Player.h"

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
	Player *player;
    //Sprite *mMegaman;

    //GameMap *mGameMap;

    // Position of megaman
    float mMegamanX;
    float mMegamanY;

    // Velocity of megaman
    float mMegamanVx;
    float mMegamanVy;

    // Last Vx of megaman before stop (to determine the direction of megaman)
    float mMegamanLastVx;

    // this is to control the animate rate of MegaMan
    DWORD mLastTime;
    
    // Megaman in the reverse direction
    int mReverse;
};


#endif // !_PLAYING_SCENE_H_