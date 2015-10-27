#include "stdafx.h"

#include "Director.h"

void CDirector::Init()
{
	//cout << "Director Init()" << endl;
	
	srand((unsigned int)time(NULL));
	GameDone = false;

	g_TextManager->Init();
	g_SoundManager->Init();
	g_SceneManager->Init();
	g_EventManager->Init();
	g_DrawManager->Init();
	//g_TimeManager->Init();
	
}


void CDirector::Update()
{
	//cout << "Director Update()" << endl;
	g_EventManager->Update();
	g_SceneManager->Update();
	g_TextManager->Update();
	g_SoundManager->Update();
	g_DrawManager->Update();
}


void CDirector::Render()
{
	//cout << "Director Render()" << endl;
	g_SceneManager->Render();
	g_TextManager->Render();
	g_DrawManager->Render();
	
}


void CDirector::Release()
{
	//cout << "Director Release()" << endl;
	g_DrawManager->Release();
	g_EventManager->Release();
	g_SoundManager->Release();
	g_SceneManager->Release();
	g_TextManager->Release();

	//g_DrawManager->Destroy();
	//g_EventManager->Destroy();
	//g_SoundManager->Destroy();
	//g_SceneManager->Destroy();
	//g_TimeManager->Destroy();
	//g_TextManager->Destroy();

	SDL_Quit();
}

void CDirector::GameLoop()
{
	while (!GameDone)
	{
		Update();
		Render();
		g_TimeManager->FrameLock();
	}
}


