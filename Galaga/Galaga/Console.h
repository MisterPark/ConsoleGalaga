#pragma once
class Console
{
public:
  static void SetSize(int line, int column);
  static void SetCursorInfo(int cursorSize, bool visible);
  static void SetCursorPosition(int x, int y);
  static void Write(const WCHAR* text);
};

