#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <d3dx9.h>

#include "GameGlobal.h"

class Camera
{
public:
    Camera(int width, int height, D3DXVECTOR3 pos);
    ~Camera();

    void SetWidth(int width);
    int GetWidth();
    void SetHeight(int height);
    int GetHeight();

    void SetPosition(float x, float y);
    D3DXVECTOR3 GetPosition();

	static Camera *GetInstance();

	// Transform a point in the view port coordinate systems to world coordinate
	void TransformToWorld(D3DXVECTOR2 *point);

private:
	Camera();

private:
	static Camera *mInstance;

	// Transformation matrix
	D3DXMATRIX mTransform;

    int mWidth;
    int mHeight;

    D3DXVECTOR3 mPosition;
};

#endif // !_CAMERA_H_