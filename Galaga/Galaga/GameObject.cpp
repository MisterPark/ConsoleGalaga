#include "stdafx.h"
#include "GameObject.h"
#include "ObjectManager.h"
#include "Camera.h"


GameObject::GameObject()
{
  ObjectManager::AddObject(this);
}

GameObject::~GameObject()
{
  Destroy();
}

void GameObject::Render()
{
  Camera* cam = Camera::GetInstance();
  Vector2 pos = cam->GetPosition();
  WCHAR* buffer = cam->GetBuffer();
  int w = cam->GetWidth();
  int h = cam->GetHeight();
  int worldX, worldY;
  for (int i = 0; i < shape.height; i++)
  {
    for (int j = 0; j < shape.width; j++)
    {
      worldX = j + position.x;
      worldY = i + position.y;
      if (worldX < 0) continue;
      if (worldX >= w) continue;
      if (worldY < 0) continue;
      if (worldY >= h) continue;
      buffer[worldY * (w + 1) + worldX] = shape.data[i*shape.width+j];
    }
  }
  
}

void GameObject::Destroy()
{
  destroyFlag = true;
}

bool GameObject::DestroyEnabled()
{
  return destroyFlag;
}

Vector2& GameObject::GetPosition()
{
  return position;
}
