#pragma once
#include "GameObject.h"
class Missile :
    public GameObject
{
  // GameObject��(��) ���� ��ӵ�
  virtual void Initialize() override;
  virtual void Update() override;
};

