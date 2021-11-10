#include "stdafx.h"
#include "TestScene.h"
#include "Player.h"

TestScene::TestScene(const string& sceneName)
  :IScene(sceneName)
{
  new Player();
}

TestScene::~TestScene()
{
}
