#include "stdafx.h"
#include "SceneManager.h"

SceneManager* SceneManager::instance = nullptr;

SceneManager::SceneManager()
{
  currentScene = nullptr;
  nextScene = nullptr;
}

SceneManager::~SceneManager()
{
  auto iter = scenes.begin();
  auto end = scenes.end();
  for (; iter != end;)
  {
    IScene* scene = (*iter);
    iter = scenes.erase(iter);
    delete scene;
  }
  sceneMap.clear();
  currentScene = nullptr;
  nextScene = nullptr;
}

SceneManager* SceneManager::GetInstance()
{
  if (instance == nullptr)
  {
    instance = new SceneManager();
  }
  return instance;
}

void SceneManager::Destroy()
{
  if (instance != nullptr)
  {
    delete instance;
    instance = nullptr;
  }
}

void SceneManager::Update()
{
  SceneManager::GetInstance();
  IScene* scene;
  if (instance->nextScene != nullptr)
  {
    if (instance->nextScene != instance->currentScene)
    {
      if (instance->currentScene != nullptr)
      {
        instance->currentScene->Release();
      }
      instance->currentScene = instance->nextScene;
      instance->currentScene->Initialize();
    }
  }

  if (instance->currentScene != nullptr)
  {
    instance->currentScene->Update();
  }
}

void SceneManager::LoadScene(const string& sceneName)
{
  SceneManager::GetInstance();
  auto find = instance->sceneMap.find(sceneName);
  if (find != instance->sceneMap.end())
  {
    instance->nextScene = find->second;
  }
}

void SceneManager::LoadScene(int sceneNum)
{
  SceneManager::GetInstance();
  instance->nextScene = instance->scenes[sceneNum];
}

void SceneManager::Register(IScene* scene)
{
  SceneManager::GetInstance();
  instance->sceneMap[scene->GetName()] = scene;
  instance->scenes.push_back(scene);
}

void SceneManager::Deregister(IScene* scene)
{
  SceneManager::GetInstance();
  auto find = instance->sceneMap.find(scene->GetName());
  if (find != instance->sceneMap.end())
  {
    instance->sceneMap.erase(find);
  }
  auto iter = instance->scenes.begin();
  auto end = instance->scenes.end();
  for (; iter != end;)
  {
    if ((*iter) == scene)
    {
      iter = instance->scenes.erase(iter);
      break;
    }
    else
    {
      ++iter;
    }
  }
}
