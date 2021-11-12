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
  FILE* fp = nullptr;
  WCHAR* buffer;
  WCHAR path[MAX_PATH] = { 0, };
  GetModuleFileNameW(NULL, path, MAX_PATH);
  wstring wpath = path;
  for (int i = wpath.size() - 1; i > 0; i--)
  {
    if (wpath[i] == L'\\')
    {
      wpath = wpath.substr(0, i + 1);
      break;
    }
  }

  wpath += fileName;
  _wfopen_s(&fp, wpath.c_str(), L"rt");
  if (fp == nullptr)
  {
    throw "경로에 파일이 없음.";
    return;
  }
  fseek(fp, 0, SEEK_END);
  int numBytes = ftell(fp) - 1;
  fseek(fp, 0, SEEK_SET);
  int bufferCount = numBytes / 2 + 1;
  buffer = new WCHAR[bufferCount];
  wmemset(buffer, 0, bufferCount);
  fread(buffer, sizeof(WCHAR), 1, fp);
  WCHAR bom = buffer[0];
  if (bom != 0xFEFF)
  {
    return;
  }
  fread(buffer, sizeof(WCHAR), bufferCount, fp);
  buffer[numBytes / 2] = L'\0';

  // parsing
  int lineCount = 1;
  for (int i = 0; i < bufferCount; i++ )
  {
    if (buffer[i] == L'\n')
    {
      lineCount++;
      if (width != 0)
      {
        width = i;
      }
    }
  }

  data = new WCHAR[width * height];
  for (int i = 0; i < bufferCount; i++)
  {
    if (buffer[i] == L'\n' || buffer[i] == L'\0')
    {
      continue;
    }
  }
  
}
