#include "stdafx.h"
#include "Shape.h"
#include <direct.h>

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

void Shape::LoadShape(const wstring& fileName)
{
  WCHAR path[MAX_PATH] = { 0, };
  GetModuleFileNameW(NULL, path, MAX_PATH);
  wstring wpath = path;
  for (int i = MAX_PATH - 1; i >= 0; i--)
  {
    if (path[i] == L'\\')
    {
      wpath = wpath.substr(0, i + 1) + fileName;
      break;
    }
  }

  FILE* fp;
  _wfopen_s(&fp, wpath.c_str(), L"rt");
  if (fp == nullptr)
  {
    return;
  }
  fseek(fp, 0, SEEK_END);
  int len = ftell(fp) - 1;
  fseek(fp, 0, SEEK_SET);

  WCHAR bom = 0;
  fread(&bom, sizeof(WCHAR), 1, fp);
  if (bom != 0xFEFF)
  {
    return;
  }

  int bufCount = len / 2 + 1;
  WCHAR* buf = new WCHAR[bufCount];
  wmemset(buf, 0, bufCount);
  fread(buf, sizeof(WCHAR), bufCount, fp);
  buf[len / 2] = L'\0';

  fclose(fp);

  // parsing
  int col = 0;
  int line = 1;
  for (int i = 0; i < bufCount; i++)
  {
    if (buf[i] == L'\r')
    {
      if (width == 0)
      {
        width = i;
      }
      line++;
    }
  }
  width = width == 0 ? 1 : width;
  height = line;

  data = new WCHAR[width * height];
  int idx = 0;
  for (int i = 0; i < bufCount; i++)
  {
    if (buf[i] == L'\r') continue;
    if (buf[i] == L'\n') continue;
    if (buf[i] == L'\0') continue;
    data[idx] = buf[i];
    idx++;
  }
  
}
