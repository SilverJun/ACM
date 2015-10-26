// Avoid_Color_Music.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

