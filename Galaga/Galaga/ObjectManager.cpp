#include "stdafx.h"
#include "ObjectManager.h"

ObjectManager* ObjectManager::instance = nullptr;

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}

ObjectManager* ObjectManager::GetInstance()
{
  if (instance == nullptr)
  {
    instance = new ObjectManager();
  }
  return instance;
}

void ObjectManager::Destroy()
{
  if (instance != nullptr)
  {
    delete instance;
    instance = nullptr;
  }
}

void ObjectManager::Awake()
{
  ObjectManager::GetInstance();

  int numObjects = instance->waitings.size();
  for (int i = 0; i < numObjects; i++)
  {
    instance->waitings[i]->Initialize();
    instance->objects.push_back(instance->waitings[i]);
  }
  instance->waitings.clear();
}

void ObjectManager::Update()
{
  ObjectManager::GetInstance();
  int numObjects = instance->objects.size();
  for (int i = 0; i < numObjects; i++)
  {
    instance->objects[i]->Update();
  }
}

void ObjectManager::Release()
{
  ObjectManager::GetInstance();
  auto begin = instance->objects.begin();
  auto end = instance->objects.end();
  for (auto iter = begin; iter != end;)
  {
    GameObject* obj = *iter;
    if (obj->DestroyEnabled())
    {
      iter = instance->objects.erase(iter);
      delete obj;
    }
    else
    {
      ++iter;
    }
    
  }
}

void ObjectManager::Render()
{
  ObjectManager::GetInstance();
  int numObjects = instance->objects.size();
  for (int i = 0; i < numObjects; i++)
  {
    instance->objects[i]->Render();
  }
}

void ObjectManager::AddObject(GameObject* object)
{
  ObjectManager::GetInstance();
  instance->waitings.push_back(object);
}

vector<GameObject*>& ObjectManager::GetObjects()
{
  return instance->objects;
}
