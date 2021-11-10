#pragma once
class IScene
{
public:
  IScene();
  IScene(const string& sceneName);
  virtual ~IScene();

  virtual void Initialize();
  virtual void Release();
  virtual void Update();

  string& GetName();
  int GetID();

private:
  string name;
  int id;

};

