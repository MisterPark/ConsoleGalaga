#pragma once
#include "GameObject.h"
class Unit :
    public GameObject
{
  // GameObject��(��) ���� ��ӵ�
  virtual void Initialize() override;
  virtual void Update() override;
};

