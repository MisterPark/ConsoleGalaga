#pragma once
#include "Unit.h"
class Player :
    public Unit
{
public:
  Player();
  virtual ~Player();

  virtual void Update();

  // GameObject을(를) 통해 상속됨
  virtual void Initialize() override;


};

