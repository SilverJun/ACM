// Avoid_Color_Music.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Director.h"

#undef main

int main(int argc, char* argv[])
{
	g_Director->Init();
	
	while (!g_Director->GameDone)
	{
		g_Director->Update();
		g_Director->Render();
		g_TimeManager->FrameLock();
	}

	g_Director->Release();

	return 0;
}

