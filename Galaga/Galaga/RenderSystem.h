#pragma once
class RenderSystem
{
private:
  RenderSystem();
  ~RenderSystem();
public:
  static RenderSystem* GetInstance();
  static void Destroy();
  
  static void Render();

};

