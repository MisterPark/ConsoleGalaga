#pragma once
#include "Scene.h"

class TestScene :
    public IScene
{
public:
  TestScene(const string& sceneName);
  virtual ~TestScene();
};

