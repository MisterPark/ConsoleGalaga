#pragma once
#include "GameObject.h"
class Player :
    public GameObject
{
public:
  Player();
  virtual ~Player();

  virtual void Update();

  // GameObject��(��) ���� ��ӵ�
  virtual void Initialize() override;
};

