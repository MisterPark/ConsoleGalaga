#pragma once
#include "Unit.h"
class Missile :
    public Unit
{
public:
  Missile();
  ~Missile();

  // GameObject을(를) 통해 상속됨
  virtual void Initialize() override;
  virtual void Update() override;

  void SetDirection(const Vector2& direction);

private:
  Vector2 direction;
};

