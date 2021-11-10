#pragma once
#include <iostream>
#include <vector>
#include "GameObject.h"
using namespace std;

class ObjectManager
{
private:
  ObjectManager();
  ~ObjectManager();
public:
  static ObjectManager* GetInstance();
  static void Destroy();

  static void Awake();
  static void Update();
  static void Release();
  static void Render();

  static void AddObject(GameObject* object);

  static vector<GameObject*>& GetObjects();

private:
  vector<GameObject*> waitings;
  vector<GameObject*> objects;
  static ObjectManager* instance;
};

