#include "stdafx.h"
#include "Camera.h"
#include "ObjectManager.h"

Camera* instance = nullptr;

Camera::Camera()
{
  CONSOLE_CURSOR_INFO cursorInfo = { 0, };
  cursorInfo.dwSize = 1; //Ä¿¼­ ±½±â (1 ~ 100)
  cursorInfo.bVisible = FALSE; //Ä¿¼­ Visible TRUE(º¸ÀÓ) FALSE(¼û±è)
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

  buffer = new WCHAR[(width + 1) * height];
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      buffer[i * (width+1) + j] = L'¡¡';
    }
    buffer[i * (width+1) + width] = L'\n';
  }

  buffer2 = new WCHAR[(width + 1) * height];
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      buffer2[i * (width + 1) + j] = L'¡¡';
    }
    buffer2[i * (width + 1) + width] = L'\n';
  }
  currentBuffer = buffer;
  nextBuffer = buffer2;
}

Camera::~Camera()
{
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
    for (int j = 0; j < instance->width; j++)
    {
      instance->nextBuffer[i * (instance->width+1) + j] = L'¡¡';
    }

    if (i == instance->height - 1)
    {
      instance->nextBuffer[i * (instance->width+1) + instance->width] = L'\0';
    }
    else
    {
      instance->nextBuffer[i * (instance->width+1) + instance->width] = L'\n';
    }
    
  }
}

void Camera::Render()
{
  Camera::GetInstance();
  instance->Swapchain();
  COORD Cur;
  Cur.X = 0;
  Cur.Y = 0;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
  //wprintf_s(instance->currentBuffer);
  DWORD writtenCount;
  WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE),
    instance->currentBuffer, 1800, &writtenCount, NULL);
  //Sleep(50);
}

Vector2& Camera::GetPosition()
{
  return position;
}

WCHAR* Camera::GetBuffer()
{
  return nextBuffer;
}

void Camera::Swapchain()
{
  WCHAR* buf = currentBuffer;
  currentBuffer = nextBuffer;
  nextBuffer = buf;
}
