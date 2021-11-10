#pragma once
class Time
{
private:
	Time();
	~Time();

public:
	static Time* GetInstance();
	static void Destroy();

	static void Initialize();
	static void Release();

	static bool SkipFrame();

	static int GetFPS();
	static void SetFPS(int _fps);

	static float DeltaTime();

	// ����׿�
	static void RenderFPS();

private:
	LARGE_INTEGER frequency;
	int fps = 50;

	bool isUsedQueryPerformance = false;
	__int64 cpuTick = 0;

	__int64 oldTime = 0;
	__int64 elapseSum = 0;
	float deltaTime = 0.f;
	int frameCount = 0;
	int targetFrame = 0;
	int timeStack = 0; // �����Ӵ� �ʰ� �̸� �ð� ����

	int renderCount = 0;

};
