#pragma once
class Shape
{
public:
  Shape();
  ~Shape();
  
  void LoadShape(const wstring& fileName);

public:
  int width;
  int height;
  WCHAR* data;
};

