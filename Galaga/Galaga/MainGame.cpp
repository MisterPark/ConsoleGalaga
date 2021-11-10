#include "stdafx.h"
#include "MainGame.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "SceneManager.h"
#include "Camera.h"
#include "TestScene.h"
#include "Time.h"

MainGame* MainGame::instance = nullptr;

MainGame::MainGame()
{
  Time::GetInstance()->Initialize();
  IScene* scene = new TestScene("TestScene");
  SceneManager::GetInstance()->LoadScene("TestScene");
}

MainGame::~MainGame()
{
}

MainGame* MainGame::GetInstance()
{
  if (instance == nullptr)
  {
    instance = new MainGame();
  }
  return instance;
}

void MainGame::Destroy()
{
  if (instance != nullptr)
  {
    delete instance;
    instance = nullptr;
  }
}

void MainGame::Run()
{
  while (!shutdown)
  {
    InputManager::Update();
    SceneManager::Update();
    
    Camera::Render();
  }
}

void MainGame::Shutdown()
{
  shutdown = true;
}
