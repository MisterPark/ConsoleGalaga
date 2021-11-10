#pragma once
#include "GameObject.h"
class Player :
    public GameObject
{
public:
  Player();
  virtual ~Player();

  virtual void Update();

  // GameObject을(를) 통해 상속됨
  virtual void Initialize() override;
};

