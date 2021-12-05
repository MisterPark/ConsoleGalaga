#pragma once
class Camera
{
private:
  Camera();
  ~Camera();
public:
  static Camera* GetInstance();
  static void Destroy();

  static void Update();
  static void Clear();
  static void Render();

  Vector2& GetPosition();
  WCHAR* GetBuffer();
  int GetWidth() { return width; }
  int GetHeight() { return height; }
  void Swapchain();

private:
  Vector2 position;
  WCHAR* buffer = nullptr;
  WCHAR* buffer2 = nullptr;
  WCHAR* currentBuffer = nullptr;
  WCHAR* nextBuffer = nullptr;
  int width;
  int height;
  int bufferCount;
};

