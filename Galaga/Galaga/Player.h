#pragma once
#include "Unit.h"
class Player :
    public Unit
{
public:
  Player();
  virtual ~Player();

  virtual void Update();

  // GameObject��(��) ���� ��ӵ�
  virtual void Initialize() override;


};

