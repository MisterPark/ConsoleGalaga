#include "stdafx.h"
#include "Missile.h"
#include "Camera.h"

Missile::Missile()
{
  speed = 2.f;
  shape.LoadShape(L"missile.txt");
}

Missile::~Missile()
{
}

void Missile::Initialize()
{
}

void Missile::Update()
{
  float dt = Time::DeltaTime();
  float w = Camera::GetInstance()->GetWidth();
  float h = Camera::GetInstance()->GetHeight();
  position += direction * speed;// *dt;

  if (Camera::GetInstance()->IsOutOfRange(this))
  {
    Destroy();
  }
}

void Missile::SetDirection(const Vector2& direction)
{
  this->direction = direction.Normalized();
}
