#include "stdafx.h"
#include "InputManager.h"

InputManager* InputManager::instance = nullptr;

InputManager::InputManager()
{
  memset(keypress, 0, 256);
}

InputManager::~InputManager()
{
}

InputManager* InputManager::GetInstance()
{
  if (instance == nullptr)
  {
    instance = new InputManager();
  }
  return instance;
}

void InputManager::Destroy()
{
  if (instance != nullptr)
  {
    delete instance;
    instance = nullptr;
  }
}

void InputManager::Update()
{
  InputManager::GetInstance();
  
  for (int i = 0; i < 256; i++)
  {
    instance->keypress[i] = (GetAsyncKeyState(i) & 0x8001);
  }
}

bool InputManager::GetKey(int keycode)
{
  if (keycode < 0 || keycode >= 256) return false;
  InputManager::GetInstance();
  return instance->keypress[keycode];
}
