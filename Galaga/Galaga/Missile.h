#pragma once
#include "Unit.h"
class Missile :
    public Unit
{
public:
  Missile();
  ~Missile();

  // GameObject��(��) ���� ��ӵ�
  virtual void Initialize() override;
  virtual void Update() override;

  void SetDirection(const Vector2& direction);

private:
  Vector2 direction;
};

