#include "stdafx.h"
#include "TimeManager.h"


CTimeManager::CTimeManager()
{
	F_CurTime = clock();
	F_OldTime = clock();
	
	
}


CTimeManager::~CTimeManager()
{

}

void CTimeManager::FrameLock()
{
	while (true)
	{
		F_CurTime = clock();

		if (F_CurTime - F_OldTime > 20)
		{
			F_OldTime = F_CurTime;
			break;
		}
	}
}


clock_t CTimeManager::GetTime()
{
	return g_CurTime;
}

void CTimeManager::Init()
{
	g_CurTime = clock();
}

void CTimeManager::Update()
{
	g_CurTime = clock();
}

void CTimeManager::Release()
{
}



