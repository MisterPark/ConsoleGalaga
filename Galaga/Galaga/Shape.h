#pragma once
class Shape
{
public:
  Shape();
  ~Shape();
  
  void LoadShape(const string& fileName);

public:
  int width;
  int height;
  WCHAR* data;
};

