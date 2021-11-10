#include "stdafx.h"
#include "Time.h"

Time* pTime = nullptr;

Time::Time()
{
}

Time::~Time()
{
}

Time* Time::GetInstance()
{
  if (pTime == nullptr)
  {
    pTime = new Time;
    Initialize();
  }
  return pTime;
}

void Time::Destroy()
{
  if (pTime)
  {
    delete pTime;
    pTime = nullptr;
  }
}

void Time::Initialize()
{
  if (QueryPerformanceFrequency(&pTime->frequency))
  {
    pTime->isUsedQueryPerformance = true;
    pTime->cpuTick = pTime->frequency.QuadPart / 1000;
  }
}

void Time::Release()
{
}

bool Time::SkipFrame()
{
  LARGE_INTEGER time;
  __int64 curTime;
  __int64 elapsed; // 1������ ����ð�(ms)

  QueryPerformanceCounter(&time);
  curTime = time.QuadPart;

  if (pTime->oldTime == 0)
  {
    pTime->oldTime = curTime;
    return false;
  }

  // �����Ӵ� �ɸ� �ð� (����ũ�μ���) -> �и�����
  elapsed = (curTime - pTime->oldTime) / pTime->cpuTick;

  pTime->elapseSum += elapsed;
  // �õ�Ÿ�� ����
  pTime->oldTime = curTime;
  // ��ŸŸ�� ���� (�ʴ���)
  pTime->deltaTime = float(elapsed) / 1000;
  //������ ī��Ʈ
  pTime->frameCount++;

  if (pTime->elapseSum >= 1000) // 1�� �����
  {
    WCHAR str[64] = {};
    wsprintfW(str, L"FPS : %d / Render : %d", pTime->frameCount, pTime->renderCount);
    SetConsoleTitleW(str);
    //UpdateWindow(g_hwnd);

    pTime->fps = pTime->frameCount;
    pTime->frameCount = 0;
    pTime->elapseSum = 0;
    pTime->renderCount = 0;
  }

  // �����Ӵ� �ʰ�/�̸� �ð� ����
  //pTime->timeStack += (int)(elapsed - pTime->targetFrame);

  //if (pTime->timeStack >= pTime->targetFrame) // ������
  //{
  //    pTime->timeStack -= pTime->targetFrame;
  //    return true;
  //}
  //else // ������
  //{
  //    //Sleep(abs(pTime->timeStack));
  //}

  pTime->renderCount++;
  return false;
}

int Time::GetFPS()
{
  return pTime->fps;
}

void Time::SetFPS(int _fps)
{
  pTime->fps = _fps;
  pTime->targetFrame = (int)(1000.f / _fps);
}

float Time::DeltaTime()
{
  return pTime->deltaTime;
}

void Time::RenderFPS()
{
}
