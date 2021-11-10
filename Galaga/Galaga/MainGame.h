#pragma once
class MainGame
{
private:
  MainGame();
  ~MainGame();
public:
  static MainGame* GetInstance();
  static void Destroy();

  void Run();
  void Shutdown();
private:
  bool shutdown = false;
  static MainGame* instance;
};

