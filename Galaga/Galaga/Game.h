#pragma once
class Game
{
public:
  Game();
  ~Game();
  void Run();

private:
  bool shutdown = false;
};

