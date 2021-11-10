#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "MainGame.h"

using namespace std;


int main()
{
  _wsetlocale(LC_ALL, L"korean");
  
  MainGame::GetInstance()->Run();
  MainGame::Destroy();

  return 0;
}