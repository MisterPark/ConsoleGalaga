#include "stdafx.h"
#include "Camera.h"
#include "ObjectManager.h"

Camera* instance = nullptr;

Camera::Camera()
{
  width = 50;
  height = 50;
  bufferCount = width * height;
  Console::SetSize(height, width * 2);
  Console::SetCursorInfo(1, false);

  buffer = new WCHAR[(width+1) * height];
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width+1; j++)
    {
      buffer[i * (width+1) + j] = L'¡¡';
      if (j == width)
      {
        buffer[i * (width+1)+j] = L'\n';
      }
    }
  }

  buffer2 = new WCHAR[(width+1) * height];
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width+1; j++)
    {
      buffer2[i * (width + 1) + j] = L'¡¡';
      if (j == width)
      {
        buffer2[i * (width+1) + j] = L'\n';
      }
    }
    
  }
  currentBuffer = buffer;
  nextBuffer = buffer2;
}

Camera::~Camera()
{
  if (buffer)
  {
    delete[] buffer;
    buffer = nullptr;
  }

  if (buffer2)
  {
    delete[] buffer2;
    buffer2 = nullptr;
  }
}

Camera* Camera::GetInstance()
{
  if (instance == nullptr)
  {
    instance = new Camera();
  }
  return instance;
}

void Camera::Destroy()
{
  if (instance)
  {
    delete instance;
    instance = nullptr;
  }
}

void Camera::Update()
{
  Camera::GetInstance();
}

void Camera::Clear()
{
  for (int i = 0; i < instance->height; i++)
  {
    for (int j = 0; j < instance->width+1; j++)
    {
      instance->currentBuffer[i * (instance->width+1) + j] = L'¡¡';
      if (j == instance->width)
      {
        if (i == instance->height - 1)
        {
          instance->currentBuffer[i * (instance->width+1) + j] = L'\0';
        }
        else
        {
          instance->currentBuffer[i * (instance->width+1) + j] = L'\n';
        }
      }
    }

    
    
  }
}

void Camera::Render()
{
  Camera::GetInstance();
  Console::SetCursorPosition(0, 0);
  Console::Write(instance->currentBuffer);
}

Vector2& Camera::GetPosition()
{
  return position;
}

WCHAR* Camera::GetBuffer()
{
  return currentBuffer;
}


bool Camera::IsOutOfRange(GameObject* obj)
{
  int x = obj->GetPosition().x;
  int y = obj->GetPosition().y;
  int w = obj->shape.width;
  int h = obj->shape.height;

  if (x+w < 0) return true;
  if (y+h < 0) return true;
  if (x > width) return true;
  if (y > height) return true;
  return false;
}

void Camera::Swapchain()
{
  WCHAR* buf = currentBuffer;
  currentBuffer = nextBuffer;
  nextBuffer = buf;
}
