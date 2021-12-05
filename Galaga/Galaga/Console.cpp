#include "stdafx.h"
#include "Console.h"


void Console::SetSize(int line, int column)
{
  char buf1[128] = { 0, };
  char buf2[128] = { 0, };
  sprintf_s(buf1, "%d", (column));
  sprintf_s(buf2, "%d", (line));
  string op = "mode con: cols=";
  op += string(buf1);
  op += " lines=";
  op += string(buf2);
  system(op.c_str());
}

void Console::SetCursorInfo(int cursorSize, bool visible)
{
  CONSOLE_CURSOR_INFO cursorInfo = { 0, };
  cursorInfo.dwSize = cursorSize; //Ä¿¼­ ±½±â (1 ~ 100)
  cursorInfo.bVisible = visible; //Ä¿¼­ Visible TRUE(º¸ÀÓ) FALSE(¼û±è)
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void Console::SetCursorPosition(int x, int y)
{
  COORD Cur;
  Cur.X = x;
  Cur.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void Console::Write(const WCHAR* text)
{
  DWORD writtenCount;
  WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE),
    text, lstrlenW(text), &writtenCount, NULL);
}
