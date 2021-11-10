#pragma once
class InputManager
{
private:
  InputManager();
  ~InputManager();
public:
  static InputManager* GetInstance();
  static void Destroy();

  static void Update();

  static bool GetKey(int keycode);

private:
  bool keypress[256];
  static InputManager* instance;
};

