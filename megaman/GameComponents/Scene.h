#ifndef _SCENE_H_
#define _SCENE_H_

#include <d3dx9.h>
#include <d3d9.h>

#include "GameGlobal.h"

class Scene
{
public:
    Scene();
    ~Scene();

    virtual void Init();
    virtual void Update(float delta);
    virtual void Draw();

    // Handle keys: Up/Down/Left/Right
    virtual void ProcessInput(bool up, bool down, bool left, bool right);
    virtual void OnKeyDown(int keyCode);
    virtual void OnKeyUp(int keyCode);
};

#endif // !_SCENE_H_