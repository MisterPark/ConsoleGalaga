#include "stdafx.h"
#include "Player.h"
#include "InputManager.h"
#include "Time.h"

Player::Player()
{
  //shape.data = new WCHAR[1];
  //shape.data[0] = L'¡Ú';
  //shape.width = 1;
  //shape.height = 1;
  shape.LoadShape(L"playerShape.txt");
  speed = 30.f;
}

Player::~Player()
{
}

void Player::Update()
{
  InputManager::GetInstance();
  float dt = Time::DeltaTime();
  Vector2 direction = Vector2::Zero;

  if (InputManager::GetKey(VK_LEFT) && InputManager::GetKey(VK_UP))
  {
    direction = (Vector2::Left + Vector2::Up).Normalized();
  }
  else if (InputManager::GetKey(VK_LEFT) && InputManager::GetKey(VK_DOWN))
  {
    direction = (Vector2::Left + Vector2::Down).Normalized();
  }
  else if (InputManager::GetKey(VK_RIGHT) && InputManager::GetKey(VK_UP))
  {
    direction = (Vector2::Right + Vector2::Up).Normalized();
  }
  else if (InputManager::GetKey(VK_RIGHT) && InputManager::GetKey(VK_DOWN))
  {
    direction = (Vector2::Right + Vector2::Down).Normalized();
  }
  else if (InputManager::GetKey(VK_LEFT))
  {
    direction = Vector2::Left;
  }
  else if (InputManager::GetKey(VK_RIGHT))
  {
    direction = Vector2::Right;
  }
  else if (InputManager::GetKey(VK_UP))
  {
    direction = Vector2::Up;
  }
  else if (InputManager::GetKey(VK_DOWN))
  {
    direction = Vector2::Down;
  }

  if (InputManager::GetKey(VK_SPACE))
  {

  }

  position += direction * speed * dt;
}

void Player::Initialize()
{
}
