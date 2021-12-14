#pragma once
#include "GameObject.h"
class Unit :
    public GameObject
{
public:
  // GameObject을(를) 통해 상속됨
  virtual void Initialize() override;
  virtual void Update() override;

protected:
  float speed;
};

