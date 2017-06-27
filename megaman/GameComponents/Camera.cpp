#include "Camera.h"

Camera *Camera::mInstance = NULL;

Camera::Camera()
{
	D3DXMatrixIdentity(&mTransform);
	mTransform._22 = -1;

	//this->SetPosition(0.0f, (float)GameGlobal::GetHeight());
}

Camera *Camera::GetInstance()
{
	if (!mInstance)
	{
		mInstance = new Camera();
	}
	return mInstance;
}


Camera::~Camera()
{
}

void Camera::SetWidth(int width)
{
    mWidth = width;
}

int Camera::GetWidth()
{
    return mWidth;
}

void Camera::SetHeight(int height)
{
    mHeight = height;
}

int Camera::GetHeight()
{
    return mHeight;
}

void Camera::SetPosition(float x, float y)
{
    mPosition = D3DXVECTOR3(x, y, 0);

	
}

D3DXVECTOR3 Camera::GetPosition()
{
    return mPosition;
}

void Camera::TransformToWorld(D3DXVECTOR2 *point)
{
	mTransform._41 = -mPosition.x;
	mTransform._42 = mPosition.y;
	D3DXVECTOR4 result;
	D3DXVec3Transform(&result, &D3DXVECTOR3(point->x, point->y, 0), &mTransform);
	point->x = result.x;
	point->y = result.y;
}
