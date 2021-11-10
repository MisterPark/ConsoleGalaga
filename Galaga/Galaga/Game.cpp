#include "Game.h"
#include <Windows.h>
#include "InputManager.h"

Game::Game()
{
  InputManager::GetInstance();
}

Game::~Game()
{
  InputManager::Destory();
}

void Game::Run()
{
  for (;!this->shutdown;) // 1������
  {
    if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
    {
      shutdown = true;
    }
    
  }
}
