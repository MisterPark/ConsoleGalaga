#pragma once
#include "Shape.h"

class GameObject
{
public:
  GameObject();
  virtual ~GameObject();

  virtual void Initialize() = 0;
  virtual void Update() = 0;
  virtual void Render();

  void Destroy();
  bool DestroyEnabled();
  Vector2& GetPosition();


protected:
  bool destroyFlag = false;
  Vector2 position;
  float speed = 1.f;
public:
  Shape shape;
};

