#pragma once
#include "GameObject.h"
class Unit :
    public GameObject
{
public:
  // GameObject��(��) ���� ��ӵ�
  virtual void Initialize() override;
  virtual void Update() override;

protected:
  float speed;
};

