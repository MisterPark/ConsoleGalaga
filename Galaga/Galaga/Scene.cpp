#include "stdafx.h"
#include "Scene.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "Camera.h"
#include "Time.h"
int uniqueID = 0;

IScene::IScene()
{
  Time::GetInstance();
}

IScene::IScene(const string& sceneName)
{
  name = sceneName;
  id = uniqueID;
  uniqueID++;
  SceneManager::Register(this);
}

IScene::~IScene()
{
}

void IScene::Initialize()
{

}

void IScene::Release()
{
}

void IScene::Update()
{
  ObjectManager::GetInstance()->Awake();
  ObjectManager::GetInstance()->Update();
  Camera::Update();
  Camera::GetInstance()->Clear();
  ObjectManager::GetInstance()->Render();
  Time::GetInstance()->SkipFrame();
}

string& IScene::GetName()
{
  return name;
}

int IScene::GetID()
{
  return id;
}
