#pragma once
#include "Singleton.h"
class CTimeManager : public Singleton<CTimeManager>
{
public:
	CTimeManager();
	~CTimeManager();

	clock_t g_CurTime;

	clock_t F_CurTime;
	clock_t F_OldTime;

	void FrameLock();
	clock_t GetTime();

	void Init();
	void Update();
	void Release();

};

#define g_TimeManager CTimeManager::GetInstance()

