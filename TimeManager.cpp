#include "stdafx.h"
#include "TimeManager.h"


CTimeManager::CTimeManager()
{
	F_CurTime = clock();
	F_OldTime = clock();
	CreateTime(0);	//기본 타임
	
}


CTimeManager::~CTimeManager()
{

}

void CTimeManager::FrameLock()
{
	while (true)
	{
		F_CurTime = clock();

		if (F_CurTime - F_OldTime > 10)
		{
			F_OldTime = F_CurTime;
			break;
		}
	}
}

void CTimeManager::CreateTime(int n)
{
	//clock_t *newTime = new clock_t[2];
	//newTime[OldTime] = clock();
	//newTime[CurTime] = clock();
	//vTime.push_back(newTime);
	vTime[n][OldTime] = clock();
	vTime[n][CurTime] = clock();
}

clock_t *CTimeManager::GetTime(int idx)
{
	return vTime[idx];
}

void CTimeManager::Init(int idx)
{
	vTime[idx][OldTime] = vTime[idx][CurTime];
}

void CTimeManager::Update(int idx)
{
	vTime[idx][CurTime] = clock();
}

void CTimeManager::Release(int idx)
{
}



