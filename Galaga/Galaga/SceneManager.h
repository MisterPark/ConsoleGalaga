#pragma once
#include "Scene.h"

class SceneManager
{
private:
  SceneManager();
  ~SceneManager();
public:
  static SceneManager* GetInstance();
  static void Destroy();

  static void Update();

  static void LoadScene(const string& sceneName);
  static void LoadScene(int sceneNum);

  static void Register(IScene* scene);
  static void Deregister(IScene* scene);

private:
  IScene* currentScene;
  IScene* nextScene;
  map<string, IScene*> sceneMap;
  vector<IScene*> scenes;
  static SceneManager* instance;
};

