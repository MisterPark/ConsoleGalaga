#include "stdafx.h"
#include "Player.h"
#include "InputManager.h"
#include "Time.h"

Player::Player()
{
  shape.data = new WCHAR[1];
  shape.data[0] = L'¡Ú';
  shape.width = 1;
  shape.height = 1;
  speed = 30.f;
}

Player::~Player()
{
}

void Player::Update()
{
  InputManager::GetInstance();
  float dt = Time::DeltaTime();
  if (InputManager::GetKey(VK_LEFT))
  {
    position += Vector2::Left * speed * dt;
  }
  if (InputManager::GetKey(VK_RIGHT))
  {
    position += Vector2::Right * speed * dt;
  }
  if (InputManager::GetKey(VK_UP))
  {
    position += Vector2::Up * speed * dt;
  }
  if (InputManager::GetKey(VK_DOWN))
  {
    position += Vector2::Down * speed * dt;
  }
}

void Player::Initialize()
{
}
