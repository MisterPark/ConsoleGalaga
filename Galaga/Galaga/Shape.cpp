#include "stdafx.h"
#include "Shape.h"

Shape::Shape()
{
  width = 0;
  height = 0;
  data = nullptr;
}

Shape::~Shape()
{
  if (data)
  {
    delete[] data;
    data = nullptr;
  }
}

void Shape::LoadShape(const string& fileName)
{
}
