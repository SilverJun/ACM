#pragma once
#include "Singleton.h"
class CTimeManager : public Singleton<CTimeManager>
{
public:
	CTimeManager();
	~CTimeManager();

	clock_t vTime[6][2];
	//clock_t CurTime;
	//clock_t OldTime;
	clock_t F_CurTime;
	clock_t F_OldTime;

	void FrameLock();
	void CreateTime(int n);
	clock_t *GetTime(int idx);

	void Init();
	void Init(int idx);
	void Update(int idx);
	void Release(int idx);

};

#define g_TimeManager CTimeManager::GetInstance()
#define CurTime 1
#define OldTime 2


