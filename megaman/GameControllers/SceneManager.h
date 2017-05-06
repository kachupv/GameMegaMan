#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_



#include "../GameComponents/Scene.h"

class SceneManager
{
public:
    static SceneManager *GetInstance();
    ~SceneManager();

    Scene *GetCurrentScene();
    void SetCurrentScene(Scene *scene);
    void Update(float delta);

private:
    SceneManager();
    static SceneManager *mInstance;
    Scene *mCurrentScene;
};

#endif // !_SCENE_MANAGER_H_